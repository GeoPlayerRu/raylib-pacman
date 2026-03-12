#include "world.h"
#include "components.h"
#include <raylib.h>
#include <string>

World::World(){
	this->entities = {};
	this->seconds_per_tick = 0;
	this->clock = 0;
	this->debug = false;
	this->bound_offset = 1;
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

	if(IsKeyPressed(KEY_F2))
		this->seconds_per_tick-=0.025;
	if(IsKeyPressed(KEY_F3))
		this->seconds_per_tick+=0.025;

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
	if (this->debug == false)
		return;

	DrawText(TextFormat("entities: %i",this->entities.size()), 0, 0, 14, WHITE);
	DrawText(TextFormat("seconds_per_tick: %f",this->seconds_per_tick), 0, 16, 14, WHITE);
	if (IsKeyDown(KEY_F4))
	{
		std::string str = "";
		for(int i = 0; i < GRID_CAPACITY; i++)
		{
			if (i!=0 && i%GRID_COLUMNS==0)
			{
				str += '\n';
			}
			if (dynamic_cast<Wall*>(grid[i]))
					str += '#';
			else if (dynamic_cast<Pacman*>(grid[i]))
				str += 'P';
			else
				str += ' ';
		}
		DrawText(str.c_str(), 32, 0, 14, WHITE);
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

void World::set_size(Vector2i size){
	this->width = size.x;
	this->height = size.y; 
}

void create_world_with(float seconds_per_tick){
	get_world().seconds_per_tick = seconds_per_tick;
}

World& get_world() {
	static World world;
	return world;
}
