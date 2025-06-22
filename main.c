#include "raylib.h"
#include "player.h"
#include "collision_tile.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Phantom");
    SetTargetFPS(60);

    Texture2D tileAtlas = LoadTexture("haunted_house_tile.png");
    InitPlayer();

    Camera2D camera = { 0 };
    camera.target = (Vector2){ player.position.x + player.width / 2, player.position.y + player.height / 2 };
    camera.offset = (Vector2){ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    while (!WindowShouldClose())
    {
        playerKB();         // Handle input
        playerUpdate();     // Update physics

        camera.target = (Vector2){ player.position.x + player.width / 2, player.position.y + player.height / 2 };

        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode2D(camera);

        DrawTileMap(tileAtlas);  // Draw background
        DrawPlayer();            // Draw character

        EndMode2D();

        // Debug info
        DrawText(TextFormat("X: %.2f  Y: %.2f  isJump: %s", player.position.x, player.position.y, player.isJump ? "true" : "false"), 10, 10, 20, WHITE);

        EndDrawing();
    }

    UnloadTexture(tileAtlas);
    UnloadTexture(player.texture);
    CloseWindow();
    return 0;
}
