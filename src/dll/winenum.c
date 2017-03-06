
#include <windows.h>
#include <stdlib.h>
#include "../include/dll_utils.h"
#include "../include/dll_globals.h"
#include "../include/winenum.h"

void Enum() {
  nummonitors = 0;
  numwnds = 0;

  // MDI
  if (state.mdiclient) {
    EnumMdi();
    return;
  }

  // Update handle to progman
  if (!IsWindow(progman)) {
    progman = FindWindow(L"Progman", L"Program Manager");
  }

  // Enumerate monitors
  EnumDisplayMonitors(NULL, NULL, EnumMonitorsProc, 0);

  // Enumerate windows
  HWND taskbar = FindWindow(L"Shell_TrayWnd", NULL);
  RECT wnd;
  if (taskbar != NULL && GetWindowRect(taskbar,&wnd) != 0) {
    wnds[numwnds++] = wnd;
  }
  if (sharedstate.snap >= 2) {
    EnumWindows(EnumWindowsProc, 0);
  }

  // Use this to print the monitors and windows
  /*
  FILE *f = OpenLog(L"ab");
  fwprintf(f, L"nummonitors: %d\n", nummonitors);
  int k;
  for (k=0; k < nummonitors; k++) {
    fwprintf(f, L"mon #%02d: left %d, top %d, right %d, bottom %d\n", k, monitors[k].left, monitors[k].top, monitors[k].right, monitors[k].bottom);
  }
  fwprintf(f, L"numwnds: %d\n", numwnds);
  for (k=0; k < numwnds; k++) {
    fwprintf(f, L"wnd #%02d: %dx%d @ %dx%d\n", k, wnds[k].right-wnds[k].left, wnds[k].bottom-wnds[k].top, wnds[k].left, wnds[k].top);
  }
  fwprintf(f, L"\n");
  CloseLog(f);
  */
}
BOOL CALLBACK EnumMonitorsProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData) {
  // Make sure we have enough space allocated
  if (nummonitors == monitors_alloc) {
    monitors_alloc++;
    monitors = realloc(monitors, monitors_alloc*sizeof(RECT));
  }
  // Add monitor
  monitors[nummonitors++] = *lprcMonitor;
  return TRUE;
}
BOOL CALLBACK EnumAltTabWindows(HWND window, LPARAM lParam) {
  // Make sure we have enough space allocated
  if (numhwnds == hwnds_alloc) {
    hwnds_alloc += 20;
    hwnds = realloc(hwnds, hwnds_alloc*sizeof(HWND));
  }

  // Only store window if it's visible, not minimized to taskbar and on the same monitor as the cursor
  if (IsWindowVisible(window) && !IsIconic(window)
   && (GetWindowLongPtr(window,GWL_STYLE)&WS_CAPTION) == WS_CAPTION
   && state.origin.monitor == MonitorFromWindow(window,MONITOR_DEFAULTTONULL)
  ) {
    hwnds[numhwnds++] = window;
  }
  return TRUE;
}

BOOL CALLBACK EnumWindowsProc(HWND window, LPARAM lParam) {
  // Make sure we have enough space allocated
  if (numwnds == wnds_alloc) {
    wnds_alloc += 20;
    wnds = realloc(wnds, wnds_alloc*sizeof(RECT));
  }

  // Only store window if it's visible, not minimized to taskbar, not the window we are dragging and not blacklisted
  RECT wnd;
  LONG_PTR style;
  if (window != state.hwnd && window != progman
   && IsWindowVisible(window) && !IsIconic(window)
   && (((style=GetWindowLongPtr(window,GWL_STYLE))&WS_CAPTION) == WS_CAPTION || blacklisted(window,&settings.Snaplist))
   && GetWindowRect(window,&wnd) != 0
  ) {
    // Maximized?
    if (IsZoomed(window)) {
      // Get monitor size
      HMONITOR monitor = MonitorFromWindow(window, MONITOR_DEFAULTTONEAREST);
      MONITORINFO mi = { sizeof(MONITORINFO) };
      GetMonitorInfo(monitor, &mi);
      // Crop this window so that it does not exceed the size of the monitor
      // This is done because when maximized, windows have an extra, invisible, border (a border that stretches onto other monitors)
      wnd.left = max(wnd.left, mi.rcMonitor.left);
      wnd.top = max(wnd.top, mi.rcMonitor.top);
      wnd.right = min(wnd.right, mi.rcMonitor.right);
      wnd.bottom = min(wnd.bottom, mi.rcMonitor.bottom);
    }

    // Return if this window is overlapped by another window
    int i;
    for (i=0; i < numwnds; i++) {
      if (wnd.left >= wnds[i].left && wnd.top >= wnds[i].top && wnd.right <= wnds[i].right && wnd.bottom <= wnds[i].bottom) {
        return TRUE;
      }
    }

    // Add window
    wnds[numwnds++] = wnd;

    // Use this to print the title and classname of the windows that are snapable
    /*
    FILE *f = OpenLog(L"ab");
    wchar_t title[100], classname[100];
    GetWindowText(window, title, ARRAY_SIZE(title));
    GetClassName(window, classname, ARRAY_SIZE(classname));
    fwprintf(f, L"window: %s|%s\n", title, classname);
    CloseLog(f);
    */
  }
  return TRUE;
}
void EnumMdi() {
  // Add MDIClient as the monitor
  RECT wnd;
  if (GetClientRect(state.mdiclient,&wnd) != 0) {
    monitors[nummonitors++] = wnd;
  }
  if (sharedstate.snap < 2) {
    return;
  }

  // Add all the siblings to the window
  POINT mdiclientpt = {0,0};
  if (ClientToScreen(state.mdiclient,&mdiclientpt) == FALSE) {
    return;
  }
  HWND window = GetWindow(state.mdiclient, GW_CHILD);
  while (window != NULL) {
    if (window == state.hwnd) {
      window = GetWindow(window, GW_HWNDNEXT);
      continue;
    }
    if (numwnds == wnds_alloc) {
      wnds_alloc += 20;
      wnds = realloc(wnds, wnds_alloc*sizeof(RECT));
    }
    if (GetWindowRect(window,&wnd) != 0) {
      wnds[numwnds++] = (RECT) { wnd.left-mdiclientpt.x, wnd.top-mdiclientpt.y, wnd.right-mdiclientpt.x, wnd.bottom-mdiclientpt.y };
    }
    window = GetWindow(window, GW_HWNDNEXT);
  }
}
