#include <stdint.h>
#include <stdlib.h>
#include "raylib.h"

#define PLAYER_HEIGHT 60
#define PLAYER_WIDTH 10
int main(void) {
    InitWindow(800, 450, "Mi primer juego en C con Raylib");


    Vector2 ballPosition = {GetScreenWidth()/2,GetScreenHeight()/2};

    float deltaVelocity = 0.4;
    Vector2 ballVelocity = {4, 2};
    Rectangle p1 = {.x = 0, .y = 30, .width = PLAYER_WIDTH, .height = PLAYER_HEIGHT};
    Rectangle p2 = {.x = GetScreenWidth()-PLAYER_WIDTH, .y = 30, .width = PLAYER_WIDTH, .height = PLAYER_HEIGHT};

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if(IsKeyDown(KEY_UP) && p1.y >0) p1.y -= 5; 
        if(IsKeyDown(KEY_DOWN) && p1.y < GetScreenHeight()-PLAYER_HEIGHT) p1.y += 5; 
        if(IsKeyDown(KEY_W) && p2.y >0) p2.y -= 5; 
        if(IsKeyDown(KEY_S) && p2.y < GetScreenHeight()-PLAYER_HEIGHT) p2.y += 5; 


        ballPosition.x = ballPosition.x + ballVelocity.x;
        ballPosition.y = ballPosition.y + ballVelocity.y;

        if(CheckCollisionCircleRec(ballPosition, 10, p2) || CheckCollisionCircleRec(ballPosition, 10, p1)){
            ballVelocity.x = ballVelocity.x +deltaVelocity;
            deltaVelocity = -deltaVelocity;
            ballVelocity.x = -ballVelocity.x;
        }
        if(ballPosition.y < 10 || ballPosition.y > GetScreenHeight()-10) ballVelocity.y = -ballVelocity.y;
        if(ballPosition.x <0 || ballPosition.x > GetScreenWidth()){ 
            ballPosition.x= GetScreenWidth()/2;
            ballPosition.y = GetScreenHeight()/2;
        }
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle(p1.x , p1.y,PLAYER_WIDTH, PLAYER_HEIGHT, BLACK);
            DrawRectangle(p2.x , p2.y,PLAYER_WIDTH, PLAYER_HEIGHT, BLACK);
            DrawCircle(ballPosition.x, ballPosition.y, 10, RED);
        EndDrawing();

    }

    CloseWindow();
    return 0;
}
