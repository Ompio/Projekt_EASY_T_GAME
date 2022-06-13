#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "tile_b.h"
#include "functions.h"
class unit
{
	int entity_id;
	sf::Texture looks;
	int attack;
	int defense;
	int damage_min;
	int damage_max;
	int health_b;
	int health;
	int speed;
	int amount;
public:
	unit();
	unit(int id, int a, int o, int min, int max, int zd, int z, int s, std::string filename, int q);
	void fight(unit& enemy);
	void show_range(std::vector<std::vector<int> >& map);
	void move(std::vector<std::vector<int> >& map,coords x);
	sf::Texture shareTexture();
	texturesL pushToLoaded();
};

