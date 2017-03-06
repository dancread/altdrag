/*
 * winenum.h
 *
 */

#ifndef SRC_INCLUDE_WINENUM_H_
#define SRC_INCLUDE_WINENUM_H_
void EnumMdi();
void Enum();
BOOL CALLBACK EnumMonitorsProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData);
BOOL CALLBACK EnumAltTabWindows(HWND window, LPARAM lParam);
BOOL CALLBACK EnumWindowsProc(HWND window, LPARAM lParam);
#endif /* SRC_INCLUDE_WINENUM_H_ */
