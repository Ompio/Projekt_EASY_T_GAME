#pragma once
#include "f_sfml.h"
class tile_b
{
	bool empty;
	int xcord;
	int ycord;
	sf::Sprite tile;
	sf::Texture battle_tile_null;
 public:
	tile_b();
	tile_b(bool b, int x, int y, sf::Sprite t);
	void show_tile(sf::RenderWindow& window);
};

