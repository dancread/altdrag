# src\config\autostart.c
# src\config\config.c
# src\config\update.c
# src\core\altdrag.c
# src\core\error.c
# src\core\tray.c
# src\dll\hooks.c
# src\dll\winenum.c
# src\lang\languages.c
# src\lang\localization.c
CC=i686-w64-mingw32-gcc
LIBS=-lshlwapi -lwininet -lcomctl32 -lole32
DLL_LIBS=-mdll -lshlwapi -lwininet -lcomctl32 -lole32 -lpsapi
RES_C=i686-w64-mingw32-windres
ALT_DRAG_SRC= src/config/config.c src/config/update.c src/core/altdrag.c src/core/error.c src/core/tray.c src/dll/hooks.c src/dll/winenum.c src/lang/languages.c src/lang/localization.c
ALT_DRAG_OBJ=$(ALT_DRAG_SRC:.c=.o)
all: altdrag tools
	echo "Done"
altdrag: dll exec
	echo "Done"	
dll:
	mkdir -p dll
	$(RES_C) resource/hooks.rc dll/hooks.o
	#$(CC) -o dll/error.o src/core/error.c $(DLL_LIBS)
	#$(CC) -o dll/dll_utils.o src/dll/dll_utils.c $(DLL_LIBS)
	#$(CC) -o dll/winenum.o dll/dll_utils.o src/dll/winenum.c $(DLL_LIBS)
	#$(CC) -o dll/hooks.dll src/dll/hooks.c dll/winenum.o dll/error.o dll/hooks.o dll/dll_utils.o $(DLL_LIBS)
	$(CC) -o dll/hooks.dll dll/hooks.o src/dll/hooks.c src/dll/winenum.c src/core/error.c src/dll/dll_utils.c $(DLL_LIBS) -g
exec:
	mkdir -p bin
	$(RES_C) resource/altdrag.rc bin/altdrag.o
	#$(CC) -o bin/autostart.o src/config/autostart.c
	#$(CC) -o bin/error.o  src/core/error.c
	$(CC) -w -o bin/AltDrag.exe bin/altdrag.o src/core/altdrag.c src/core/tray.c src/core/error.c src/config/config.c src/config/autostart.c src/config/update.c src/lang/languages.c src/lang/localization.c -mwindows $(LIBS)
tools:
	mkdir -p bin
	i686-w64-mingw32-gcc -o bin/unhook.exe src/tools/unhook.c
	i686-w64-mingw32-gcc -o bin/import_languages.exe src/tools/import_languages.c -lshlwapi
	x86_64-w64-mingw32-gcc -o bin/HookWindows_x64.exe src/tools/hookwindows_x64.c  -lshlwapi
clean:
	rm -rf bin
	rm -rf dll
	echo "" > log.txt
kill:
	taskkill /IM AltDrag.exe