#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "atlas.h"
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
		virtual void collision(Entity* with) {}
		void queue_free();
	private:
		bool free_queued;
};


class Pacman : public Entity{
	const int speed = 16;
	const int frame_count = 7;
	const int fps = 24;
	private:
		TextureAtlas texture;
		int facing;
		Rectangle getTextureRect() const;
	public:
		unsigned char frame;
		float time; 

		Pacman();
		Pacman(Vector2 position);
		void tick() override;
		void process() override;
		void animation_tick();
		void draw() const override;
		void collision(Entity* with) override;
};

class Wall : public Entity {
	private:
		TextureAtlas texture;
	public:
		Wall();
		void ready() override;
		void draw() const override;
};

class Scorepoint : public Entity {
	private:
		TextureAtlas texture;
	public:
		Scorepoint();
		void draw() const override;
};

#endif
