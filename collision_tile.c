// collision_tile.c
#include "raylib.h"
#include <stdbool.h>

#define TILE_SIZE 64
#define MAP_WIDTH  10
#define MAP_HEIGHT 10

// 1 = solid tile, 0 = walkable
int collisionMap[MAP_HEIGHT][MAP_WIDTH] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,1,0,0,1,0,0,1},
    {1,0,0,1,0,0,1,0,0,1},
    {1,0,0,1,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,0,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

bool CheckCollisionWithMap(Rectangle rect)
{
    int startCol = (int)(rect.x / TILE_SIZE);
    int endCol   = (int)((rect.x + rect.width) / TILE_SIZE);
    int startRow = (int)(rect.y / TILE_SIZE);
    int endRow   = (int)((rect.y + rect.height) / TILE_SIZE);

    for (int row = startRow; row <= endRow; row++) {
        for (int col = startCol; col <= endCol; col++) {
            if (row >= 0 && row < MAP_HEIGHT && col >= 0 && col < MAP_WIDTH) {
                if (collisionMap[row][col] == 1) {
                    return true; // Collision detected
                }
            }
        }
    }
    return false;
}

void DrawTileMap(Texture2D atlas) {
    Rectangle src = { 0, 0, TILE_SIZE, TILE_SIZE }; // First tile in atlas
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            Vector2 pos = { x * TILE_SIZE, y * TILE_SIZE };
            DrawTextureRec(atlas, src, pos, WHITE);
        }
    }
}
