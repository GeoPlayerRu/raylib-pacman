#include <fstream>
#include <iostream>
#include "components.h"
#include "world.h"

void load_world(World& world,const char* path) {
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
	
	world.height = CELL_SIZE * (max_y-1);
	world.width = CELL_SIZE * (max_x-1);
}

