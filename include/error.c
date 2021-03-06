/*
  Copyright (C) 2015  Stefan Sundin

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
*/

int showerror = 1;


#if defined(DEBUG) || defined(ERROR_WRITETOFILE)

#include <shlobj.h>
wchar_t log_filename[1000] = L"";

FILE *OpenLog(wchar_t *mode) {
  //return stdout;
  // Put the file on the desktop (since we should always be able to write there)
  if (log_filename[0] == '\0') {
    SHGetFolderPath(NULL, CSIDL_DESKTOP, NULL, SHGFP_TYPE_CURRENT, log_filename);
    wcscat(log_filename, L"\\"APP_NAME"-log.txt");
  }
  FILE *f = _wfopen(log_filename, mode);
  if (f == NULL) {
    // If it fails to open the file, it should print to the terminal (recompile with -mconsole)
    return stdout;
  }
  return f;
}

void CloseLog(FILE *f) {
  if (f != stdout) {
    fclose(f);
  }
}

#endif


LRESULT CALLBACK ErrorMsgProc(INT nCode, WPARAM wParam, LPARAM lParam) {
  if (nCode == HCBT_ACTIVATE) {
    // Edit the caption of the buttons
    SetDlgItemText((HWND)wParam, IDYES, L"Copy error");
    SetDlgItemText((HWND)wParam, IDNO,  L"OK");
  }
  return 0;
}

void _Error(wchar_t *func, wchar_t *info, int errorcode, wchar_t *file, int line) {
  if (!showerror) {
    return;
  }
  // Format message
  wchar_t msg[1000], *errormsg;
  int length = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM, NULL, errorcode, 0, (wchar_t*)&errormsg, 0, NULL);
  if (length != 0) {
    errormsg[length-2] = '\0'; // Remove that damn newline at the end of the formatted error message
  }
  swprintf(msg, ARRAY_SIZE(msg), L"%s failed in file %s, line %d.\nError: %s (%d)\n\n%s", func, file, line, errormsg, errorcode, info);
  LocalFree(errormsg);
  // Display message
  #ifdef ERROR_WRITETOFILE
  FILE *f = OpenLog(L"ab");
  fputws(msg, f);
  fputws(L"\n\n", f);
  CloseLog(f);
  #else
  // Tip: You can also press Ctrl+C in a MessageBox window to copy the text
  HHOOK hhk = SetWindowsHookEx(WH_CBT, &ErrorMsgProc, 0, GetCurrentThreadId());
  int response = MessageBox(NULL, msg, APP_NAME" Error", MB_ICONERROR|MB_YESNO|MB_DEFBUTTON2);
  UnhookWindowsHookEx(hhk);
  if (response == IDYES) {
    // Copy message to clipboard
    int size = (wcslen(msg)+1)*sizeof(msg[0]);
    wchar_t *data = LocalAlloc(LMEM_FIXED, size);
    memcpy(data, msg, size);
    OpenClipboard(NULL);
    EmptyClipboard();
    SetClipboardData(CF_UNICODETEXT, data);
    CloseClipboard();
    LocalFree(data);
  }
  #endif
}

#define Error(a,b,c) _Error(a, b, c, TEXT(__FILE__), __LINE__)

//DBG("%d", 5);
//DBGA("%d", 5);

#ifdef ERROR_WRITETOFILE

#define DBG(fmt, ...) { \
  FILE *f = OpenLog(L"ab"); \
  fwprintf(f, TEXT(fmt), ##__VA_ARGS__); \
  fputws(L"\n\n", f); \
  CloseLog(f); \
}

#else

#define DBG(fmt, ...) { \
  wchar_t _txt[1000]; \
  wsprintf(_txt, TEXT(fmt), ##__VA_ARGS__); \
  MessageBox(NULL, _txt, APP_NAME" Debug", MB_ICONINFORMATION|MB_OK); \
}

#define DBGA(fmt, ...) { \
  char _txt[1000]; \
  sprintf(_txt, fmt, ##__VA_ARGS__); \
  MessageBoxA(NULL, _txt, "Debug", MB_ICONINFORMATION|MB_OK); \
}

#endif
