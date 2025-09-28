#include "mostrarPiezas.h"

Color colores[19] = {{ 244,  67,  54, 255 },  // rojo suave
{ 233,  30,  99, 255 },  // fucsia
{ 156,  39, 176, 255 },  // violeta
{ 103,  58, 183, 255 },  // violeta oscuro
{  63,  81, 181, 255 },  // azul
{  33, 150, 243, 255 },  // azul claro
{   3, 169, 244, 255 },  // celeste
{   0, 188, 212, 255 },  // turquesa
{   0, 150, 136, 255 },  // verde agua
{  76, 175,  80, 255 },  // verde
{ 139, 195,  74, 255 },  // verde lima
{ 205, 220,  57, 255 },  // lima amarillento
{ 255, 235,  59, 255 },  // amarillo
{ 255, 193,   7, 255 },  // ámbar
{ 255, 152,   0, 255 },  // naranja
{ 255,  87,  34, 255 },  // naranja fuerte
{ 121,  85,  72, 255 },  // marrón
{ 158, 158, 158, 255 },  // gris
{  96, 125, 139, 255 }};  // gris azulado
//
Pieza crearPieza(TipoPieza tipo, Vector2 pos){
    Pieza p = {0};
    p.tipo = tipo;
    p.pos = p.posInicial = pos;
    p.colocada = false;

    switch(tipo){
        case PIEZA_LINEA: {
            p.color = colores[rand() %19];
            int linea[4][4]={{0,0,0,0},
                             {1,1,1,0},
                             {0,0,0,0},
                             {0,0,0,0}};
            memcpy(p.mapa,linea,sizeof(linea));
        } break;

        case PIEZA_CUBO: {
            p.color = colores[rand() %19];
            int cubo[4][4]={{1,1,0,0},
                            {1,1,0,0},
                            {0,0,0,0},
                            {0,0,0,0}};
            memcpy(p.mapa,cubo,sizeof(cubo));
        } break;

        case PIEZA_COLUMNA: {
            p.color = colores[rand() %19];
            int colu[4][4]={{0,1,0,0},
                            {0,1,0,0},
                            {0,1,0,0},
                            {0,0,0,0}};
            memcpy(p.mapa,colu,sizeof(colu));
        } break;

        case PIEZA_TE: {
            p.color = colores[rand() %19];
            int te[4][4]={{0,1,0,0},
                          {1,1,1,0},
                          {0,0,0,0},
                          {0,0,0,0}};
            memcpy(p.mapa,te,sizeof(te));
        } break;

        case PIEZA_J1: {
            p.color = colores[rand() %19];
            int j[4][4]={{1,0,0,0},
                         {1,1,1,0},
                         {0,0,0,0},
                         {0,0,0,0}};
            memcpy(p.mapa,j,sizeof(j));
        } break;

        case PIEZA_J2: {
            p.color = colores[rand() %19];
            int j[4][4]={{0,0,0,0},
                         {1,1,1,0},
                         {1,0,0,0},
                         {0,0,0,0}};
            memcpy(p.mapa,j,sizeof(j));
        } break;

        case PIEZA_J3: {
            p.color = colores[rand() %19];
            int j[4][4]={{0,0,1,0},
                         {1,1,1,0},
                         {0,0,0,0},
                         {0,0,0,0}};
            memcpy(p.mapa,j,sizeof(j));
        } break;

        case PIEZA_J4: {
            p.color = colores[rand() %19];
            int j[4][4]={{0,0,0,0},
                         {1,1,1,0},
                         {0,0,1,0},
                         {0,0,0,0}};
            memcpy(p.mapa,j,sizeof(j));
        } break;
        case PIEZA_S1: {
            p.color = colores[rand() %19];
            int s[4][4]={{0,1,1,0},
                         {1,1,0,0},
                         {0,0,0,0},
                         {0,0,0,0}};
            memcpy(p.mapa,s,sizeof(s));
        } break;
        case PIEZA_S2: {
            p.color = colores[rand() %19];
            int s[4][4]={{1,0,0,0},
                         {1,1,0,0},
                         {0,1,0,0},
                         {0,0,0,0}};
            memcpy(p.mapa,s,sizeof(s));
        } break;

        case PIEZA_Z1: {
            p.color = colores[rand() %19];
            int z[4][4]={{1,1,0,0},
                         {0,1,1,0},
                         {0,0,0,0},
                         {0,0,0,0}};
            memcpy(p.mapa,z,sizeof(z));
        } break;
        case PIEZA_Z2: {
            p.color = colores[rand() %19];
            int z[4][4]={{0,1,0,0},
                         {1,1,0,0},
                         {1,0,0,0},
                         {0,0,0,0}};
            memcpy(p.mapa,z,sizeof(z));
        } break;

        case PIEZA_CUBO3: {
            p.color = colores[rand() %19];
            int cubo3[4][4]={{1,1,1,0},
                             {1,1,1,0},
                             {1,1,1,0},
                             {0,0,0,0}};
            memcpy(p.mapa,cubo3,sizeof(cubo3));
        } break;

        case PIEZA_LINEA4H: {
            p.color = colores[rand() %19];
            int l4h[4][4]={{1,1,1,1},
                           {0,0,0,0},
                           {0,0,0,0},
                           {0,0,0,0}};
            memcpy(p.mapa,l4h,sizeof(l4h));
        } break;

        case PIEZA_LINEA4V: {
            p.color = colores[rand() %19];
            int l4v[4][4]={{1,0,0,0},
                           {1,0,0,0},
                           {1,0,0,0},
                           {1,0,0,0}};
            memcpy(p.mapa,l4v,sizeof(l4v));
        } break;

        case PIEZA_CRUZ: {
            p.color = colores[rand() %19];
            int cruz[4][4]={{0,1,0,0},
                            {1,1,1,0},
                            {0,1,0,0},
                            {0,0,0,0}};
            memcpy(p.mapa,cruz,sizeof(cruz));
        } break;

        case PIEZA_PUNTO: {
            p.color = colores[rand() %19];
            int punto[4][4]={{0,0,0,0},
                             {0,1,0,0},
                             {0,0,0,0},
                             {0,0,0,0}};
            memcpy(p.mapa,punto,sizeof(punto));
        } break;
        case PIEZA_L: {
            p.color = colores[rand() %19];
            int punto[4][4]={{1,0,0,0},
                             {1,0,0,0},
                             {1,1,1,0},
                             {0,0,0,0}};
            memcpy(p.mapa,punto,sizeof(punto));
        } break;
        case PIEZA_L1: {
            p.color = colores[rand() %19];
            int punto[4][4]={{0,0,1,0},
                             {0,0,1,0},
                             {1,1,1,0},
                             {0,0,0,0}};
            memcpy(p.mapa,punto,sizeof(punto));
        } break;
        case PIEZA_L2: {
            p.color = colores[rand() %19];
            int punto[4][4]={{1,1,1,0},
                             {1,0,0,0},
                             {1,0,0,0},
                             {0,0,0,0}};
            memcpy(p.mapa,punto,sizeof(punto));
        } break;
        case PIEZA_L3: {
            p.color = colores[rand() %19];
            int punto[4][4]={{1,1,1,0},
                             {0,0,1,0},
                             {0,0,1,0},
                             {0,0,0,0}};
            memcpy(p.mapa,punto,sizeof(punto));
        } break;

        default: break;
    }

    return p;
}


