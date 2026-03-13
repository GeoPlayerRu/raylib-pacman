#include <raylib.h>
#include <raymath.h>
#include "atlas.h"
#include "components.h"
#include "world.h"

// Pacman definitions


Rectangle Pacman::getTextureRect() const{
	return this->texture.rect_view(16*frame, facing*16, 16, 16);
	}
Pacman::Pacman() {
	this->texture = TextureAtlas(get_world().get_atlas(),0,0,112,64);
	this->facing = 0;
	this->position = {0.,0.};
	this->frame = 0;
	this->time = 0;
}
Pacman::Pacman(Vector2 position) {
	this->texture = TextureAtlas(get_world().get_atlas(),0,0,112,64);
	this->facing = 0;
	this->position = {0.,0.};
}

void Pacman::tick() {
	// Input handling
	if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {this->facing=1;}
	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {this->facing=2;}
	if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {this->facing=3;}
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {this->facing=0;}

	// Movement in direction
	double angle = PI/2.0*facing;
	Vector2 direction = {(float)(cos(angle)),(float)(sin(-angle))};
	Vector2 new_position = Vector2Add(this->position,Vector2Scale(direction, (float)speed)); 
	
	World& world = get_world();

	if (dynamic_cast<Wall*>(world.grid[indexify_position(new_position)]) == nullptr){
		this->position=new_position;
	}
	
	// Bound check
	if (this->position.x < world.bound_offset*CELL_SIZE){
		this->position.x += world.width-2*world.bound_offset*CELL_SIZE;
	}
	if (this->position.y < world.bound_offset*CELL_SIZE){
		this->position.y += world.height-2*world.bound_offset*CELL_SIZE;
	}
	if (this->position.x >= world.width-world.bound_offset*CELL_SIZE){
		this->position.x -= world.width-2*world.bound_offset*CELL_SIZE;
	}
	if (this->position.y >= world.height-world.bound_offset*CELL_SIZE){
		this->position.y -= world.height-2*world.bound_offset*CELL_SIZE;
	}
}

void Pacman::process() {
	this->time += GetFrameTime();
	if (this->time >= 1.0/this->fps){
		this->time = 0.;
		this->animation_tick();
	}
}

void Pacman::animation_tick() {
	this->frame = (this->frame+1)%frame_count;
}

void Pacman::draw() const {
	// Drawing
	DrawTextureRec(this->texture.get_texture(), this->getTextureRect(), this->position, WHITE);
}

void Pacman::collision(Entity* with){
	Scorepoint* score = dynamic_cast<Scorepoint*>(with);
	if (score != nullptr) {
		score->queue_free();
	}

}


