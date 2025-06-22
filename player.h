#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

#define SPEED 5
#define GRAVITY 1.0f
#define JUMP -20.0f

typedef struct Player {
    Texture2D texture;
    Vector2 position;
    Vector2 velocity;
    int width;
    int height;
    bool isJump;
    bool faceRight;
} Player;

extern Player player;

void InitPlayer();
void playerKB();
void playerCollision();
void DrawPlayer();

#endif
