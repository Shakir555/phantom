#include "collision.h"

int tileMap[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
};

bool CheckCollisionWithMap(Rectangle rect)
{
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (tileMap[y][x] == 1) {
                Rectangle tile = {
                    x * TILE_SIZE,
                    y * TILE_SIZE,
                    TILE_SIZE,
                    TILE_SIZE
                };
                if (CheckCollisionRecs(rect, tile)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void DrawTileMap(Texture2D tileAtlas)
{
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (tileMap[y][x] == 1) {
                DrawTexture(tileAtlas, x * TILE_SIZE, y * TILE_SIZE, WHITE);
            }
        }
    }
}
