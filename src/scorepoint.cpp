#include "components.h"
#include "world.h"
#include <raylib.h>

Scorepoint::Scorepoint(){
	this->texture = TextureAtlas(get_world().get_atlas(),112,0,16,16);
}

void Scorepoint::draw() const {
	DrawTextureRec(this->texture.get_texture(), this->texture.full_view(), this->position, WHITE);
}
