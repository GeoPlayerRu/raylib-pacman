#include "components.h"

void Entity::queue_free() {
	if (this->free_queued)
		return;

	this->free_queued = true;
}

bool Entity::get_free_flag() {
	return this->free_queued;
}
