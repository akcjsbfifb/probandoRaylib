#include <stdint.h>
#include "raylib.h"

int main(void) {
    InitWindow(800, 450, "Mi primer juego en C con Raylib");

    Vector2 ballPosition = { 400, 225 };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT))  ballPosition.x -= 2.0f;
        if (IsKeyDown(KEY_DOWN))  ballPosition.y += 2.0f;
        if (IsKeyDown(KEY_UP))    ballPosition.y -= 2.0f;

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Usa las flechas para mover la bola", 190, 200, 20, LIGHTGRAY);
            DrawCircleV(ballPosition, 20, MAROON);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
