#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <raylib.h>
#include <raymath.h>

class Entity{
	public:
		virtual ~Entity(){}
		
		Vector2 position;

		virtual void ready() {}
		virtual void process() {}
		virtual void draw() const {}
		virtual void tick() {}
};


class Pacman : public Entity{
	const int speed = 16;
	private:
		Texture2D texture;
		int facing;

		Rectangle getTextureRect() const;
	public:
		Pacman();
		Pacman(Vector2 position);
		~Pacman();
		void tick() override;
		void draw() const override;
};

class Wall : public Entity {
	private:
		Texture2D texture;
	public:
		Wall();
		~Wall();
		void ready() override;
		void draw() const override;
};

#endif
