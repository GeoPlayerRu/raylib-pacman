#include "world.h"
#include "components.h"
#include <cstdlib>
#include <raylib.h>
#include <string>

void init_world() {
	create_world_with(1./5.);
	
	World& world = get_world();
	Vector2i window_size = get_map_size("assets/map");
	
	world.load_atlas();
	world.set_size(window_size);
	load_world(world,"assets/map");

	world.setup();
}

World::World(){
	this->entities = {};
	this->grid = new Entity*[get_capacity()];
	this->seconds_per_tick = 0;
	this->clock = 0;
	this->debug = false;
	this->bound_offset = 1;
}

World::~World(){
	for(int i = 0; i < this->entities.size();i++) {
		delete this->entities[i];
	}
	UnloadTexture(this->texture_atlas);
}

void World::load_atlas() {	
	this->texture_atlas = LoadTexture("assets/atlas.png");
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
	
	if(state != LevelState::NotFinished){
		if(IsKeyPressed(KEY_Q))
			CloseWindow();
		if(IsKeyPressed(KEY_R))
			init_world();
		return;
	}

	this->update_grid();

	for(int i = 0; i < this->entities.size(); i++) {
		this->entities[i]->process();
		if (this->clock>=this->seconds_per_tick) {
			this->entities[i]->tick();
		}

		// Collision check
		for(int j = i+1; j < this->entities.size(); j++)
			if (abs(this->entities[j]->position.x-this->entities[i]->position.x) < CELL_SIZE/2 && abs(this->entities[j]->position.y-this->entities[i]->position.y) < CELL_SIZE/2){
				this->entities[j]->collision(this->entities[i]);
				this->entities[i]->collision(this->entities[j]);
			}
	}

	if (this->clock>=this->seconds_per_tick) {
		this->clock = 0;
	}
	
	// Check for freed. Very very bad loop
	bool freed_continue = true;
	while (freed_continue) {
		freed_continue = false;

		for(int i = 0; i < this->entities.size(); i++)
			if (this->entities[i]->get_free_flag()) {
				this->entities.erase(this->entities.begin()+i);
				freed_continue = true;
				break;
			}
	}
}

void World::draw() const {
	for(int i = 0; i < this->entities.size(); i++) {
		this->entities[i]->draw();
	}

	if(state != LevelState::NotFinished) {
		if(state == LevelState::Won)
		{
			DrawText("You won!", 16, 16, 24, WHITE);
		}
		else {
			DrawText("You lost!",16,16,24,WHITE);
		}
		DrawText("q to quit, r to restart",0,40,16,WHITE);
		DrawText(TextFormat("Score: %i",this->points),16,56,16,WHITE);

	}


	if (this->debug == false)
		return;

	DrawText(TextFormat("entities: %i",this->entities.size()), 0, 0, 14, WHITE);
	DrawText(TextFormat("seconds_per_tick: %f",this->seconds_per_tick), 0, 16, 14, WHITE);
	if (IsKeyDown(KEY_F4))
	{
		std::string str = "";
		for(int i = 0; i < this->get_capacity(); i++)
		{
			if (i!=0 && i%this->get_columns()==0)
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


int World::indexify_position(Vector2 vector){
	return (int)(vector.x / 16.0) + this->get_columns() * (int)(vector.y / 16.0);
}

void World::update_grid() {
	for(int i = 0; i < this->get_capacity(); i++)
		this->grid[i] = nullptr;
	
	for(int i = 0; i < this->entities.size(); i++)
	{
		int indexified_position = indexify_position(this->entities[i]->position);
		if (indexified_position < 0 || indexified_position >= this->get_capacity())
			continue;
		grid[indexified_position] = this->entities[i];
	}
}

void World::set_size(Vector2i size){
	this->width = size.x;
	this->height = size.y; 
	if(this->grid != nullptr)
		delete [] grid;
	this->grid = new Entity*[this->get_capacity()];
}

int World::get_capacity() const{
	return this->get_columns()*this->get_rows();
}

int World::get_rows() const{
	return this->height/CELL_SIZE;
}

int World::get_columns() const{
	return this->width/CELL_SIZE;
}

void World::lose(){
	state = LevelState::Lost;
}

void World::win(){
	state = LevelState::Won;
}

Texture2D* World::get_atlas() {
	return &this->texture_atlas;
}

void create_world_with(float seconds_per_tick){
	get_world() = World();
	get_world().seconds_per_tick = seconds_per_tick;
}

World& get_world() {
	static World world;
	return world;
}


