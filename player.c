#include "player.h"

Player player;

void InitPlayer()
{
    player.texture = LoadTexture("phantom.png");
    player.width = 64;               // Set player width
    player.height = 96;              // Set improved height
    player.position = (Vector2){ 0, 400 - player.height }; // Start on ground
    player.velocity = (Vector2){ 0, 0 };
    player.isJump = false;
    player.faceRight = true;
}

void playerKB()
{
    if (IsKeyDown(KEY_RIGHT))
    {
        player.position.x += SPEED;
        player.faceRight = true;
    }
    if (IsKeyDown(KEY_LEFT))
    {
        player.position.x -= SPEED;
        player.faceRight = false;
    }
    if (IsKeyPressed(KEY_SPACE) && !player.isJump)
    {
        player.velocity.y = JUMP;
        player.isJump = true;
    }
}

void playerCollision()
{
    Rectangle ground = { -10000, 400, 20000, 50 };  // Long scrolling ground

    player.velocity.y += GRAVITY;
    player.position.y += player.velocity.y;

    Rectangle playerRect = {
        player.position.x,
        player.position.y,
        player.width,
        player.height
    };

    if (CheckCollisionRecs(playerRect, ground))
    {
        player.position.y = ground.y - player.height;
        player.velocity.y = 0;
        player.isJump = false;
    }
}

void DrawPlayer()
{
    Rectangle sourceRec;
    if (player.faceRight)
    {
        sourceRec = (Rectangle){ 0.0f, 0.0f, (float)player.texture.width, (float)player.texture.height };
    }
    else
    {
        sourceRec = (Rectangle){ (float)player.texture.width, 0.0f, -(float)player.texture.width, (float)player.texture.height };
    }

    Rectangle destRec = {
        player.position.x,
        player.position.y,
        player.width,
        player.height
    };

    Vector2 origin = { 0, 0 };
    DrawTexturePro(player.texture, sourceRec, destRec, origin, 0.0f, WHITE);
}
