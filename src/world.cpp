#include "world.h"
#include <raylib.h>

World::World(){
	this->entities = {};
	this->seconds_per_tick = 0;
	this->clock = 0;
}

void World::setup(){
	for(int i = 0; i < this->entities.size(); i++)
		this->entities[i].ready();
}

void World::process(){
	this->clock += GetFrameTime();

	for(int i = 0; i < this->entities.size(); i++) {
		this->entities[i].process();
		if (this->clock>=this->seconds_per_tick) {
			this->entities[i].tick();
		}
	}

	if (this->clock>=this->seconds_per_tick) {
		this->clock = 0;
	}
}

void World::draw() {
	for(int i = 0; i< this->entities.size(); i++) {
		this->entities[i].draw();
	}
}

World create_world_with(float seconds_per_tick){
	World result = World();
	
	result.seconds_per_tick = seconds_per_tick;

	return result;
}
