#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class unit
{
	int unit_id;
	int attack;
	int defense;
	int damage_min;
	int damage_max;
	int health_b;
	int health;
	int speed;
	sf::Texture looks;
	int ;
public:
	unit();
	unit(int id, int a, int o, int min, int max, int zd, int z, int s, sf::Sprite l);
	void fight();
	void show_range(int& map);
	void move(int& map);
};

