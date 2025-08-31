#include "raylib.h"
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define MAP_SIZE 9
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

#define HEIGHT_PIEZAS 70 + 30 * 9
#define POS_FIRST (SCREEN_WIDTH / 2.0f - 30 * 4.5f)
#define POS_SECOND (SCREEN_WIDTH / 2.0f - 30 * 1.5f)
#define POS_THIRD (SCREEN_WIDTH / 2.0f + 30 * 1.5f)

#define SQUARE_SIZE 29

typedef enum {
    PIEZA_LINEA,
    PIEZA_CUBO,
    PIEZA_COLUMNA,
    PIEZA_TE,
    PIEZA_J,
    PIEZA_S,
    PIEZA_Z
} TipoPieza;

typedef struct {
  int mapa[9][9];
} Mapa;

typedef struct {
  Vector2 pos;
  Vector2 posInicial;
  TipoPieza tipo;
  Color color;
  int mapa[3][3];
} Pieza3;


Pieza3 linea = {.color = RED, .tipo = PIEZA_LINEA, .posInicial = {POS_FIRST, HEIGHT_PIEZAS}, .pos = {POS_FIRST, HEIGHT_PIEZAS},
                .mapa = {{0, 0, 0}, {1, 1, 1}, {0, 0, 0}}};
Pieza3 cubo = {.color = BLACK, .tipo = PIEZA_CUBO, .posInicial = {POS_SECOND, HEIGHT_PIEZAS}, .pos = {POS_SECOND, HEIGHT_PIEZAS},
               .mapa = {{1, 1, 0}, {1, 1, 0}, {0, 0, 0}}};

Pieza3 columna = {.color = BLUE, .tipo = PIEZA_COLUMNA, .posInicial = {POS_THIRD, HEIGHT_PIEZAS}, .pos = {POS_THIRD, HEIGHT_PIEZAS},
               .mapa = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}}};

Pieza3 te = {
    .color = GREEN,
    .tipo = PIEZA_TE,
    .posInicial = {POS_FIRST, HEIGHT_PIEZAS},
    .pos = {POS_FIRST, HEIGHT_PIEZAS},
    .mapa = {{0, 1, 0},
             {1, 1, 1},
             {0, 0, 0}}
};

void mostrarMapa(const Mapa *actual);
void limpiarMapa(Mapa *actual);
void mostrarPieza(Pieza3 pieza);
void moverPieza(Pieza3 *pieza);
void encontrarColision(Mapa *mapa, Pieza3 *pieza);
void resetPieza(Pieza3 *pieza);
void consolidarMapa(Mapa *mapa);
void limpiarMapaInicial(Mapa *actual);
bool piezaEntraCoord(Mapa *mapa, Pieza3 pieza, int x, int y);
void analizarColumn(Mapa *mapa);
void analizarFilas(Mapa *mapa);

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mi primer juego en C con Raylib");

  Mapa mapa;

  limpiarMapaInicial(&mapa);
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    analizarFilas(&mapa);
    analizarColumn(&mapa);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    mostrarMapa(&mapa);
    mostrarPieza(linea);
    mostrarPieza(cubo);
    mostrarPieza(columna);
    EndDrawing();

    // Primero limpiamos el mapa (para que no queden restos de la pieza en otra
    // pos)
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        limpiarMapa(&mapa);

        moverPieza(&linea);
        moverPieza(&cubo);
        moverPieza(&columna);

        encontrarColision(&mapa, &linea);
        encontrarColision(&mapa, &cubo);
        encontrarColision(&mapa, &columna);
    }else{
       resetPieza(&linea);
       resetPieza(&cubo);
       resetPieza(&columna);
       consolidarMapa(&mapa);
    }
  }

  CloseWindow();
  return 0;
}

