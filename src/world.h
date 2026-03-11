#ifndef WORLD_H
#define WORLD_H

#include "components.h"
#include <vector>

/// Class that holds information about game world
class World {
	public:
		World();
		~World();

		std::vector<Entity*> entities; /// Main subjects of game world.
		float seconds_per_tick; 	  /// Internal clock speed
		
		void setup();     /// Sets up game world. 
					      /// Should be called once when entites are set.

		void process();   /// Should be called every frame. Calls
						  /// process() on every entity

		void draw();	  /// Should be called at the end of frame.
						  /// Calls draw() on every entity	
	private:
		float clock;
};

static World world; /// World singleton

World create_world_with(float seconds_per_tick);

#endif
