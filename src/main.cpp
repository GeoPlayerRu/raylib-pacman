#include <raylib.h>
#include <raymath.h>
#include "components.h"
#include "world.h"

int main() {
	const int screen_height = 320;
	const int screen_width = 320;

	InitWindow(screen_width, screen_height, "Test game");

	SetTargetFPS(60);
	
	world = create_world_with(1.0);
	
	world.entities.push_back(Pacman({screen_width/2,screen_height/2}));

	world.setup();

	while (WindowShouldClose() == false) {

		world.process();		

		BeginDrawing();

		ClearBackground(BLACK);
		
		DrawText(TextFormat("Entities: %i",world.entities.size()),0,0, 14,WHITE);
		world.draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
