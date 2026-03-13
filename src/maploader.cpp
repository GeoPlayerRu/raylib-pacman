#include <fstream>
#include "components.h"
#include "world.h"

void load_world(World& world,const char* path) {
	std::ifstream in;
	in.open(path);
	
	int x = 0;
	int y = 0;

	while(in.eof() == false)
	{
		char c;
		in.get(c);	

		switch (c) {

			case '#':
				{
					Wall* wall = new Wall;
					wall->position = {(float)x*16,(float)y*16};
					world.entities.push_back(wall);
					x++;
				}
				break;
			case 'P':
				{
					Pacman* pacman = new Pacman;
					pacman->position = {(float)x*16,(float)y*16};
					world.entities.push_back(pacman);
					x++;
				}
	
				break;
			case '\n':
				
				x = 0;
				y++;
				break;
			default:
				x++;
				break;
		}
		
		
	}
	
}

Vector2i get_map_size(const char* path){
	std::ifstream in;
	in.open(path);
	
	int x = 0;
	int y = 0;

	int max_x = 0;
	int max_y = 0;

	while(in.eof() == false)
	{
		char c;
		in.get(c);
		

		if (max_x < x)
			max_x = x;
		if (max_y < y)
			max_y = y;

		if(c == '\n'){			
			x = 0;
			y++;
		}
		else {
			x++;
		}
	}
	
	return {max_x * CELL_SIZE,max_y * CELL_SIZE};
}
