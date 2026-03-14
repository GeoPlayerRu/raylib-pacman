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
			case 'G':
				{
					Ghost* ghost = new Ghost;
					ghost->position = {(float)x*16,(float)y*16};
					world.entities.push_back(ghost);

				}
				x++;
				break;
			case '\n':
				
				x = 0;
				y++;
				break;
			case '-':
				{
					Portal* portal = new Portal;
					portal->position = {(float)x*16,(float)y*16};
					world.entities.push_back(portal);
				}
				x++;
				break;
			case '+':
				{
					Door* door = new Door;
					door->position = {(float)x*16,(float)y*16};
					world.entities.push_back(door);
				}
				x++;
				break;
			case ' ':
				{
					Scorepoint* point = new Scorepoint;
					point->position = {(float)x*16,(float)y*16};
					world.entities.push_back(point);
				}
				x++;

				break;
			case 'C':
				{
					Cherry* cherry = new Cherry;
					cherry->position = {(float)x*16,(float)y*16};
					world.entities.push_back(cherry);
				}
				x++;
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
