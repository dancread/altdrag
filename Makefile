all:
	i686-w64-mingw32-windres include/altdrag.rc bin/altdrag.o
	i686-w64-mingw32-windres include/hooks.rc bin/hooks.o
	i686-w64-mingw32-gcc -o AltDrag.exe altdrag.c bin/altdrag.o -mwindows -lshlwapi -lwininet -lcomctl32 -lole32 -g -O0
	i686-w64-mingw32-gcc -o hooks.dll hooks.c bin/hooks.o -mdll -lshlwapi -lcomctl32 -lpsapi -lole32 -lgdi32 -g -O0
unhook:
	i686-w64-mingw32-gcc -o bin/unhook.exe tools/unhook.c
clean:
	rm AltDrag.exe hooks.dll
	echo "" > log.txt
kill:
	taskkill /IM AltDrag.exe