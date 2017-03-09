/*
  AltDrag - en-US localization by Stefan Sundin

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
*/
struct strings en_US = {
 /* === translation info === */
 /* code               */ L"en-US",
 /* lang_english       */ L"English",
 /* lang               */ L"English",
 /* author             */ L"Stefan Sundin",
 /* === app === */
 /* tray_enabled       */ L"AltDrag",
 /* tray_disabled      */ L"AltDrag (disabled)",
 /* menu */
 /* enable             */ L"Enable",
 /* disable            */ L"Disable",
 /* hide               */ L"Hide tray",
 /* update             */ L"Update available!",
 /* config             */ L"Configure",
 /* about              */ L"About",
 /* exit               */ L"Exit",

 /* update */
 /* balloon            */ L"New version found!",
 /* dialog             */ L"A new version is available. Go to website?",
 /* nonew              */ L"No update available.",

 /* === config === */
 /* title              */ L"AltDrag Configuration",
 /* tabs */
 /* general            */ L"General",
 /* input              */ L"Mouse and keyboard",
 /* blacklist          */ L"Blacklist",
 /* advanced           */ L"Advanced",
 /* about              */ L"About",

 /* general tab */
 /* box                */ L"General settings",
 /* autofocus          */ L"&Focus windows when dragging.\nYou can also press Ctrl to focus windows.",
 /* aero               */ L"Mimic &Aero Snap",
 /* inactivescroll     */ L"&Scroll inactive windows",
 /* mdi                */ L"&MDI support",
 /* autosnap           */ L"Automatically snap to:",
 /* autosnap0          */ L"Disabled",
 /* autosnap1          */ L"To screen borders",
 /* autosnap2          */ L"+ outside of windows",
 /* autosnap3          */ L"+ inside of windows",
 /* language           */ L"Language:",
 /* autostart_box      */ L"Autostart",
 /* autostart          */ L"S&tart AltDrag when logging on",
 /* autostart_hide     */ L"&Hide tray",
 /* autostart_elevate  */ L"&Elevate to administrator privileges",
 /*       elevate_tip  */ L"Note that a UAC prompt will appear every time you log in, unless you disable UAC completely.",
 /* elevate            */ L"E&levate",
 /* elevated           */ L"Elevated",
 /* elevate_tip        */ L"This will create a new instance of AltDrag which is running with administrator privileges. This allows AltDrag to manage other programs which are running with administrator privileges.\n\nYou will have to approve a UAC prompt from Windows to allow AltDrag to run with administrator privileges.",
 /* elevation_aborted  */ L"Elevation aborted.",
 /* autosave           */ L"Note: Settings are saved and applied instantly!",

 /* input tab */
 /* mouse */
 /* box                */ L"Mouse actions",
 /* lmb                */ L"Left mouse button:",
 /* mmb                */ L"Middle mouse button:",
 /* rmb                */ L"Right mouse button:",
 /* mb4                */ L"Mouse button 4:",
 /* mb5                */ L"Mouse button 5:",
 /* scroll             */ L"Scroll wheel:",
 /* lowerwithmmb       */ L"&Lower windows by middle clicking on title bars",

 /* actions */
 /* move               */ L"Move window",
 /* resize             */ L"Resize window",
 /* close              */ L"Close window",
 /* minimize           */ L"Minimize window",
 /* lower              */ L"Lower window",
 /* alwaysontop        */ L"Toggle always on top",
 /* center             */ L"Center window on screen",
 /* nothing            */ L"Nothing",
 /* alttab             */ L"Alt+Tab",
 /* volume             */ L"Volume",
 /* transparency       */ L"Transparency",

 /* hotkeys */
 /* box                */ L"Hotkeys",
 /* leftalt            */ L"L&eft Alt",
 /* rightalt           */ L"&Right Alt",
 /* leftwinkey         */ L"Left &Winkey",
 /* rightwinkey        */ L"Right W&inkey",
 /* leftctrl           */ L"Left &Ctrl",
 /* rightctrl          */ L"Right C&trl",
 /* more               */ L"You can add any key by editing the ini file.\nUse the shift key to snap windows to each other.",

 /* blacklist tab */
 /* box                */ L"Blacklist settings",
 /* processblacklist   */ L"Process blacklist:",
 /* blacklist          */ L"Blacklist:",
 /* snaplist           */ L"Snaplist:",
 /* explanation        */ L"Read <a href=\"https://stefansundin.github.io/altdrag/doc/blacklist.html\">the website</a> for a thorough explanation on how the blacklist works!",
 /* findwindow_box     */ L"Identify window",
 /* _explanation       */ L"Click the icon to identify the classname of a window so that you can add it to the Blacklist or Snaplist above.",

 /* advanced tab */
 /* box                */ L"Advanced settings",
 /* hookwindows        */ L"&Enable snapping when normally moving windows.\nWorks in conjunction with automatic snapping!",
 /* hookwindows_warn   */ L"Note that this is not 100% safe as this feature works by hooking into other processes. This might be risky to use when playing games with anti-cheat protection.\n\nAre you sure you want to enable this feature?",
 /* checkonstartup     */ L"A&utomatically check for updates",
 /* beta               */ L"Check for &beta versions",
 /* checknow           */ L"&Check now",
 /* ini                */ L"AltDrag's settings are saved in AltDrag.ini. There are a few things that you can only configure by editing the file manually.",
 /* openini            */ L"Open &ini file",

 /* about tab */
 /* box                */ L"About AltDrag",
 /* version            */ L"Version 1.1",
 /* author             */ L"Created by Stefan Sundin",
 /* license            */ L"AltDrag is free and open source software!\nFeel free to redistribute!",
 /* donate             */ L"&Donate",
 /* translation_credit */ L"Translation credit",

 /* === misc === */
 /* unhook_error       */ L"There was an error disabling AltDrag. This was most likely caused by Windows having already disabled AltDrag's hooks.\n\nIf this is the first time this has happened, you can safely ignore it and continue using AltDrag.\n\nIf this is happening repeatedly, you can read on the website how to prevent this from happening again (look for 'AltDrag mysteriously stops working' in the documentation).",
};
