#ifndef WORLD_H

#define WORLD_H

#include "components.h"
#include <raylib.h>
#include <string>
#include <vector>

const int CELL_SIZE = 16;

struct Vector2i{
	int x;
	int y;
};

enum LevelState{
	NotFinished = 0,
	Won = 1,
	Lost = 2,
};

const int PACMAN_KILLTIME = 45;
/// Class that holds information about game world
class World {
	public:
		World();
		~World();
		bool debug = false;
		std::vector<Entity*> entities; /// Main subjects of game world.
		Entity** grid;   /// Grid representation
		float seconds_per_tick = 0.; 	   /// Internal clock speed
		int width = 0;
		int height = 0;
		int bound_offset = 1;

		void setup();     /// Sets up game world. 
					      /// Should be called once when entites are set.

		void process();   /// Should be called every frame. Calls
						  /// process() on every entity

		void draw() const;	  /// Should be called at the end of frame.
						  /// Calls draw() on every entity	
		void set_size(Vector2i);
		int get_capacity() const;
		int get_columns() const;
		int get_rows() const;
		void start_killmode();
		bool get_killmode();
		void load_atlas();
		void lose();
		void win();
		Texture2D* get_atlas();
		int indexify_position(Vector2 vector);
		int points = 0;
	private:
		float clock = 0.;
		int pacman_killmod_timer = 0;
		int state = 0;
		void update_grid();
		Texture2D texture_atlas;
};

void create_world_with(float seconds_per_tick);
void init_world();
World& get_world(); // Thanks, 2ndbeam, helps a lot
Vector2i get_map_size(const char* path);
void load_world(World& world, const char* path);

#endif
