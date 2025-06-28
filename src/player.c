#include "player.h"
#include "collision.h"

Player player;

void InitPlayer()
{
    player.texture = LoadTexture("img/phantom_move.png");
    player.width = player.texture.width / 4;
    player.height = player.texture.height;
    player.position = (Vector2){ 100, 400 - player.height };
    player.velocity = (Vector2){ 0, 0 };
    player.isJump = false;
    player.faceRight = true;
    player.currentFrame = 0;
    player.frameCounter = 0;
    player.frameSpeed = 10;
}

void playerKB()
{
    bool moving = false;

    if (IsKeyDown(KEY_RIGHT)) {
        player.position.x += SPEED;
        player.faceRight = true;
        moving = true;
    }

    if (IsKeyDown(KEY_LEFT)) {
        player.position.x -= SPEED;
        player.faceRight = false;
        moving = true;
    }

    if (IsKeyPressed(KEY_SPACE) && !player.isJump) {
        player.velocity.y = JUMP;
        player.isJump = true;
    }

    if (moving) {
        player.frameCounter++;
        if (player.frameCounter >= (60 / player.frameSpeed)) {
            player.currentFrame = (player.currentFrame + 1) % 4;
            player.frameCounter = 0;
        }
    } else {
        player.currentFrame = 0;
        player.frameCounter = 0;
    }
}

void playerUpdate()
{
    player.velocity.y += GRAVITY;

    Vector2 nextPos = {
        player.position.x,
        player.position.y + player.velocity.y
    };

    Rectangle nextRect = {
        nextPos.x, nextPos.y,
        player.width, player.height
    };

    if (!CheckCollisionWithMap(nextRect)) {
        player.position.y = nextPos.y;
    } else {
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

    if (!player.faceRight) {
        sourceRec.width = -frameWidth;
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