// ---------- nuevas variables globales
Mapa mapa;
Pieza piezas[3]; // las 3 activas en pantalla
int enMovimiento = -1;
// función para generar 3 nuevas

void generarPiezas(){
    int flag = 1;
    while(flag){
        piezas[0] = crearPieza(rand()%CANT_PIEZAS, (Vector2){POS_FIRST, HEIGHT_PIEZAS});
        piezas[1] = crearPieza(rand()%CANT_PIEZAS, (Vector2){POS_SECOND, HEIGHT_PIEZAS});
        piezas[2] = crearPieza(rand()%CANT_PIEZAS, (Vector2){POS_THIRD, HEIGHT_PIEZAS});
        if(piezaEntraMapa(piezas[0]) && piezaEntraMapa(piezas[1]) && piezaEntraMapa(piezas[2])){
            flag = 0;
        }
    }
    
}
//
void UpdateDrawFrame(void) {
    analizarFilas();
    analizarColumn();
    
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        limpiarMapa();
        for(int i=0;i<3;i++){
            if(!piezas[i].colocada) {
                if(enMovimiento == -1 || enMovimiento == i){ 
                    if(moverPieza(&piezas[i])){
                       enMovimiento = i;
                    }
                }
            }
            encontrarColision(&piezas[i]);
        }
    } else {
        for(int i=0;i<3;i++){
            consolidarPiezaEnMapa(&piezas[i]);
            if(!piezas[i].colocada){
                resetPieza(&piezas[i]);
            }
        }
        enMovimiento = -1;
        // si las 3 están colocadas, generar nuevas
        if(piezas[0].colocada && piezas[1].colocada && piezas[2].colocada){
            generarPiezas();
        }
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    mostrarMapa();
    for(int i=0;i<3;i++) mostrarPieza(piezas[i]);
    EndDrawing();
}

