#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

#define GRAVITY 1.0f
#define JUMP -20.0f
#define SPEED 5.0f

typedef struct Player 
{
    Vector2 position;
    Vector2 velocity;
    float width;
    float height;
    bool isJump;
    Texture2D texture;
} Player;

extern Player player;

void InitPlayer();
void playerKB();
void playerCollision();
void DrawPlayer();

#endif