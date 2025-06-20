#include "player.h"

Player player;

void InitPlayer()
{
    player.texture = LoadTexture("phantom.png");
    player.position = (Vector2){100, 300};
    player.velocity = (Vector2){0, 0};
    player.width = player.texture.width;
    player.height = player.texture.height;
    player.isJump = false;
}

void playerKB()
{
    if (IsKeyDown(KEY_RIGHT))
    {
        player.position.x += SPEED;
    }
    if (IsKeyDown(KEY_LEFT))
    {
        player.position.x -= SPEED;
    }
    if (IsKeyPressed(KEY_SPACE) && !player.isJump)
    {
        player.velocity.y = JUMP;
        player.isJump = true;
    }
}

void playerCollision()
{
    Rectangle ground = {0, 400, 2000, 50};
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
        player.position.y = ground.y -player.height;
        player.velocity.y = 0;
        player.isJump = false;
    }
}

void DrawPlayer()
{
    DrawTexture(player.texture, player.position.x,
                player.position.y, WHITE);
}