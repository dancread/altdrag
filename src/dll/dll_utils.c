/*
 * dll_utils.c
 *
 */
#include <windows.h>
#include <psapi.h>
#include <shlwapi.h>
#include "../include/dll_globals.h"
#include "../include/dll_utils.h"

// Blacklist
int blacklisted(HWND hwnd, struct blacklist *list) {
  wchar_t title[256]=L"", classname[256]=L"";
  int i;

  // Do not check if list is empty
  if (list->length == 0) {
    return 0;
  }

  // ProcessBlacklist is case-insensitive
  if (list == &settings.ProcessBlacklist) {
    DWORD pid;
    GetWindowThreadProcessId(hwnd, &pid);
    HANDLE proc = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
    GetProcessImageFileName(proc, title, ARRAY_SIZE(title));
    CloseHandle(proc);
    PathStripPath(title);
    for (i=0; i < list->length; i++) {
      if (!wcsicmp(title,list->items[i].title)) {
        return 1;
      }
    }
    return 0;
  }

  GetWindowText(hwnd, title, ARRAY_SIZE(title));
  GetClassName(hwnd, classname, ARRAY_SIZE(classname));
  for (i=0; i < list->length; i++) {
    if ((list->items[i].title == NULL && !wcscmp(classname,list->items[i].classname))
     || (list->items[i].classname == NULL && !wcscmp(title,list->items[i].title))
     || (list->items[i].title != NULL && list->items[i].classname != NULL && !wcscmp(title,list->items[i].title) && !wcscmp(classname,list->items[i].classname))) {
      return 1;
    }
  }
  return 0;
}
