#ifndef COLLISION_TILE_H
#define COLLISION_TILE_H

#include "raylib.h"
#include <stdbool.h>

bool CheckCollisionWithMap(Rectangle rect);
void DrawTileMap(Texture2D atlas);

#endif
