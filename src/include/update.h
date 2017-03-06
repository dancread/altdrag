/*
 * update.h
 *
 *  Created on: Feb 26, 2017
 *      Author: Daniel
 */

#ifndef SRC_INCLUDE_UPDATE_H_
#define SRC_INCLUDE_UPDATE_H_
#include <windows.h>

// Globals
int update = 0;
// Prototypes
int OpenUrl(wchar_t *url);
DWORD WINAPI _CheckForUpdate(LPVOID arg);
void CheckForUpdate(int p_verbose);

#endif /* SRC_INCLUDE_UPDATE_H_ */
