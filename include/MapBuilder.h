#include "BASE.h"


typedef struct MapFile {
	int row;
	int col;
	int **mapdata;
} MapFile;



// release functions
MapFile* buildMapFile();			// builds the map file object and returns a pointer to it
void loadMap(MapFile* mapfile, int **arr);			// allows user to load their custom map
void freeMapFile(MapFile* mapfile);	// removes all reserved locations within mapfile from memory
void drawMap(MapFile* mapfile);		// function to render the map on screen

// debug functions
void printMap(MapFile* map);