#include "Destroyer/Destroyer.h"

int main(void)
{
	printf("Hello, World\n");
	
	int rows = MX;
	int cols = MY;
	int **customMapFile = malloc(sizeof(int*) * rows);
	for (int i = 0; i < rows; i++) {
		customMapFile[i] = malloc(sizeof(int)*cols);
	}
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols/2; j++){
			customMapFile[i][j] = 0;
		}
	}
	for(int i = 0; i < rows; i++){
		for(int j = cols/2; j < cols; j++){
			customMapFile[i][j] = 1;
		}
	}
	
	MapFile *map = buildMapFile();
	Destroyer *destroyer = createDestroyer(50,50, 2);
	loadMap(map,customMapFile);
	
	// loadMap(map,);
	// printMap(map);
	InitWindow(1280,720,"raylib");
	SetTargetFPS(60);

	while(!WindowShouldClose()) {
		updateDestroyer(destroyer);
		BeginDrawing();
		ClearBackground(YELLOW);

		// drawMap(map);
		// DrawRectangle(50,50,TILESIZE,TILESIZE,RED);
		drawMap(map);
		drawDestroyer(destroyer);		

		destroy(destroyer,map);
		EndDrawing();
	}
	freeMapFile(map);
	return 0;
}
