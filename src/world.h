#ifndef WORLD_H

#define WORLD_H

#include "components.h"
#include <string>
#include <vector>

const int GRID_ROWS = 20;
const int GRID_COLUMNS = 20;
const int GRID_CAPACITY = GRID_COLUMNS*GRID_ROWS;

/// Class that holds information about game world
class World {
	public:
		World();
		~World();
		bool debug;
		std::vector<Entity*> entities; /// Main subjects of game world.
		Entity* grid[GRID_CAPACITY];   /// Grid representation
		float seconds_per_tick; 	   /// Internal clock speed
		
		void setup();     /// Sets up game world. 
					      /// Should be called once when entites are set.

		void process();   /// Should be called every frame. Calls
						  /// process() on every entity

		void draw() const;	  /// Should be called at the end of frame.
						  /// Calls draw() on every entity	
	private:
		float clock;
		void update_grid();
};

void create_world_with(float seconds_per_tick);
World& get_world(); // Thanks, 2ndbeam, helps a lot
int indexify_position(Vector2 vector);

#endif