void consolidarPiezaEnMapa(Pieza *pieza) {
    // Convertir posición de la pieza a coordenadas del mapa
    int filaBase = (int)((pieza->pos.y - 50) / 30);
    int coluBase = (int)((pieza->pos.x - POS_FIRST) / 30);

    for (int i = 0; i < 4; i++) {       // filas de la pieza
        for (int j = 0; j < 4; j++) {   // columnas de la pieza
            if (pieza->mapa[i][j] == 1) {
                int mapFila = filaBase + i;
                int mapColu = coluBase + j;

                // Validar límites del mapa
                if (mapFila >= 0 && mapFila < MAP_SIZE && mapColu >= 0 && mapColu < MAP_SIZE) {
                    if (mapa.mapa[mapFila][mapColu] == 1) {
                        mapa.mapa[mapFila][mapColu] = 2; // consolidar solo esta pieza
                        pieza->colocada = true; // marcar la pieza como colocada
                        pieza->pos.x = -10000;
                        pieza->pos.y = -10000;
                    }
                }
            }
        }
    }

}
int piezaEntraMapa(Pieza pieza){
    for(int i = 0; i<MAP_SIZE; i++){
        for(int j = 0;j<MAP_SIZE;j++){
            if(piezaEntraCoord(pieza, i, j)){
                return 1;
            }
        }
    }
    return 0;
}
int piezaEntraCoord(Pieza pieza, int x, int y) {
    // Recorremos la matriz 3x3 de la pieza
    for (int i = 0; i < 4; i++) {       // filas de la pieza
        for (int j = 0; j < 4; j++) {   // columnas de la pieza
            if (pieza.mapa[i][j] == 1) {
                int mapFila = x + i;
                int mapColu = y + j;

                // Validamos límites del mapa
                if (mapFila < 0 || mapFila >= MAP_SIZE || mapColu < 0 || mapColu >= MAP_SIZE)
                    return 0;

                // Si ya hay bloque consolidado
                if (mapa.mapa[mapFila][mapColu] == 2)
                    return 0;
            }
        }
    }
    return 1; // si ningún bloque colisiona, podemos colocar
}

void analizarColumn(){
  for(int i = 0; i<9; i++){
    int flag = 0;

    for(int j = 0; j<9 ; j++){
        if(mapa.mapa[j][i] != 2){
          flag = 1;
      }
    }
    if(flag==0){
      for(int j = 0; j<9 ; j++){
        mapa.mapa[j][i] = 0;
      }   
    }
  }
}
void analizarFilas(){
  for(int i = 0; i<9; i++){
    int flag = 0;

    for(int j = 0; j<9 ; j++){
        if(mapa.mapa[i][j] != 2){
          flag = 1;
      }
    }
    if(flag==0){
      for(int j = 0; j<9 ; j++){
        mapa.mapa[i][j] = 0;
      }   
    }
  }
}
void encontrarColision(Pieza *pieza) {
  // Convertir posición en coordenadas del mapa (columna/fila base)
  int colu = (int)((pieza->pos.x - POS_FIRST) / 30);
  int fila = (int)((pieza->pos.y - 50) / 30);

  // Recorremos la matriz 3x3 de la pieza
  //
  if(piezaEntraCoord(*pieza, fila, colu)){
    for (int i = 0; i < 4; i++) {     // filas de la pieza
      for (int j = 0; j < 4; j++) {   // columnas de la pieza
        if (pieza->mapa[i][j] == 1) { // si hay parte de la pieza
          int mapFila = fila + i;
          int mapColu = colu + j;
          // Validar que está dentro de los límites del mapa
          if (mapFila >= 0 && mapFila < 9 && mapColu >= 0 && mapColu < 9 && mapa.mapa[mapFila][mapColu] == 0){
              mapa.mapa[mapFila][mapColu] = 1;
          }
        }
      }
    }
  }
}
void resetPieza(Pieza *pieza){
  pieza->pos.x = pieza->posInicial.x;
  pieza->pos.y = pieza->posInicial.y;
  pieza->colocada = 0;
}
int moverPieza(Pieza *pieza) {
  if (GetMousePosition().x > pieza->pos.x - 10 &&
      GetMousePosition().x < pieza->pos.x + 30 * 3 + 10 &&
      GetMousePosition().y > pieza->pos.y - 10 &&
      GetMousePosition().y < pieza->pos.y + 30 * 3 + 10) {
    pieza->pos.x += GetMouseDelta().x;
    pieza->pos.y += GetMouseDelta().y;
    return 1;
  }else{pieza->pos.x = pieza->posInicial.x; pieza->pos.y = pieza->posInicial.y;return 0;}
}
void mostrarMapa() {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      if (mapa.mapa[i][j] == 0)
        DrawRectangle(POS_FIRST + j * 30, 50 + i * 30, 29, 29, GRAY);
      if (mapa.mapa[i][j] == 1)
        DrawRectangle(POS_FIRST + j * 30, 50 + i * 30, 29, 29, ORANGE);
      if (mapa.mapa[i][j] == 2)
        DrawRectangle(POS_FIRST + j * 30, 50 + i * 30, 29, 29, RED);
    }
  }
}

void limpiarMapaInicial() {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
       mapa.mapa[i][j] = 0;
    }
  }
}
void limpiarMapa() {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      if(mapa.mapa[i][j] == 1) mapa.mapa[i][j] = 0;
    }
  }
}

void mostrarPieza(Pieza pieza) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (pieza.mapa[i][j] == 1) {
        DrawRectangle(pieza.pos.x + j * 30, pieza.pos.y + i * 30, 29, 29, pieza.color);
      }
    }
  }
}
