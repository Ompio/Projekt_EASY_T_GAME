#pragma once
#include "functions.h"
class tile_b
{
	bool empty;
	int xcord;
	int ycord;
	sf::Sprite tile;
	sf::Sprite entity;
	sf::Texture battle_tile_null;
	sf::Texture battle_tile_basic;
	sf::FloatRect tile_box;
	struct interaction;
	bool was_pressed = false;
 public:
	tile_b();
	tile_b(bool b, int x, int y, sf::Texture t);
	void show_tile(sf::RenderWindow& window);
	void show_entity(sf::RenderWindow& window, sf::Texture entityTexture);
	void tile_properties(sf::RenderWindow& window, std::vector<std::vector<int> > map, coords& x);
	void check_interaction(sf::RenderWindow& window,coords& x);
};

