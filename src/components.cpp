#include <raylib.h>
#include <raymath.h>
#include "components.h"

// Pacman definitions

Rectangle Pacman::getTextureRect(){
	Rectangle result;
	result.x = 0;
	result.y = facing*16;
	result.height = 16;
	result.width = 16;
	return result;
}
Pacman::Pacman() {
	this->texture = LoadTexture("assets/sprites/pacman.png");
	this->facing = 0;
	this->position = {0.,0.};
}
Pacman::Pacman(Vector2 position) {
	this->texture = LoadTexture("assets/sprites/pacman.png");
	this->facing = 0;
	this->position = position;
}
Pacman::~Pacman() {
	UnloadTexture(this->texture);
}
void Pacman::process() {
	float delta = GetFrameTime();
	
	// Input handling
	if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {this->facing=1;}
	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {this->facing=2;}
	if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {this->facing=3;}
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {this->facing=0;}

	// Movement in direction
	double angle = PI/2.0*facing;
	Vector2 direction = {(float)(cos(angle)),(float)(sin(-angle))};
	this->position = Vector2Add(this->position,Vector2Scale(direction, delta * (float)speed)); 
	}

void Pacman::draw() {
	// Drawing
	DrawTextureRec(this->texture, this->getTextureRect(), this->position, WHITE);
}

// Wall definitions

Wall::Wall() {
	this->texture = LoadTexture("assets/sprites/walls.png");
}

Wall::~Wall() {
	UnloadTexture(this->texture);	
}

void Wall::ready() {
	// Set neigbors depending on state
}

void Wall::draw() {
	// Draw based on neighbors
}


