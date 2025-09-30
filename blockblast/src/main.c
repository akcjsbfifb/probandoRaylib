#include "mostrarPiezas.h"


int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mi primer juego en C con Raylib");

    srand(time(NULL));

    limpiarMapaInicial();

    generarPiezas();

    #if defined(PLATFORM_WEB)
        emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
    #else
        SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
        //--------------------------------------------------------------------------------------

        // Main game loop
        while (!WindowShouldClose())    // Detect window close button or ESC key
        {
            UpdateDrawFrame();
        }
    #endif

    CloseWindow(); // nunca llega en web, pero lo dejamos
    return 0;
}
