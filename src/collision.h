#ifndef COLLISION_H
#define COLLISION_H

#include "raylib.h"

#define TILE_SIZE 100
#define MAP_WIDTH 8
#define MAP_HEIGHT 6

extern int tileMap[MAP_HEIGHT][MAP_WIDTH];

bool CheckCollisionWithMap(Rectangle rect);
void DrawTileMap(Texture2D tileAtlas);

#endif
