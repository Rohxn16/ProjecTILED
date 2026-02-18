#include "Destroyer/Destroyer.h"

Destroyer* createDestroyer(int x, int y, int radius) {
    Destroyer* destroyerInstance = malloc(sizeof(Destroyer));
    destroyerInstance->x = x;
    destroyerInstance->y = y;
    destroyerInstance->radius = radius;
    return destroyerInstance;
}

void drawDestroyer(Destroyer* destroyerInstance)
{
    DrawCircle(destroyerInstance->x, destroyerInstance->y, 10, GREEN);
}

void destroy(Destroyer* destroyerInstance, MapFile* mapfile)
{
    if (IsKeyPressed(KEY_SPACE)) {

        int tileX = destroyerInstance->x / TILESIZE;
        int tileY = destroyerInstance->y / TILESIZE;
        int radius = destroyerInstance->radius;

        // Compute clamped loop limits
        int startX = tileX - radius;
        int endX   = tileX + radius;

        int startY = tileY - radius;
        int endY   = tileY + radius;

        // Clamp to map boundaries
        if (startX < 0) startX = 0;
        if (startY < 0) startY = 0;
        if (endX >= mapfile->row) endX = mapfile->row - 1;
        if (endY >= mapfile->col) endY = mapfile->col - 1;

        for (int i = startX; i <= endX; i++) {
            for (int j = startY; j <= endY; j++) {
                mapfile->mapdata[i][j] = 0;
            }
        }
    }
}


void updateDestroyer(Destroyer* destroyerInstance) 
{
    if (IsKeyDown(KEY_A)) {
        destroyerInstance->x -= 20;
    }
    if (IsKeyDown(KEY_D)) {
        destroyerInstance->x += 5;
    }
    if (IsKeyDown(KEY_W)) {
        destroyerInstance->y -= 20;
    }
    if (IsKeyDown(KEY_S)) {
        destroyerInstance->y += 5;
    }
}

void destroyDestroyer(Destroyer* destroyerInstance) {
    free(destroyerInstance);
}