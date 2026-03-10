#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <raylib.h>
#include <raymath.h>

class IProcessable {
	public:
		virtual ~IProcessable() {}	
		// Called every frame
		virtual void process() = 0;
};
class IReadible {
	public:
		virtual ~IReadible() {}	
		// Called when the level is set up
		virtual void ready() = 0;
};

class IDrawable {
	public:
		virtual ~IDrawable() {}	
		virtual void draw() = 0;
};

class Pacman : public IProcessable, public IDrawable {
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
		virtual void draw();
};

class Wall : public IReadible, public IDrawable {
	private:
		Texture2D texture;
	public:
		Wall();
		~Wall();
		virtual void ready();
		virtual void draw();
};

#endif
