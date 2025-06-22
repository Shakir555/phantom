#include "player.h"

Player player;

void InitPlayer()
{
    player.texture = LoadTexture("phantom_idle.png");  // 4-frame sprite sheet
    player.width = player.texture.width / 4;
    player.height = player.texture.height;
    player.position = (Vector2){ 100, 400 - player.height };
    player.velocity = (Vector2){ 0, 0 };
    player.isJump = false;
    player.faceRight = true;
    player.currentFrame = 0;
    player.frameCounter = 0;
    player.frameSpeed = 10;  // frames per second
}

void playerKB()
{
    bool moving = false;

    if (IsKeyDown(KEY_RIGHT))
    {
        player.position.x += SPEED;
        player.faceRight = true;
        moving = true;
    }
    if (IsKeyDown(KEY_LEFT))
    {
        player.position.x -= SPEED;
        player.faceRight = false;
        moving = true;
    }

    if (IsKeyPressed(KEY_SPACE) && !player.isJump)
    {
        player.velocity.y = JUMP;
        player.isJump = true;
    }

    // Animate only when moving
    if (moving)
    {
        player.frameCounter++;
        if (player.frameCounter >= (60 / player.frameSpeed))
        {
            player.currentFrame++;
            if (player.currentFrame > 3) player.currentFrame = 0;
            player.frameCounter = 0;
        }
    }
    else
    {
        player.currentFrame = 0;
        player.frameCounter = 0;
    }
}

void playerUpdate()
{
    player.velocity.y += GRAVITY;
    player.position.y += player.velocity.y;

    float groundY = 400;

    if (player.position.y + player.height >= groundY)
    {
        player.position.y = groundY - player.height;
        player.velocity.y = 0;
        player.isJump = false;
    }
}

void DrawPlayer()
{
    float frameWidth = (float)(player.texture.width / 4);
    Rectangle sourceRec = {
        frameWidth * player.currentFrame,
        0.0f,
        frameWidth,
        (float)player.texture.height
    };

    if (!player.faceRight)
    {
        sourceRec.width = -frameWidth;  // Flip horizontally if facing left
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
