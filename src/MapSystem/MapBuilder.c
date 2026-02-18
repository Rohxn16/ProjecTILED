#include "MapSystem/MapBuilder.h"

// release
MapFile* buildMapFile()
{
	MapFile* mapfile = malloc(sizeof(MapFile));
	mapfile->row = MX;
	mapfile->col = MY;

	mapfile->mapdata = malloc(sizeof(int*) * mapfile->row);
	for (int i = 0; i < mapfile->row; i++) {
		mapfile->mapdata[i] = malloc(sizeof(int) * mapfile->col);
	}

	for(int i=0; i < mapfile->row; i++) {
		for (int j=0; j < mapfile->col; j++) {
			mapfile->mapdata[i][j] = 0;
		}
	}

	return mapfile;
}

void loadMap(MapFile* mapfile, int **arr)
{
	// this method needs some safety checks to be inserted later
	mapfile->mapdata = arr;
}

void freeMapFile(MapFile* mapfile) 
{
    for (int i = 0; i < mapfile->row; i++) {
        free(mapfile->mapdata[i]);
    }
    free(mapfile->mapdata);
    free(mapfile);
}

void drawMap(MapFile* mapfile) 
{

	int row = mapfile->row;
	int col = mapfile->col;
	for (int i = 0; i < row; i++) {
		int r = i;
		for (int j = 0; j < col; j++) {
			r += 2;
			Color color = {r, 100, 150, 255};
			if (mapfile->mapdata[i][j] == 1) 
				DrawRectangle(i*TILESIZE,j*TILESIZE,TILESIZE,TILESIZE,color);
		}
	}
}

// debug
void printMap(MapFile* map) 
{
	for (int i=0; i<map->row; i++) {
		printf("----------------\n");
		for (int j=0; j<map->col; j++) {
			printf("%d",map->mapdata[i][j]);
		}
		printf("-------------\n");
	}
}