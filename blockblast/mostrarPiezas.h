#ifndef __MOSTRARPIEZAS_H__
#define __MOSTRARPIEZAS_H__
#include "raylib.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <emscripten.h>

#define MAP_SIZE 9
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

#define CANT_PIEZAS 20

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
    PIEZA_J1,
    PIEZA_J2,
    PIEZA_J3,
    PIEZA_J4,
    PIEZA_S1,
    PIEZA_S2,
    PIEZA_Z1,
    PIEZA_Z2,
    PIEZA_CUBO3,
    PIEZA_LINEA4H,
    PIEZA_LINEA4V,
    PIEZA_CRUZ,
    PIEZA_PUNTO,
    PIEZA_L,
    PIEZA_L1,
    PIEZA_L2,
    PIEZA_L3
} TipoPieza;

typedef struct {
  int mapa[9][9];
} Mapa;

typedef struct {
  Vector2 pos;
  Vector2 posInicial;
  TipoPieza tipo;
  Color color;
  int mapa[4][4];
  bool colocada; 
} Pieza;

void mostrarMapa();
void limpiarMapa();
void mostrarPieza(Pieza pieza);
int moverPieza(Pieza *pieza);
void encontrarColision(Pieza *pieza);
void resetPieza(Pieza *pieza);
void consolidarMapa();
void limpiarMapaInicial();
int piezaEntraMapa(Pieza pieza);
int piezaEntraCoord(Pieza pieza, int x, int y);
void analizarColumn();
void analizarFilas();

void generarPiezas();

void UpdateDrawFrame(void);
void consolidarPiezaEnMapa(Pieza *pieza);

#endif
