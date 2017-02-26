SRC_DIR=src
all: altdrag tools
	echo "Done"
altdrag:
	mkdir -p bin
	i686-w64-mingw32-windres resource/altdrag.rc bin/altdrag.o
	i686-w64-mingw32-windres resource/hooks.rc bin/hooks.o
	i686-w64-mingw32-gcc -o bin/AltDrag.exe src/core/altdrag.c bin/altdrag.o -mwindows -lshlwapi -lwininet -lcomctl32 -lole32 -g -O0
	i686-w64-mingw32-gcc -o bin/hooks.dll src/dll/hooks.c bin/hooks.o -mdll -lshlwapi -lcomctl32 -lpsapi -lole32 -lgdi32 -g -O0
tools:
	mkdir -p bin
	i686-w64-mingw32-gcc -o bin/unhook.exe src/tools/unhook.c
	i686-w64-mingw32-gcc -o bin/import_languages.exe src/tools/import_languages.c -lshlwapi
	x86_64-w64-mingw32-gcc -o bin/HookWindows_x64.exe src/tools/hookwindows_x64.c  -lshlwapi
clean:
	rm -r bin
	echo "" > log.txt
kill:
	taskkill /IM AltDrag.exe
