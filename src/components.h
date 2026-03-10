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

		Rectangle getTextureRect();
	public:
		Pacman();
		Pacman(Vector2 position);
		~Pacman();
		virtual void process();
};
