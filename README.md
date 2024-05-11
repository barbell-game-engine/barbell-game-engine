# Hello SDL

Development environment
- Windows 11
- SDL2-2.30.2

## Setting up development environment in Windows

How to set up g++ and make:
- [download gnu tools for windows](https://sourceforge.net/projects/gnuwin32/)
- [download make](https://gnuwin32.sourceforge.net/packages/make.htm)

How to set up emscription:
- followed instructions [here](https://emscripten.org/docs/getting_started/downloads.html#platform-notes-installation-instructions-sdk)

How to set up SDL:
1. Download the latest release of SDL from the [SDL website.](https://www.libsdl.org/) make sure to download the 'devel' version for development.
2. create a directory called 'sdl' and place the entire release in that directory. Your folder should now look like this:
```
root/
- assets/
- engine/
- ...
- sdl/
--SDL2-<version>/
---cmake/
---docs/
--- ...
```
3. go into the makefile and set the `SDL_VERSION` variable to the version you downloaded
4. run 'make' followed by your desired platform to compile. This will create an output folder where you can find your game!


# Todo:
- [X] Figure out how to build for webasm using [emcc](https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_Wasm) resource: [making a wasm game](https://robaboukhalil.medium.com/porting-games-to-the-web-with-webassembly-70d598e1a3ec)
- [x] Make a single main.cc file that can build for web or for windows 


# Useful websites
- [Emscription with SDL](https://wiki.libsdl.org/SDL2/README/emscripten)
