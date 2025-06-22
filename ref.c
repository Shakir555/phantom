#include "raylib.h"
#include "player.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Phantom");
    SetTargetFPS(60);
    InitPlayer();

    // Define a 2D camera
    Camera2D camera = { 0 };
    camera.target = (Vector2){ player.position.x + player.width / 2, player.position.y + player.height / 2 };
    camera.offset = (Vector2){ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    while (!WindowShouldClose())
    {
        playerKB();
        playerCollision();

        // Update camera to follow player
        camera.target = (Vector2){ player.position.x + player.width / 2, player.position.y + player.height / 2 };

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode2D(camera);

        // Draw scrolling background and ground
        DrawRectangle(-10000, 400, 20000, 50, DARKGRAY); // Infinite ground

        DrawPlayer();

        EndMode2D();

        EndDrawing();
    }

    UnloadTexture(player.texture);
    CloseWindow();
    return 0;
}
