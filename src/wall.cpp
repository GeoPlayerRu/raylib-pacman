#include "components.h"
#include "world.h"
#include <raylib.h>

Wall::Wall() {
	this->texture = TextureAtlas(get_world().get_atlas(),0,64,16,16);
}

void Wall::ready() {
	// Set neigbors depending on state
}

void Wall::draw() const {
	// Draw based on neighbors
	DrawTextureRec(this->texture.get_texture(), this->texture.full_view(), this->position, WHITE);
}
