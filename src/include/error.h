/*
 * error.h
 *
 *  Created on: Feb 26, 2017
 *      Author: Daniel
 */

#ifndef SRC_INCLUDE_ERROR_H_
#define SRC_INCLUDE_ERROR_H_
#include <windows.h>
#include <stdio.h>

int showerror;

#define Error(a,b,c) _Error(a, b, c, TEXT(__FILE__), __LINE__)

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
// Prototypes
FILE *OpenLog(wchar_t *mode);
LRESULT CALLBACK ErrorMsgProc(INT nCode, WPARAM wParam, LPARAM lParam);
void _Error(wchar_t *func, wchar_t *info, int errorcode, wchar_t *file, int line);
#endif /* SRC_INCLUDE_ERROR_H_ */
