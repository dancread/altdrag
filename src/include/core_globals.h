/*
 * core_globals.h
 *
 *  Created on: Feb 26, 2017
 *      Author: Daniel
 */

#ifndef SRC_INCLUDE_CORE_GLOBALS_H_
#define SRC_INCLUDE_CORE_GLOBALS_H_
#include <windows.h>
// Definitions
#define APP_NAME            L"AltDrag"
#define APP_VERSION         L"1.1"
#define APP_URL             L"https://stefansundin.github.io/altdrag/"
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
// Messages
#define WM_TRAY                WM_USER+1
#define SWM_TOGGLE             WM_APP+1
#define SWM_HIDE               WM_APP+2
#define SWM_UPDATE             WM_APP+3
#define SWM_CONFIG             WM_APP+4
#define SWM_ABOUT              WM_APP+5
#define SWM_EXIT               WM_APP+6
// Globals
int tray_added = 0;
int hide = 0;
NOTIFYICONDATA tray;
HICON icon[2];
extern int update;
HINSTANCE g_hinst = NULL;
HWND g_hwnd = NULL;
UINT WM_TASKBARCREATED = 0;
UINT WM_UPDATESETTINGS = 0;
UINT WM_ADDTRAY = 0;
UINT WM_HIDETRAY = 0;
UINT WM_OPENCONFIG = 0;
UINT WM_CLOSECONFIG = 0;
wchar_t inipath[MAX_PATH];

HWND g_cfgwnd = NULL;
// Cool stuff
HINSTANCE hinstDLL = NULL;
HHOOK keyhook = NULL;
HHOOK msghook = NULL;
BOOL x64 = FALSE;
int vista = 0;
int elevated = 0;

#endif /* SRC_INCLUDE_CORE_GLOBALS_H_ */
