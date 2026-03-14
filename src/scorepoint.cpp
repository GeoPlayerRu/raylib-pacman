#include "components.h"
#include "world.h"
#include <raylib.h>

Scorepoint::Scorepoint(){
	this->texture = TextureAtlas(get_world().get_atlas(),112,0,16,16);
}

void Scorepoint::draw() const {
	DrawTextureRec(this->texture.get_texture(), this->texture.full_view(), this->position, WHITE);
}

void Scorepoint::ready() {
	get_world().total_scorepoints++;
}

Cherry::Cherry(){
	texture = {get_world().get_atlas(),112,16,16,16};
}

void Cherry::draw() const {
	DrawTextureRec(texture.get_texture(),texture.full_view(),position,WHITE);
}

void Cherry::ready() {
	get_world().total_scorepoints++;
}
