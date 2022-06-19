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
	//constructors

	void attack_M(coords x, std::vector<std::pair<bool, std::shared_ptr<unit>>>& loadedEntities);
	void deal_damage(std::shared_ptr<unit>& enemy);
	void modify_Hp(int hp_value);
	bool check_living(std::vector<std::vector<int> >& map, std::vector<std::pair<bool, std::shared_ptr<unit>>>& loadedEntities);
	void show_range(std::vector<std::vector<int> >& map);
	void show_attack(std::vector<std::vector<int> >& map);
	bool check_attack(std::vector<std::vector<int> >& map);
	void move(std::vector<std::vector<int> >& map,coords x);

	sf::Texture get_texture();
	coords get_coords();
	int get_id();
	int get_speed();
	int get_hp();
	//getters

	void set_coords(coords place_in);
	//setters


	unit_coords pushToLoaded(std::vector<std::vector<int> >& map);
	~unit();
};

