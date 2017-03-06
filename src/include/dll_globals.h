/*
 * dll_globals.h
 *
 */

#ifndef SRC_INCLUDE_DLL_GLOBALS_C_
#define SRC_INCLUDE_DLL_GLOBALS_C_

// Definitions
#define APP_NAME            L"AltDrag"
#define APP_VERSION         L"1.1"
#define APP_URL             L"https://stefansundin.github.io/altdrag/"
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
// Enumerators
enum action {ACTION_NONE=0, ACTION_MOVE, ACTION_RESIZE, ACTION_MINIMIZE, ACTION_CENTER, ACTION_ALWAYSONTOP, ACTION_CLOSE, ACTION_LOWER, ACTION_ALTTAB, ACTION_VOLUME, ACTION_TRANSPARENCY};
enum button {BUTTON_NONE=0, BUTTON_LMB, BUTTON_MMB, BUTTON_RMB, BUTTON_MB4, BUTTON_MB5};
enum resize {RESIZE_NONE=0, RESIZE_TOP, RESIZE_RIGHT, RESIZE_BOTTOM, RESIZE_LEFT, RESIZE_CENTER};
enum cursor {HAND, SIZENWSE, SIZENESW, SIZENS, SIZEWE, SIZEALL};

/* Structs */
// Some variables must be shared so that CallWndProc hooks can access them
#define shareattr __attribute__((section ("shared"), shared))

// Window database
#define NUMWNDDB 30
struct wnddata {
  HWND hwnd;
  short restore;
  int width;
  int height;
  struct {
    int width;
    int height;
  } last;
};
struct {
  struct wnddata items[NUMWNDDB];
  struct wnddata *pos;
} wnddb;

// State
struct {
  HWND hwnd;
  HWND mdiclient;
  short alt;
  short activated; // Keep track on if an action has begun since the hotkey was depressed, in order to successfully block Alt from triggering a menu
  short ctrl;
  short interrupted;
  short updaterate;
  unsigned int clicktime;
  POINT clickpt;
  POINT prevpt;
  POINT offset;
  struct {
    enum resize x, y;
  } resize;
  short blockaltup;
  short blockmouseup;
  short ignorectrl;
  short locked;
  struct wnddata *wndentry;
  struct {
    HMONITOR monitor;
    short maximized;
    int width;
    int height;
    int right;
    int bottom;
  } origin;
  struct {
    POINT ptMinTrackSize;
    POINT ptMaxTrackSize;
  } mmi;
} state;

struct {
  short shift;
  short snap;
  enum action action;
} sharedstate shareattr = {0, 0, ACTION_NONE};

// Settings
#define MAXKEYS 10
struct {
  int AutoFocus;
  int AutoSnap;
  int AutoRemaximize;
  int Aero;
  int MDI;
  int InactiveScroll;
  int LowerWithMMB;
  int SnapThreshold;
  int FocusOnTyping;
  struct {
    int Cursor;
    int MoveRate;
    int ResizeRate;
  } Performance;
  struct {
    unsigned char keys[MAXKEYS];
    int length;
  } Hotkeys;
  struct {
    enum action LMB, MMB, RMB, MB4, MB5, Scroll;
  } Mouse;
} sharedsettings shareattr;

// Blacklist (not shared since dynamically allocated)
struct blacklistitem {
  wchar_t *title;
  wchar_t *classname;
};

struct blacklist {
  struct blacklistitem *items;
  int length;
  wchar_t *data;
};
struct {
  struct blacklist ProcessBlacklist;
  struct blacklist Blacklist;
  struct blacklist Snaplist;
} settings = {{NULL,0}, {NULL,0}, {NULL,0}};
/* Global externs */
extern HWND g_hwnd;
extern short sharedsettings_loaded shareattr;
extern wchar_t inipath[MAX_PATH] shareattr;

// Cursor data
extern HWND cursorwnd shareattr;
extern HCURSOR cursors[6];

// Hook data
extern HINSTANCE hinstDLL;
extern HHOOK mousehook;

// Msghook data
extern BOOL subclassed;
extern enum action msgaction shareattr;
extern short unload shareattr;

extern int numwnds;
// Enumerate
extern int monitors_alloc;
extern int wnds_alloc;
extern int hwnds_alloc;

extern int nummonitors;
// Snap
extern RECT *monitors;
extern RECT *wnds;

extern HWND *hwnds;
extern int numhwnds;
extern HWND progman;

#endif /* SRC_INCLUDE_DLL_GLOBALS_C_ */
