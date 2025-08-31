#include "raylib.h"
#include "raymath.h"
#include <math.h>
#include <stdio.h>

#define CELL_SIZE 50 // Tamaño de celda
#define MAP_SIZE 1000
int map[MAP_SIZE][MAP_SIZE];
int mapCopia[MAP_SIZE][MAP_SIZE];

void initMap(int mapa[MAP_SIZE][MAP_SIZE]);
void mostrarMap(int mapa[MAP_SIZE][MAP_SIZE]);
int cantVecinos(int x, int y);
void revivirMuertas(int x, int y);

void actualizarMapa();
int main() {
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Grilla infinita con Camera2D");
  initMap(map);
  initMap(mapCopia);
  Camera2D camera = {0};
  camera.zoom = 1.0f;

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    // --- Movimiento de cámara ---
        //
    if (IsKeyDown(KEY_E)) {
        actualizarMapa();
    }
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
      Vector2 delta = GetMouseDelta();
      delta = Vector2Scale(delta, -1.0f / camera.zoom);
      camera.target = Vector2Add(camera.target, delta);
    } else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
      Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);

      int posX = (int)floorf(mouseWorldPos.x / CELL_SIZE) + MAP_SIZE/2;
      int posY = (int)floorf(mouseWorldPos.y / CELL_SIZE) + MAP_SIZE/2;

      if(map[posX][posY] == 0){
            map[posX][posY] = 1;
            mapCopia[posX][posY] = 1;
      }else{
            map[posX][posY] = 0;
            mapCopia[posX][posY] = 0;
            }
    }

    // --- Zoom con la rueda ---
    float wheel = GetMouseWheelMove();
    if (wheel != 0) {
      Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);
      camera.offset = GetMousePosition();
      camera.target = mouseWorldPos;

      float scale = 0.2f * wheel;
      camera.zoom = Clamp(expf(logf(camera.zoom) + scale), 0.125f, 64.0f);
    }

    // --- Dibujo ---
    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode2D(camera);

    // Obtener límites visibles en el mundo
    Vector2 topLeft = GetScreenToWorld2D((Vector2){0, 0}, camera);
    Vector2 bottomRight =
        GetScreenToWorld2D((Vector2){screenWidth, screenHeight}, camera);

    int startX = (int)floor(topLeft.x / CELL_SIZE) * CELL_SIZE;
    int endX = (int)ceil(bottomRight.x / CELL_SIZE) * CELL_SIZE;
    int startY = (int)floor(topLeft.y / CELL_SIZE) * CELL_SIZE;
    int endY = (int)ceil(bottomRight.y / CELL_SIZE) * CELL_SIZE;

    // Dibujar líneas verticales
    for (int x = startX; x <= endX; x += CELL_SIZE) {
      DrawLine(x, startY, x, endY, LIGHTGRAY);
    }

    // Dibujar líneas horizontales
    for (int y = startY; y <= endY; y += CELL_SIZE) {
      DrawLine(startX, y, endX, y, LIGHTGRAY);
    }
    mostrarMap(map);

    // Dibujar el origen (0,0) como referencia
    DrawCircle(0, 0, 5, RED);

    EndMode2D();

    // Mouse position (pantalla)
    DrawCircleV(GetMousePosition(), 4, DARKGRAY);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}

void initMap(int mapa[MAP_SIZE][MAP_SIZE]) {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      mapa[i][j] = 0;
    }
  }
}
void mostrarMap(int mapa[MAP_SIZE][MAP_SIZE]) {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      if (mapa[i][j] == 1) {

        DrawRectangle(CELL_SIZE * (i - MAP_SIZE/2), 
              CELL_SIZE * (j - MAP_SIZE/2), 
              CELL_SIZE, CELL_SIZE, BLACK);
      }
    }
  }
}

int cantVecinos(int x, int y){
    int count = 0;
    for (int i = -1; i<2; i++){
         for (int j = -1;j<2;j++){
            if (x+i >= 0 && x+i < MAP_SIZE && y+j >= 0 && y+j < MAP_SIZE) {
                if (map[x+i][y+j] == 1) count++;
            }
         }
    }
    if (map[x][y] == 1) count--;
    return count;
}

void actualizarMapa(){
   for (int i = 0; i < MAP_SIZE; i++) {
      for (int j = 0; j < MAP_SIZE; j++) {
            if(map[i][j] == 1){

                int cant = cantVecinos(i, j);
                revivirMuertas(i, j);
                if(cant < 2 || cant > 3){

                    mapCopia[i][j] = 0;
                }
            }
      }
    }   
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = mapCopia[i][j];
        }
    }
}

void revivirMuertas(int x, int y){
    for (int i = -1; i<2; i++){
         for (int j = -1;j<2;j++){
            if(map[x+i][y+j] == 0 && cantVecinos(x + i, y + j) == 3){
                mapCopia[x+i][y+j] = 1;
            }
         }
    }
 
}

