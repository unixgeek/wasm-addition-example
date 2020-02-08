cmake_minimum_required(VERSION 3.13)
project(wasm_addition_example C)

set(CMAKE_C_STANDARD 99)

add_executable(wasm_addition_example src/main.c)

configure_file("html/ccall.html" ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file("html/cwrap.html" ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file("html/direct.html" ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

# -03 is recommended for release build.
# WASM=1 to use wasm rather than asm.js.
# EXIT_RUNTIME=0 is needed so the runtime is not closed when main() completes or there is no main().
# EXTRA_EXPORTED_RUNTIME_METHODS indicates extra modules to export.
# EXPORTED_FUNCTIONS indicates the C functions to export. You need this or the function needs to be declared with EMSCRIPTEN_KEEPALIVE.
set_target_properties(wasm_addition_example PROPERTIES LINK_FLAGS "-O3 -s WASM=1 -s EXIT_RUNTIME=0 -s EXTRA_EXPORTED_RUNTIME_METHODS='[ccall, cwrap]' -s EXPORTED_FUNCTIONS='[_lame_add]'")