#include "Map.h"

Map::Map(const std::string& thePlace) {
	_thePlace = thePlace;
	name = "Map";
}

void Map::Use() {
	std::cout << "Look at a map : " << _thePlace << " as description." << std::endl;
}