#include "components.h"
#include "world.h"

void Entity::queue_free() {
	if (this->free_queued)
		return;

	this->free_queued = true;
	World& world = get_world();

	for(int i = 0; i < world.entities.size(); i++)
		if(world.entities[i] == this) {
			delete world.entities[i];
			world.entities.erase(world.entities.begin()+i);
			break;
		}
}
