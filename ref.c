#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define GRAVITY 1.0f
#define JUMP_FORCE -20.0f
#define PLAYER_SPEED 5.0f

typedef struct Player {
    Vector2 position;
    Vector2 velocity;
    float width;
    float height;
    bool isJumping;
    Texture2D texture;
} Player;

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Side Scroller with Ghost Sprite");
    SetTargetFPS(60);

    // Load texture
    Texture2D ghostTexture = LoadTexture("phantom.png");

    Player player = {0};
    player.position = (Vector2){ 100, 300 };
    player.velocity = (Vector2){ 0, 0 };
    player.width = ghostTexture.width;
    player.height = ghostTexture.height;
    player.isJumping = false;
    player.texture = ghostTexture;

    Rectangle ground = { 0, 400, 2000, 50 };

    Camera2D camera = { 0 };
    camera.target = player.position;
    camera.offset = (Vector2){ SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    while (!WindowShouldClose())
    {
        // Input
        if (IsKeyDown(KEY_RIGHT)) player.position.x += PLAYER_SPEED;
        if (IsKeyDown(KEY_LEFT))  player.position.x -= PLAYER_SPEED;
        if (IsKeyPressed(KEY_SPACE) && !player.isJumping)
        {
            player.velocity.y = JUMP_FORCE;
            player.isJumping = true;
        }

        // Apply gravity
        player.velocity.y += GRAVITY;
        player.position.y += player.velocity.y;

        // Collision with ground
        Rectangle playerRect = { player.position.x, player.position.y, player.width, player.height };
        if (CheckCollisionRecs(playerRect, ground))
        {
            player.position.y = ground.y - player.height;
            player.velocity.y = 0;
            player.isJumping = false;
        }

        // Update camera
        camera.target = (Vector2){ player.position.x + player.width/2, SCREEN_HEIGHT/2 };

        // Draw
        BeginDrawing();
        ClearBackground(SKYBLUE);

        BeginMode2D(camera);

        DrawRectangleRec(ground, DARKGREEN);
        DrawTexture(player.texture, player.position.x, player.position.y, WHITE);

        EndMode2D();

        DrawText("Arrow keys to move, SPACE to jump", 10, 10, 20, BLACK);

        EndDrawing();
    }

    // Cleanup
    UnloadTexture(ghostTexture);
    CloseWindow();
    return 0;
}
