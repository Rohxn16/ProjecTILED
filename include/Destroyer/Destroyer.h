#include "BASE.h"
#include "MapSystem/MapBuilder.h"

typedef struct Destroyer {
    int x;
    int y;
    size_t radius;
    int** mapfileptr;
} Destroyer;

Destroyer* createDestroyer(int x, int y, int radius);
void destroy(Destroyer* destroyerInstance, MapFile* mapfile);
void drawDestroyer(Destroyer* destroyerInstance);
void updateDestroyer(Destroyer* destroyerInstance);
void destroyDestroyer(Destroyer* destroyerInstance);