void consolidarMapa(Mapa *mapa){
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      if(mapa->mapa[i][j] == 1) mapa->mapa[i][j] = 2;
    }
  }
}
bool piezaEntraCoord(Mapa *mapa, Pieza3 pieza, int x, int y){

  switch(pieza.tipo){
    case PIEZA_LINEA:
      if(mapa->mapa[x+1][y] != 2 &&
         mapa->mapa[x+1][y+1] != 2 &&
         mapa->mapa[x+1][y+2] != 2 && y < 7){
        return true;
      }
      break;
    case PIEZA_CUBO:
      if(mapa->mapa[x][y] != 2 &&
         mapa->mapa[x][y+1] != 2 &&
         mapa->mapa[x+1][y] != 2 &&
         mapa->mapa[x+1][y+1] != 2 && x > -1 && x< 8 && y >= 0&& y < 8){
        return true;
      }
      break;
    case PIEZA_COLUMNA:
      if(mapa->mapa[x][y+1] != 2 &&
         mapa->mapa[x+1][y+1] != 2 &&
         mapa->mapa[x+2][y+1] != 2 && x > -1 && x< 7 ){
        return true;

      }
      break;
    default: return false;
  }
  return false;
}
void analizarColumn(Mapa *mapa){
  for(int i = 0; i<9; i++){
    int flag = 0;

    for(int j = 0; j<9 ; j++){
        if(mapa->mapa[j][i] != 2){
          flag = 1;
      }
    }
    if(flag==0){
      for(int j = 0; j<9 ; j++){
        mapa->mapa[j][i] = 0;
      }   
    }
  }
}
void analizarFilas(Mapa *mapa){
  for(int i = 0; i<9; i++){
    int flag = 0;

    for(int j = 0; j<9 ; j++){
        if(mapa->mapa[i][j] != 2){
          flag = 1;
      }
    }
    if(flag==0){
      for(int j = 0; j<9 ; j++){
        mapa->mapa[i][j] = 0;
      }   
    }
  }
}
void encontrarColision(Mapa *mapa, Pieza3 *pieza) {
  // Convertir posición en coordenadas del mapa (columna/fila base)
  int colu = (int)((pieza->pos.x - POS_FIRST) / 30);
  int fila = (int)((pieza->pos.y - 50) / 30);

  // Recorremos la matriz 3x3 de la pieza
  //
  if(piezaEntraCoord(mapa, *pieza, fila, colu)){
    for (int i = 0; i < 3; i++) {     // filas de la pieza
      for (int j = 0; j < 3; j++) {   // columnas de la pieza
        if (pieza->mapa[i][j] == 1) { // si hay parte de la pieza
          int mapFila = fila + i;
          int mapColu = colu + j;
          // Validar que está dentro de los límites del mapa
          if (mapFila >= 0 && mapFila < 9 && mapColu >= 0 && mapColu < 9 && mapa->mapa[mapFila][mapColu] == 0){
              mapa->mapa[mapFila][mapColu] = 1;
          }

        }
      }
    }
  }
}
void resetPieza(Pieza3 *pieza){
  pieza->pos.x = pieza->posInicial.x;
  pieza->pos.y = pieza->posInicial.y;
}
void moverPieza(Pieza3 *pieza) {
  if (GetMousePosition().x > pieza->pos.x - 10 &&
      GetMousePosition().x < pieza->pos.x + 30 * 3 + 10 &&
      GetMousePosition().y > pieza->pos.y - 10 &&
      GetMousePosition().y < pieza->pos.y + 30 * 3 + 10) {
    pieza->pos.x += GetMouseDelta().x;
    pieza->pos.y += GetMouseDelta().y;
  }else{pieza->pos.x = pieza->posInicial.x; pieza->pos.y = pieza->posInicial.y;}
}
void mostrarMapa(const Mapa *actual) {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      if (actual->mapa[i][j] == 0)
        DrawRectangle(POS_FIRST + j * 30, 50 + i * 30, 29, 29, GRAY);
      if (actual->mapa[i][j] == 1)
        DrawRectangle(POS_FIRST + j * 30, 50 + i * 30, 29, 29, ORANGE);
      if (actual->mapa[i][j] == 2)
        DrawRectangle(POS_FIRST + j * 30, 50 + i * 30, 29, 29, RED);
    }
  }
}

void limpiarMapaInicial(Mapa *actual) {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
       actual->mapa[i][j] = 0;
    }
  }
}
void limpiarMapa(Mapa *actual) {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      if(actual->mapa[i][j] == 1) actual->mapa[i][j] = 0;
    }
  }
}

void mostrarPieza(Pieza3 pieza) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (pieza.mapa[i][j] == 1) {
        DrawRectangle(pieza.pos.x + j * 30, pieza.pos.y + i * 30, 29, 29, pieza.color);
      }
    }
  }
}
