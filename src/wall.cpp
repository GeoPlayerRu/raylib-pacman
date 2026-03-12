#include "components.h"
#include <raylib.h>

Wall::Wall() {
	this->texture = LoadTexture("assets/sprites/wall.png");
}

Wall::~Wall() {
	UnloadTexture(this->texture);	
}

void Wall::ready() {
	// Set neigbors depending on state
}

void Wall::draw() const {
	// Draw based on neighbors
	DrawTexture(this->texture, this->position.x, this->position.y, WHITE);
}
