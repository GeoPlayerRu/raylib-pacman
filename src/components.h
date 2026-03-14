#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "atlas.h"
#include <raylib.h>
#include <raymath.h>

class Entity{
	protected:
		Vector2 project_position(int direction, int distance);
	public:
		virtual ~Entity(){}
		
		Vector2 position;

		virtual void ready() {}
		virtual void process() {}
		virtual void draw() const {}
		virtual void tick() {}
		virtual void collision(Entity* with) {}
		void queue_free();
		bool get_free_flag();
	private:
		bool free_queued = false;
};


class Pacman : public Entity{
	const int frame_count = 7;
	const int fps = 24;
	private:
		TextureAtlas texture;
		int facing = 0;
		Rectangle getTextureRect() const;
	public:
		unsigned char frame = 0.;
		float time = 0.; 

		Pacman();
		Pacman(Vector2 position);
		void tick() override;
		void process() override;
		void animation_tick();
		void draw() const override;
		void collision(Entity* with) override;
};

class PacmanWall{};
class GhostWall{};

class Wall : public Entity,public PacmanWall,public GhostWall{
	private:
		TextureAtlas texture;
	public:
		Wall();
		void ready() override;
		void draw() const override;
};

class Door : public Entity, public PacmanWall{};
class Portal : public Entity, public GhostWall{};

class Scorepoint : public Entity {
	private:
		TextureAtlas texture;
	public:
		Scorepoint();
		void draw() const override;
		void ready() override;
};

class Ghost : public Entity {
	const int respawn_time = 45;
	private:
		static unsigned int color_decision;
		TextureAtlas texture;
		Color color;
		int direction = 1;
		Vector2 start_position;
		int respawn_timer = 0;
		void recalculate_direction();
		void try_to_chase();
	public:
		Ghost();
		void ready() override;
		void tick() override;
		void draw() const override;
		void collision(Entity* with) override;
};

class Cherry : public Entity {
	private:
		TextureAtlas texture;
	public:
		Cherry();
		void draw() const override;
		void ready() override;
};

#endif
