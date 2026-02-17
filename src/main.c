#include "BASE.h"
#include "raylib.h"
#include "MapBuilder.h"

int main(void)
{
	printf("Hello, World\n");
	InitWindow(1280,720,"raylib");

	int rows = MX;
	int cols = MY;
	int **customMapFile = malloc(sizeof(int*) * rows);
	for (int i = 0; i < rows; i++) {
		customMapFile[i] = malloc(sizeof(int)*cols);
	}
	for(int i = 0; i < rows; i++){
		for(int j = cols/2; j < cols; j++){
			customMapFile[i][j] = 1;
		}
	}

	MapFile *map = buildMapFile();
	loadMap(map,customMapFile);

	// loadMap(map,);
	printMap(map);

	while(!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		// drawMap(map);
		DrawRectangle(50,50,TILESIZE,TILESIZE,RED);
		drawMap(map);

		EndDrawing();
	}
	freeMapFile(map);
	return 0;
}
