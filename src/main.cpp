#include <raylib.h>
#include <raymath.h>
#include "world.h"
#include "maploader.h"

const int SCREEN_HEIGHT = 320;
const int SCREEN_WIDTH = 320;

int main() {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Test game");

	SetTargetFPS(60);
	
	world = create_world_with(1./10.);
	
	loadmap(world);

	world.setup();

	while (WindowShouldClose() == false) {
		
		if(IsKeyPressed(KEY_F1))
			world.debug = !world.debug;

		world.process();		

		BeginDrawing();

		ClearBackground(BLACK);
		
		world.draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
