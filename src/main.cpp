#include <raylib.h>
#include <raymath.h>
#include "world.h"

int main() {	
	create_world_with(1./5.);
	
	World& world = get_world();
	Vector2i window_size = get_map_size("assets/map");
	
	InitWindow(window_size.x, window_size.y, "Zoomba");

	world.load_atlas();
	world.set_size(window_size);
	load_world(world,"assets/map");
	

	SetTargetFPS(60);
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
