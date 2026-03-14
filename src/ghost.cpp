#include "components.h"
#include "world.h"
#include <cstdlib>
#include <raylib.h>

unsigned int Ghost::color_decision = 0;

Ghost::Ghost() {
	this->texture = {get_world().get_atlas(),64,64,32,16};
	if (color_decision > 3)
		color_decision = 0;
	switch(this->color_decision++){
		case 0:
			this->color = ORANGE;
			break;
		case 1:
			this->color = PINK;
			break;
		case 2:
			this->color = RED;
			break;
		case 3:
			this->color = BLUE;
			break;
	}
}

void Ghost::ready() {
	this->start_position = position;
}

void Ghost::tick() {
	try_to_chase();
	Vector2 check_position = project_position(direction, 1);

	World& world = get_world();

	if(respawn_timer>0){
		respawn_timer--;
		return;
	}

	if(dynamic_cast<GhostWall*>(world.grid[world.indexify_position(check_position)]) != nullptr){
		recalculate_direction();
		check_position = project_position(direction, 1);
	}

	position = check_position;
}

void Ghost::try_to_chase(){
	// Todo
}

void Ghost::recalculate_direction(){
	World& world = get_world();

	switch (rand()%3) {
		case 0:
			direction = (direction+2)%4;
			break;
		case 1:
			if(dynamic_cast<GhostWall*>(world.grid[world.indexify_position(project_position((direction+1)%4, 1))]) == nullptr){
				direction = (direction+1)%4;
			}
			else if(dynamic_cast<GhostWall*>(world.grid[world.indexify_position(project_position((direction-1)%4,1))]) == nullptr){
				direction = (direction-1)%4;
			}
			else{
				direction = (direction-2)%4;
			}
			break;
		case 2:
			if(dynamic_cast<GhostWall*>(world.grid[world.indexify_position(project_position((direction-1)%4, 1))]) == nullptr){
				direction = (direction-1)%4;
			}
			else if(dynamic_cast<GhostWall*>(world.grid[world.indexify_position(project_position((direction+1)%4,1))]) == nullptr){
				direction = (direction+1)%4;
			}
			else{
				direction = (direction-2)%4;
			}
			break;
	}	
}

void Ghost::draw() const {
	if (get_world().get_killmode() == true || respawn_timer > 0)
		DrawTextureRec(texture.get_texture(), texture.rect_view(16, 0, 16, 16), position, WHITE);
	else
		DrawTextureRec(this->texture.get_texture(), this->texture.rect_view(0,0,16, 16), this->position, this->color);
}

void Ghost::collision(Entity* with) {
	Pacman* pacman = dynamic_cast<Pacman*>(with);
	if(pacman != nullptr)
	{
		if(get_world().get_killmode()){
			respawn_timer=respawn_time;
			position=start_position;
		} else{
			pacman->queue_free();
			get_world().lose();
		}
	}
}
