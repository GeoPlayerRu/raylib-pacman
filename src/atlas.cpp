#include "atlas.h"
#include <raylib.h>

TextureAtlas::TextureAtlas(Texture2D* texture, int offset_x, int offset_y, int width, int height) {
	this->texture=texture;
	this->offset_x=offset_x;
	this->offset_y=offset_y;
	this->width=width;
	this->height=height;
}
TextureAtlas::TextureAtlas(){
	this->texture = nullptr;
	this->offset_x = 0;
	this->offset_y = 0;
	this->width = 0;
	this->height = 0;
}

Rectangle TextureAtlas::rect_view(int x, int y, int width, int height) const {
	return {
		(float)this->offset_x+x,
		(float)this->offset_y+y,
		(float)width,
		(float)height
	};	
}
Rectangle TextureAtlas::full_view() const {
	return {
		(float)this->offset_x,
		(float)this->offset_y,
		(float)this->width,
		(float)this->height
	};
}

const Texture2D TextureAtlas::get_texture() const {
	return *this->texture;
}
