#include "world.h"
#include "components.h"

World::World(){
	this->entities = new Entity[World::GRID_SIZE];
}

World::~World(){
		delete [] this->entities;
		delete [] this->processables;
		delete [] this->drawables;
	}

void World::setup(){
	this->processables_count = 0;		
	this->drawables_count = 0;

	IProcessable* temp_processables[World::GRID_SIZE];
	IDrawable* temp_drawables[World::GRID_SIZE];

	for(int i = 0; i < World::GRID_SIZE; i++) {
		// Get all processables and drawables as pointers to store later.
		IProcessable* processable = dynamic_cast<IProcessable*>(&this->entities[i]);
		IDrawable* drawable = dynamic_cast<IDrawable*>(&this->entities[i]);

		if (processable != nullptr) {
			temp_processables[this->processables_count] = processable;
			this->processables_count++;
		}
		if (drawable != nullptr) {
			temp_drawables[this->drawables_count] = drawable;
			this->drawables_count++;
		}
	}
	
	// Store processables and drawables
	this->processables = new IProcessable*[this->processables_count];
	this->drawables = new IDrawable*[this->drawables_count];

	for(int i = 0; i < this->processables_count; i++)
		this->processables[i] = temp_processables[i];
	for(int i = 0; i < this->drawables_count; i++)
		this->drawables[i] = temp_drawables[i];

	// Call ready on all readibles
	for(int i = 0; i < World::GRID_SIZE; i++)
	{
		IReadible* readible = dynamic_cast<IReadible*>(&this->entities[i]);
		if (readible != nullptr)
			readible->ready();
	}

}


