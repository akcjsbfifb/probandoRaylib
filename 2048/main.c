#include <ctype.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int mapa[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
#define MAP_X 300
#define MAP_Y 100
#define PIEZA_SIZE 50

void mostrarMapa();
void moverDerecha();
void moverIzquierda();
void moverUp();
void moverDown();
void agregarNuevaFicha();

Color getColor(int valor);
int main(){
	const int screenWidth = 800;
	const int screenHeight = 450;

	srand(time(NULL)); // Necesita #include <time.h>
	agregarNuevaFicha();
	agregarNuevaFicha();

	InitWindow(screenWidth, screenHeight, "2048");
	while(!WindowShouldClose()){
		if(IsKeyPressed(KEY_RIGHT)){
			moverDerecha();
			agregarNuevaFicha();
		}

		if(IsKeyPressed(KEY_LEFT)){
			moverIzquierda();
			agregarNuevaFicha();
		}

		if(IsKeyPressed(KEY_UP)){
			moverUp();
			agregarNuevaFicha();
		}

		if(IsKeyPressed(KEY_DOWN)){
			moverDown();
			agregarNuevaFicha();
		}
		BeginDrawing();
			ClearBackground(RAYWHITE);
			mostrarMapa();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}

void agregarNuevaFicha(){
    int vacios[16][2]; // hasta 16 posiciones vacías
    int count = 0;

    // Buscar casillas vacías
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(mapa[i][j] == 0){
                vacios[count][0] = i;
                vacios[count][1] = j;
                count++;
            }
        }
    }

    if(count > 0){
        int r = rand() % count; // elijo una posición vacía al azar
        mapa[vacios[r][0]][vacios[r][1]] = 2;
    }
}
void mostrarMapa(){
	for(int i = 0; i< 4;i++){
		for(int j = 0; j<4; j++){
			DrawRectangle(MAP_X+j*PIEZA_SIZE,MAP_Y+i*PIEZA_SIZE, PIEZA_SIZE, PIEZA_SIZE, getColor(mapa[i][j]));
		 if(mapa[i][j] != 0){
			char texto[5];
			sprintf(texto, "%d", mapa[i][j]);

			int tamano = 20; // tamaño de fuente
			int textWidth = MeasureText(texto, tamano);
			int textHeight = tamano;

			// Centrar el texto en la casilla
			int textX =  MAP_X+j*PIEZA_SIZE + (PIEZA_SIZE - textWidth)/2;
			int textY =  MAP_Y+ i*PIEZA_SIZE + (PIEZA_SIZE - textHeight)/2;

			Color colorTexto = (mapa[i][j] <= 4) ? BLACK : WHITE;
			DrawText(texto, textX, textY, tamano, colorTexto);
            }

		}	
	}
}

// ---- FUNCIONES AUXILIARES ----
void compactarFilaDerecha(int fila[4]){
    for(int k = 0; k < 3; k++){ // repetir varias veces para empujar todo
        for(int j = 2; j >= 0; j--){
            if(fila[j] != 0 && fila[j+1] == 0){
                fila[j+1] = fila[j];
                fila[j] = 0;
            }
        }
    }
}

void compactarFilaIzquierda(int fila[4]){
    for(int k = 0; k < 3; k++){
        for(int j = 1; j < 4; j++){
            if(fila[j] != 0 && fila[j-1] == 0){
                fila[j-1] = fila[j];
                fila[j] = 0;
            }
        }
    }
}

// ---- MOVIMIENTOS ----

void moverDerecha(){
    for(int i = 0; i < 4; i++){
        int fila[4];
        for(int j = 0; j < 4; j++) fila[j] = mapa[i][j];

        compactarFilaDerecha(fila);

        for(int j = 3; j > 0; j--){
            if(fila[j] != 0 && fila[j] == fila[j-1]){
                fila[j] *= 2;
                fila[j-1] = 0;
            }
        }

        compactarFilaDerecha(fila);

        for(int j = 0; j < 4; j++) mapa[i][j] = fila[j];
    }
}

void moverIzquierda(){
    for(int i = 0; i < 4; i++){
        int fila[4];
        for(int j = 0; j < 4; j++) fila[j] = mapa[i][j];

        compactarFilaIzquierda(fila);

        for(int j = 0; j < 3; j++){
            if(fila[j] != 0 && fila[j] == fila[j+1]){
                fila[j] *= 2;
                fila[j+1] = 0;
            }
        }

        compactarFilaIzquierda(fila);

        for(int j = 0; j < 4; j++) mapa[i][j] = fila[j];
    }
}

void moverUp(){
    for(int j = 0; j < 4; j++){
        int col[4];
        for(int i = 0; i < 4; i++) col[i] = mapa[i][j];

        compactarFilaIzquierda(col);

        for(int i = 0; i < 3; i++){
            if(col[i] != 0 && col[i] == col[i+1]){
                col[i] *= 2;
                col[i+1] = 0;
            }
        }

        compactarFilaIzquierda(col);

        for(int i = 0; i < 4; i++) mapa[i][j] = col[i];
    }
}

void moverDown(){
    for(int j = 0; j < 4; j++){
        int col[4];
        for(int i = 0; i < 4; i++) col[i] = mapa[i][j];

        compactarFilaDerecha(col);

        for(int i = 3; i > 0; i--){
            if(col[i] != 0 && col[i] == col[i-1]){
                col[i] *= 2;
                col[i-1] = 0;
            }
        }

        compactarFilaDerecha(col);

        for(int i = 0; i < 4; i++) mapa[i][j] = col[i];
    }
}
Color getColor(int valor){
    switch(valor){
        case 0: return (Color){ 205, 193, 180, 255 };   // Beige (fondo vacío)
        case 2: return (Color){ 238, 228, 218, 255 };   // Suave
        case 4: return (Color){ 237, 224, 200, 255 };   // Suave
        case 8: return (Color){ 242, 177, 121, 255 };   // Naranja amigable
        case 16: return (Color){ 245, 149, 99, 255 };   // Naranja más fuerte
        case 32: return (Color){ 246, 124, 95, 255 };   // Rojo suave
        case 64: return (Color){ 246, 94, 59, 255 };    // Rojo fuerte
        case 128: return (Color){ 237, 207, 114, 255 }; // Amarillo cálido
        case 256: return (Color){ 237, 204, 97, 255 };
        case 512: return (Color){ 237, 200, 80, 255 };
        case 1024: return (Color){ 237, 197, 63, 255 };
        case 2048: return (Color){ 237, 194, 46, 255 }; // Dorado feo
        default: return (Color){ 60, 58, 50, 255 };     // Oscuro para > 2048
    }
}
