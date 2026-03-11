#include "world.h"
#include <raylib.h>

World::World(){
	this->entities = {};
	this->seconds_per_tick = 0;
	this->clock = 0;
}

World::~World(){
	for(int i = 0; i < this->entities.size();i++) {
		delete this->entities[i];
	}
}

void World::setup(){
	for(int i = 0; i < this->entities.size(); i++)
		this->entities[i]->ready();
}

void World::process(){
	this->clock += GetFrameTime();

	this->update_grid();

	for(int i = 0; i < this->entities.size(); i++) {
		this->entities[i]->process();
		if (this->clock>=this->seconds_per_tick) {
			this->entities[i]->tick();
		}
	}

	if (this->clock>=this->seconds_per_tick) {
		this->clock = 0;
	}
}

void World::draw() const {
	for(int i = 0; i < this->entities.size(); i++) {
		this->entities[i]->draw();
	}
}

int indexify_position(Vector2 vector){
	return (int)(vector.x / 16.0) + GRID_COLUMNS * (int)(vector.y / 16.0);
}

void World::update_grid() {
	for(int i = 0; i < GRID_CAPACITY; i++)
		this->grid[i] = nullptr;
	
	for(int i = 0; i < this->entities.size(); i++)
	{
		int indexified_position = indexify_position(this->entities[i]->position);
		if (indexified_position < 0 || indexified_position >= GRID_CAPACITY)
			continue;
		grid[indexified_position] = this->entities[i];
	}
}



World create_world_with(float seconds_per_tick){
	World result = World();
	
	result.seconds_per_tick = seconds_per_tick;

	return result;
}
