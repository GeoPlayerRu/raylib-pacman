#include <raylib.h>
#include <raymath.h>

class IComponent {
	public:
		virtual ~IComponent() {}
		virtual void process() = 0;
};

class Pacman : IComponent {
	const int speed = 64;
	private:
		Texture2D texture;
		Vector2 position;
		int facing;

		Rectangle getTextureRect(){
			Rectangle result;
			result.x = 0;
			result.y = facing*16;
			result.height = 16;
			result.width = 16;
			return result;
		}
	public:
		Pacman() {
			this->texture = LoadTexture("assets/sprites/pacman.png");
			this->facing = 0;
			this->position = {0.,0.};
		}
		Pacman(Vector2 position) {
			this->texture = LoadTexture("assets/sprites/pacman.png");
			this->facing = 0;
			this->position = position;
		}
		~Pacman() {
			UnloadTexture(this->texture);
		}
		virtual void process() {
			float delta = GetFrameTime();
			
			// Input handling
			if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {this->facing=1;}
			if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {this->facing=2;}
			if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {this->facing=3;}
			if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {this->facing=0;}

			// Movement in direction
			double angle = PI/2.0*facing;
			Vector2 direction = {(float)(cos(angle)),(float)(sin(-angle))};
			this->position = Vector2Add(this->position,Vector2Scale(direction, delta * (float)speed)); 
			
			// Drawing
			DrawTextureRec(this->texture, this->getTextureRect(), this->position, WHITE);
		}
};
