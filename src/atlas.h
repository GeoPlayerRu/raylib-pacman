#ifndef ATLAS_H
#define ATLAS_H
#include <raylib.h>


class TextureAtlas {
	public:
		TextureAtlas(Texture2D* texture, int offset_x, int offset_y, int width, int height);
		TextureAtlas();
		Rectangle rect_view(int x,int y, int width, int height) const; // Get a view into texture	
		Rectangle full_view() const;
		const Texture2D get_texture() const;
	private:
		int offset_x = 0;
		int offset_y = 0;
		int width = 0;
		int height = 0;
		Texture2D* texture;
};

#endif
