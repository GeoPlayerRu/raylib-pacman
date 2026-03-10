#include <raylib.h>
#include <cmath>
#include <raymath.h>

class Pacman {
	const int speed = 16;
	private:
		Texture2D texture;
		Vector2 position;
		int facing;

		Rectangle getTextureRect(){
			Rectangle result;
			result.x = 0;
			result.y = facing;
			result.height = 16;
			result.width = 16;
			return result;
		}
	public:
		Pacman() {
			this->texture = LoadTexture("assets/sprites/pacman.png");
			this->facing = 0;
		}
		~Pacman() {
			UnloadTexture(this->texture);
		}
		
		void process() {
			float delta = GetFrameTime();

			// Movement in direction
			double angle = PI/2.0*facing;
			Vector2 direction = {(float)(cos(angle)),(float)(sin(angle))};
			this->position = Vector2Add(this->position,Vector2Scale(direction, delta * (float)speed)); 
			
			DrawTextureRec(this->texture, this->getTextureRect(), this->position, WHITE);
		}
};

int main() {
	const int screen_height = 320;
	const int screen_width = 320;

	InitWindow(screen_width, screen_height, "Test game");

	SetTargetFPS(60);

	Pacman pacman;

	while (WindowShouldClose() == false) {
		BeginDrawing();
		
		pacman.process();

		EndDrawing();
	}

	return 0;
}
