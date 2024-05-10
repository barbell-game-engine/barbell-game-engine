SRCDIR = src
INCLUDEDIR = include
SDLDIR = sdl
WIN_DIST_DIR = windows
WEB_DIST_DIR = web

SRCS = $(wildcard $(SRCDIR)/*.cc)

all:
	@echo options:
	@echo 'make windows' for a windows build
	@echo 'make web' for a web build with wasm

windows:
	if exist $(WIN_DIST_DIR) rmdir /s /q $(WIN_DIST_DIR)
	mkdir $(WIN_DIST_DIR)
	g++ engine/win_main.cc $(SRCS) -o $(WIN_DIST_DIR)/main \
	-I$(INCLUDEDIR) \
	-I$(SRCDIR) \
	-I$(SDLDIR)/SDL2-2.30.2/x86_64-w64-mingw32/include \
	-L$(SDLDIR)/SDL2-2.30.2/x86_64-w64-mingw32/lib  \
	-lmingw32 \
	-lSDL2main \
	-lSDL2
	copy $(SDLDIR)\SDL2-2.30.2\x86_64-w64-mingw32\bin\SDL2.dll $(WIN_DIST_DIR)
	mkdir $(WIN_DIST_DIR)\assets
	xcopy assets $(WIN_DIST_DIR)\assets /e

web:
	if exist $(WEB_DIST_DIR) rmdir /s /q $(WEB_DIST_DIR)	
	mkdir $(WEB_DIST_DIR)
	copy engine\index.html $(WEB_DIST_DIR)
	mkdir $(WEB_DIST_DIR)\assets
	xcopy assets $(WEB_DIST_DIR)\assets /e
	emcc engine/web_main.cc $(SRCS) -o $(WEB_DIST_DIR)/index.js \
	-I$(INCLUDEDIR) \
	-I$(SRCDIR) \
	-s USE_SDL=2 \
	-s USE_SDL_IMAGE=2 \
	-s SDL2_IMAGE_FORMATS='["png"]' \
	--preload-file assets/
	

.PHONY: web windows