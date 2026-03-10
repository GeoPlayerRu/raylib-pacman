#ifndef WORLD_H
#define WORLD_H

#include "components.h"

/// Class that holds information about game world
class World {
	public:
		const int GRID_SIZE = 20*20;
		World();
		~World();	
		Entity* entities; /// Main subjects of game world.
		
		void setup();     /// Sets up game world. 
					      /// Should be called once when entites are set.

		void process();   /// Should be called every frame. Calls
						  /// process() on every processable

		void draw();	  /// Should be called at the end of frame.
						  /// Calls draw() on every drawable
		
	private:
		IProcessable* processables;
		IDrawable* drawables;
};

static World world; /// World singleton

#endif
