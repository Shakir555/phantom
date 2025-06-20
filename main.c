#include "raylib.h"
#include "player.h"

#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 600

int main()
{
    InitWindow(SCREEN_HEIGHT, SCREEN_WIDTH, "Phantom");
    SetTargetFPS(60);
    InitPlayer();
    while(!WindowShouldClose())
    {
        playerKB();
        playerCollision();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(0, 400, 2000, 50, DARKGRAY);
        DrawPlayer();
        EndDrawing();
    }
    UnloadTexture(player.texture);
    CloseWindow();
}