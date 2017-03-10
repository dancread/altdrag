/*
  Copyright (C) 2015  Stefan Sundin

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
*/
#ifndef SRC_STRINGS_H_
#define SRC_STRINGS_H_
#include <windows.h>
struct strings {
  wchar_t *code;
  wchar_t *lang_english;
  wchar_t *lang;
  wchar_t *author;

  // tray
  wchar_t *tray_enabled;
  wchar_t *tray_disabled;

  // menu
  wchar_t *menu_enable;
  wchar_t *menu_disable;
  wchar_t *menu_hide;
  wchar_t *menu_update;
  wchar_t *menu_config;
  wchar_t *menu_about;
  wchar_t *menu_exit;

  // update
  wchar_t *update_balloon;
  wchar_t *update_dialog;
  wchar_t *update_nonew;

  // config
  wchar_t *title;
  wchar_t *tab_general;
  wchar_t *tab_input;
  wchar_t *tab_blacklist;
  wchar_t *tab_advanced;
  wchar_t *tab_about;

  // general
  wchar_t *general_box;
  wchar_t *general_autofocus;
  wchar_t *general_aero;
  wchar_t *general_inactivescroll;
  wchar_t *general_mdi;
  wchar_t *general_autosnap;
  wchar_t *general_autosnap0;
  wchar_t *general_autosnap1;
  wchar_t *general_autosnap2;
  wchar_t *general_autosnap3;
  wchar_t *general_language;
  wchar_t *general_autostart_box;
  wchar_t *general_autostart;
  wchar_t *general_autostart_hide;
  wchar_t *general_autostart_elevate;
  wchar_t *general_autostart_elevate_tip;
  wchar_t *general_elevate;
  wchar_t *general_elevated;
  wchar_t *general_elevate_tip;
  wchar_t *general_elevation_aborted;
  wchar_t *general_autosave;

  // input
  // mouse
  wchar_t *input_mouse_box;
  wchar_t *input_mouse_lmb;
  wchar_t *input_mouse_mmb;
  wchar_t *input_mouse_rmb;
  wchar_t *input_mouse_mb4;
  wchar_t *input_mouse_mb5;
  wchar_t *input_mouse_scroll;
  wchar_t *input_mouse_lowerwithmmb;
  // actions
  wchar_t *input_actions_move;
  wchar_t *input_actions_resize;
  wchar_t *input_actions_close;
  wchar_t *input_actions_minimize;
  wchar_t *input_actions_lower;
  wchar_t *input_actions_alwaysontop;
  wchar_t *input_actions_center;
  wchar_t *input_actions_nothing;
  wchar_t *input_actions_alttab;
  wchar_t *input_actions_volume;
  wchar_t *input_actions_transparency;
  // hotkeys
  wchar_t *input_hotkeys_box;
  wchar_t *input_hotkeys_leftalt;
  wchar_t *input_hotkeys_rightalt;
  wchar_t *input_hotkeys_leftwinkey;
  wchar_t *input_hotkeys_rightwinkey;
  wchar_t *input_hotkeys_leftctrl;
  wchar_t *input_hotkeys_rightctrl;
  wchar_t *input_hotkeys_more;

  // blacklist
  wchar_t *blacklist_box;
  wchar_t *blacklist_processblacklist;
  wchar_t *blacklist_blacklist;
  wchar_t *blacklist_snaplist;
  wchar_t *blacklist_explanation;
  wchar_t *blacklist_findwindow_box;
  wchar_t *blacklist_findwindow_explanation;

  // advanced
  wchar_t *advanced_box;
  wchar_t *advanced_hookwindows;
  wchar_t *advanced_hookwindows_warn;
  wchar_t *advanced_checkonstartup;
  wchar_t *advanced_beta;
  wchar_t *advanced_checknow;
  wchar_t *advanced_ini;
  wchar_t *advanced_openini;

  // about
  wchar_t *about_box;
  wchar_t *about_version;
  wchar_t *about_author;
  wchar_t *about_license;
  wchar_t *about_donate;
  wchar_t *about_translation_credit;

  /* misc */
  wchar_t *unhook_error;
};

struct strings l10n_ini;

struct l10n_mapping_t {
  wchar_t **str;
  wchar_t *name;
};

#endif /* SRC_STRINGS_H_ */
