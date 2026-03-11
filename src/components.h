#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <raylib.h>
#include <raymath.h>

class Entity{
	public:
		virtual ~Entity(){}
		
		virtual void ready() {}
		virtual void process() {}
		virtual void draw() {}
		virtual void tick() {}
};


class Pacman : public Entity{
	const int speed = 16;
	private:
		Texture2D texture;
		Vector2 position;
		int facing;

		Rectangle getTextureRect();
	public:
		Pacman();
		Pacman(Vector2 position);
		~Pacman();
		void tick() override;
		void draw() override;
};

class Wall : public Entity {
	private:
		Texture2D texture;
	public:
		Wall();
		~Wall();
		void ready() override;
		void draw() override;
};

#endif
