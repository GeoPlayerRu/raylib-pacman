#include "maploader.h"
#include <fstream>
#include <iostream>
#include "world.h"

void loadmap() {
	std::ifstream input_stream;
	input_stream.open("assets/map");

	if(input_stream.is_open() == false)
		return;

	std::cout << input_stream.getline()

	input_stream.close();
}

