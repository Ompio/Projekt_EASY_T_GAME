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
	coords place;

public:
	unit();
	unit(int id, int a, int def, int min, int max, int zd, int z, int s, std::string filename, int q);
	void fight(unit& enemy);
	void attack_M(coords x, std::vector<unit_coords>& loadedEntities);
	void deal_damage(unit& enemy);
	void modify_Hp(int hp_value);
	bool check_living(std::vector<std::vector<int> >& map, std::vector<unit_coords>& loadedEntities);
	void show_range(std::vector<std::vector<int> >& map,std::vector<unit_coords>& loadedEntities);
	void show_attack(std::vector<std::vector<int> >& map, std::vector<unit_coords>& loadedEntities);
	void move(std::vector<std::vector<int> >& map,coords x, std::vector<unit_coords>& loadedEntities);
	sf::Texture get_texture();
	coords get_coords();
	void set_coords(coords place_in);
	unit_coords pushToLoaded(std::vector<std::vector<int> >& map);
	~unit();
};

