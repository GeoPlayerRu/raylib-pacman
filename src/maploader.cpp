#include "maploader.h"
#include <fstream>
#include <iostream>
#include "components.h"
#include "world.h"

void loadmap(World& world) {
	std::ifstream in;
	in.open("assets/map");
	
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

