# WASM Addition Example
This project is a very simple example of how web assembly works.

# Build
## Install emsdk
1. `git clone https://github.com/emscripten-core/emsdk.git`
1. `cd emsdk`
1. `./emsdk install latest`
1. `./emsdk activate latest`

## Compile Examples
1. `source PATH_TO_EMSDK_ROOT/emsdk_env.sh`
1. `mkdir build`
1. `cd build`
1. `emconfigure cmake ..`
1. `emmake make`

# Run
1. `emrun --no_browser --port 8080 .`
1. Open http://localhost:8080 in a browser.

# Examples
### ccall.html 
An example of using `Module.ccall` to call a function in C. 
### cwrap.html
An example of using `Module.cwrap` to define a JavaScript function that calls a function in C. This is
better than `ccall` as it makes the code more "readable".
### direct.html
An example of calling a function in C directly since all exported functions get exported as JavaScript
functions, prefixed with a `_`. This is supposedly faster than `ccall` and `cwrap`, but requires you to do the type
translations yourself. 
### main.c 
An example of exporting a C function to JavaScript. It also provides and example of calling a JavaScript 
function from C.

# CLion Setup
1. Create new Toolchain called *Emscripten*
    1. Set C Compiler to `PATH_TO_EMSDK_ROOT/upstream/emscripten/emcc`
    1. Set C++ Compiler to your `PATH_TO_EMSDK_ROOT/upstream/emscripten/em++`
1. Create new CMake Profile called *Emscripten Debug*
    1. Add to CMake Options: `-DCMAKE_TOOLCHAIN_FILE=PATH_TO_EMSDK_ROOT/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake`
    1. Add to Environment Variables:
        * `EMSDK_NODE=PATH_TO_EMSDK_ROOT/node/12.9.1_64bit/bin/node`
        * `EMSDK=PATH_TO_EMSDK_ROOT`
        * `EM_CONFIG=HOME/.emscripten`
1. Choose *Emscripten Debug* in *Run/Debug configurations*