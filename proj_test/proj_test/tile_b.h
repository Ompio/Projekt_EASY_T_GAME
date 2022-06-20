#pragma once
import functions_m;
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
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
	sf::Font arial;
	sf::Text stats;
	struct interaction;
	bool was_pressed = false;
 public:
	tile_b();
	tile_b(bool b, int x, int y, sf::Texture t, sf::Font& font);
	tile_b(bool b, int x, int y, sf::Sprite t);
	void show_tile(sf::RenderWindow& window);
	void show_entity(sf::RenderWindow& window, sf::Texture entityTexture, sf::Color unit_color, int _b_hp, int _hp, int _quantity);
	void tile_properties(sf::RenderWindow& window, std::vector<std::vector<int> > map, coords& x);
	void check_interaction(sf::RenderWindow& window,coords& x);
};

