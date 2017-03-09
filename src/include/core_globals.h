/*
 * core_globals.h
 *
 *  Created on: Feb 26, 2017
 *      Author: Daniel
 */

#ifndef SRC_INCLUDE_CORE_GLOBALS_H_
#define SRC_INCLUDE_CORE_GLOBALS_H_
#include <windows.h>
#include "../../localization/strings.h"
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
// Utils
#define ENABLED() (keyhook || msghook)
// Globals
extern int tray_added;
extern int hide;
extern NOTIFYICONDATA tray;
extern HICON icon[2];
extern int update;
extern HINSTANCE g_hinst;
extern HWND g_hwnd;
extern UINT WM_TASKBARCREATED;
extern UINT WM_UPDATESETTINGS;
extern UINT WM_ADDTRAY;
extern UINT WM_HIDETRAY;
extern UINT WM_OPENCONFIG;
extern UINT WM_CLOSECONFIG;
extern wchar_t inipath[MAX_PATH];

extern HWND g_cfgwnd;
// Cool stuff
extern HINSTANCE hinstDLL;
extern HHOOK keyhook;
extern HHOOK msghook;
extern BOOL x64;
extern int vista;
extern int elevated;
// Lang
extern struct strings *languages[1]; //FIXME: Terrible idea
extern struct strings *l10n;
extern struct strings en_US;
extern struct l10n_mapping_t l10n_mapping[92];  //FIXME: Terrible idea

#endif /* SRC_INCLUDE_CORE_GLOBALS_H_ */
