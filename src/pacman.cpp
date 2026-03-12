#include <raylib.h>
#include <raymath.h>
#include "components.h"

// Pacman definitions


Rectangle Pacman::getTextureRect() const{
	Rectangle result;
	result.x = 16*frame;
	result.y = facing*16;
	result.height = 16;
	result.width = 16;
	return result;
}
Pacman::Pacman() {
	this->texture = LoadTexture("assets/sprites/pacman.png");
	this->facing = 0;
	this->position = {0.,0.};
	this->frame = 0;
}
Pacman::Pacman(Vector2 position) {
	this->texture = LoadTexture("assets/sprites/pacman.png");
	this->facing = 0;
	this->position = {0.,0.};
}
Pacman::~Pacman() {
	UnloadTexture(this->texture);
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
	this->position = Vector2Add(this->position,Vector2Scale(direction, (float)speed)); 

	// Bound check
	if (this->position.x < 0){
		this->position.x += 320;
	}
	if (this->position.y < 0){
		this->position.y += 320;
	}
	if (this->position.x >= 320){
		this->position.x -= 320;
	}
	if (this->position.y >= 320){
		this->position.y -= 320;
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
	DrawTextureRec(this->texture, this->getTextureRect(), this->position, WHITE);
}



