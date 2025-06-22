#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

#define SPEED 4
#define JUMP -10
#define GRAVITY 0.5f

typedef struct Player {
    Texture2D texture;
    Vector2 position;
    Vector2 velocity;
    int width;
    int height;
    bool isJump;
    bool faceRight;
    int currentFrame;
    int frameCounter;
    int frameSpeed;
} Player;

extern Player player;

void InitPlayer();
void playerKB();
void playerUpdate();
void DrawPlayer();

#endif
