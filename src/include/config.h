/*
 * config.h
 *
 *  Created on: Feb 26, 2017
 *      Author: Daniel
 */

#ifndef SRC_LANG_CONFIG_H_
#define SRC_LANG_CONFIG_H_
// Boring stuff
BOOL CALLBACK PropSheetProc(HWND, UINT, LPARAM);
INT_PTR CALLBACK GeneralPageDialogProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK InputPageDialogProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK BlacklistPageDialogProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK AdvancedPageDialogProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK AboutPageDialogProc(HWND, UINT, WPARAM, LPARAM);
void LinkProc(HWND, UINT, WPARAM, LPARAM);


// Blacklist
LRESULT CALLBACK CursorProc(HWND, UINT, WPARAM, LPARAM);
#endif /* SRC_LANG_CONFIG_H_ */
