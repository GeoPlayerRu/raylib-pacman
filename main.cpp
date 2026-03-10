#include <raylib.h>

int main() {
	const int screen_height = 720;
	const int screen_width = 1280;

	InitWindow(screen_width, screen_height, "Test game");

	SetTargetFPS(60);

	while (WindowShouldClose() == false) {
		BeginDrawing();
		
		ClearBackground(RAYWHITE);

		DrawText("Congrats to me, I created first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
	}

	return 0;
}
