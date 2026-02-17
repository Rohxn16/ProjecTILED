#include <Tile.h>

Tile* createTile(int x, int y) {
	Tile* tile = malloc(sizeof(tile));
	tile->x = x;
	tile->y = y;
	return tile;
}