#include "components.h"
#include "world.h"

void Entity::queue_free() {
	if (this->free_queued)
		return;

	this->free_queued = true;
}

bool Entity::get_free_flag() {
	return this->free_queued;
}

Vector2 Entity::project_position(int direction, int distance) {
	double angle = PI/2.0*direction;
	Vector2 vector_direction = {(float)(cos(angle)),(float)(sin(-angle))};
	return Vector2Add(this->position,Vector2Scale(vector_direction, (float)distance*CELL_SIZE)); 

}
