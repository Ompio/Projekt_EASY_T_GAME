#pragma once
#include "f_sfml.h"
class tile_b
{
	bool empty;
	int xcord;
	int ycord;
	sf::Sprite tile;
	sf::Texture battle_tile_null;
	sf::FloatRect tile_box;
	struct interaction;
 public:
	tile_b();
	tile_b(bool b, int x, int y, sf::Sprite t);
	void show_tile(sf::RenderWindow& window);
	void check_interaction(sf::RenderWindow& window);
};

