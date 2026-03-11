#include <raylib.h>
#include <raymath.h>
#include "components.h"
#include "world.h"

const int SCREEN_HEIGHT = 320;
const int SCREEN_WIDTH = 320;

int main() {
	
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Test game");

	SetTargetFPS(60);
	
	world = create_world_with(.25);
	
	world.entities.push_back(new Pacman({SCREEN_WIDTH/2,SCREEN_HEIGHT/2}));

	world.setup();

	while (WindowShouldClose() == false) {

		world.process();		

		BeginDrawing();

		ClearBackground(BLACK);
		
		world.draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
