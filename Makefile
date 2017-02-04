all:
	C:\TDM-GCC-32\bin\windres include/altdrag.rc bin/altdrag.o
	C:\TDM-GCC-32\bin\windres include/hooks.rc bin/hooks.o
	C:\TDM-GCC-64\bin\windres include/hookwindows_x64.rc bin/hookwindows_x64.o
	C:\TDM-GCC-64\bin\windres include/hooks.rc bin/hooks_x64.o
	C:\TDM-GCC-32\bin\mingw32-gcc -o AltDrag.exe altdrag.c bin/altdrag.o -mwindows -lshlwapi -lwininet -lcomctl32 -lole32 -lshell32 -g -DDEBUG
	C:\TDM-GCC-32\bin\mingw32-gcc hooks.dll hooks.c bin/hooks.o -mdll -lshlwapi -lcomctl32 -lpsapi -lole32 -g -DDEBUG
	C:\TDM-GCC-64\bin\x86_64-w64-mingw32-gcc -o HookWindows_x64.exe hookwindows_x64.c bin/hookwindows_x64.o -mwindows -lshlwapi -g -DDEBUG
	C:\TDM-GCC-64\bin\x86_64-w64-mingw32-gcc -o hooks_x64.dll hooks.c bin/hooks_x64.o -mdll -lshlwapi -lcomctl32 -lpsapi -lole32 -g -DDEBUG
clean:
	start "taskkill /IM AltDrag.exe & exit"
	PING -n 5 127.0.0.1>nul
	rmdir /s /q bin
	mkdir bin
	del AltDrag.exe hooks.dll hooks_x64.dll HookWindows_x64.exe
installer:
	makensis /V2 installer.nsi
