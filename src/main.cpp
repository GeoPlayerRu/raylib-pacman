#include <raylib.h>
#include <raymath.h>
#include "components.h"

int main() {
	const int screen_height = 320;
	const int screen_width = 320;

	InitWindow(screen_width, screen_height, "Test game");

	SetTargetFPS(60);

	Pacman pacman = Pacman(Vector2{screen_width/2.0,screen_height/2.0});

	while (WindowShouldClose() == false) {
		BeginDrawing();

		ClearBackground(BLACK);
		
		pacman.process();

		EndDrawing();
	}

	return 0;
}
