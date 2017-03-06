/*
 * autostart.h
 *
 *  Created on: Feb 26, 2017
 *      Author: Daniel
 */

#ifndef SRC_INCLUDE_AUTOSTART_H_
#define SRC_INCLUDE_AUTOSTART_H_

// Prototypes
void CheckAutostart(int *on, int *hidden, int *elevated);
void SetAutostart(int on, int hide, int elevate);

#endif /* SRC_INCLUDE_AUTOSTART_H_ */
