#include "mostrarPiezas.h"


int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mi primer juego en C con Raylib");

    srand(time(NULL));

    limpiarMapaInicial();
    SetTargetFPS(60);

    generarPiezas();

    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);

    CloseWindow(); // nunca llega en web, pero lo dejamos
    return 0;
}
