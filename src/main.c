#include <emscripten/emscripten.h>

// This is not C++, but it was still recommended to include this to prevent C++ name mangling.
#ifdef __cplusplus
extern "C" {
#endif

EMSCRIPTEN_KEEPALIVE
int lame_add(int n1, int n2) {
    // There is also EM_JS().
    EM_ASM({
               console.log('main.c: lame_add(' + $0 + ',' + $1 + ')');
           }, n1, n2);

    return n1 + n2;
}

#ifdef __cplusplus
}
#endif