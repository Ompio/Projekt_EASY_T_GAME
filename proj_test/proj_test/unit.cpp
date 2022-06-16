#include "unit.h"
#include "functions.h"
#include <cstdlib>

unit::unit()
{
	if (!looks.loadFromFile("BLOB.png"))
	{
		std::cout << "nie udalo sie otworzyc pliku";
	}
	entity_id=99;
	attack=10;
	defense=4;
	damage_max=20;
	damage_min=10;
	health=2000;
	health_b=100;
	speed=8;
	amount = 1;
}

unit::unit(int id, int a, int def, int min, int max, int zd, int z, int s, std::string filename, int q)
{
	if (!looks.loadFromFile(filename))
	{
		std::cout << "nie udalo sie otworzyc pliku";
	}
	entity_id = id;
	attack = a;
	defense = def;
	damage_max = min;
	damage_min = max;
	health = zd;
	health_b = z;
	speed = s;
	amount = q;
}

void unit::fight(unit& enemy)
{
	this->deal_damage(enemy);
}

void unit::attack_M(coords x, std::vector<unit_coords>& loadedEntities)
{
	coords place;
	for (auto& entity : loadedEntities) {
		if (entity.place==x) {
			//deal_damage(entity.entity);
			std::cout << std::endl << " uda³o sie zaatakowaæ " << std::endl;
		}
	}
	//this->deal_damage(enemy);
}


void unit::deal_damage(unit& enemy)
{
	srand(time(NULL));
	int damage=0;
	for (int i = 0; i < amount; i++) {
		damage += rand() % (damage_max - damage_min) + damage_min;
	}
	std::cout << std::endl << damage << " <- damage " << std::endl;
}

void unit::modify_Hp(int hp_value)
{
	health += hp_value;
	amount = ((health-1) / health_b)+1;
	std::cout <<"health :" << health <<" amount: " <<amount<< std::endl;
}

bool unit::check_living(std::vector<std::vector<int> >& map, std::vector<unit_coords>& loadedEntities)
{
	coords place;// = find_in_map(map, entity_id);
	place.x = -1;
	std::vector<unit_coords>::iterator it1 = loadedEntities.begin();;
	for (auto& entity : loadedEntities) {
		if (entity.entity_id == entity_id) {
			place = entity.place;
			break;
		}

		it1++;
	}

	if (place.x == -1) return false;
	else if (health <= 0) {
		map[place.x][place.y] = 0;
		loadedEntities.erase(it1);
		return false;
	}
	return true;
}


void unit::show_range(std::vector<std::vector<int> >& map, std::vector<unit_coords>& loadedEntities)
{
	coords place;// = find_in_map(map, entity_id);

	for (auto& entity : loadedEntities) {
		if (entity.entity_id == entity_id) {
			place = entity.place;
		}
	}

	int count = 0;
	for (int i = speed; i > 0; i-- ) {
		for (int j = count; j >= 0; j--) {

			if (place.y + i < 11 && place.x + j < 15 && map[place.x + j][place.y + i] == 0) {
					map[place.x + j][place.y + i] = 1;
			}
			if (place.y - i >= 0 && place.x - j >= 0 && map[place.x - j][place.y - i] == 0) {
					map[place.x - j][place.y - i] = 1;
			}
			if (place.x + i < 15 && place.y - j >= 0 && map[place.x + i][place.y - j] == 0) {
					map[place.x + i][place.y - j] = 1;
			}
			if (place.x - i >= 0 && place.y + j < 11 && map[place.x - i][place.y + j] == 0) {
				map[place.x - i][place.y + j] = 1;
			}
		}
		count++;
		std::cout << i << std::endl;
	}
}

void unit::show_attack(std::vector<std::vector<int>>& map, std::vector<unit_coords>& loadedEntities)
{
	coords place;// = find_in_map(map, entity_id);

	for (auto& entity : loadedEntities) {
		if (entity.entity_id == entity_id) {
			place = entity.place;
		}
	}
	for (int i = 1; i > 0; i--) {
		for (int j = 1; j >= 0; j--) {

			if (place.y + i < 11 && place.x + j < 15 && map[place.x + j][place.y + i] > 10 ){
				map[place.x + j][place.y + i] = 2;
			}
			if (place.y - i >= 0 && place.x - j >= 0 && map[place.x - j][place.y - i] > 10) {
				map[place.x - j][place.y - i] = 2;
			}
			if (place.x + i < 15 && place.y - j >= 0 && map[place.x + i][place.y - j] > 10) {
				map[place.x + i][place.y - j] = 2;
			}
			if (place.x - i >= 0 && place.y + j < 11 && map[place.x - i][place.y + j] > 10) {
				map[place.x - i][place.y + j] = 2;
			}
		}
	}
}



void unit::move(std::vector<std::vector<int> >& map, coords x, std::vector<unit_coords>& loadedEntities)
{
	coords place;
	for (auto& entity : loadedEntities) {
		if (entity.entity_id == entity_id) {
			place = entity.place;

			map[place.x][place.y] = 0;
			map[x.x][x.y] = entity_id;
			entity.place.x = x.x;
			entity.place.y = x.y;
		}
	}
}

sf::Texture unit::get_texture()
{
	return sf::Texture(looks);
}

coords unit::get_coords()
{
	return place;
}

void unit::set_coords(coords place_in)
{
	place = place_in;
}

unit_coords unit::pushToLoaded(std::vector<std::vector<int> >& map)
{
	coords ZERO = find_in_map(map, entity_id);
	unit_coords x;
	x.entity_id = entity_id;
	x.texture = looks;
	x.place = ZERO;
	//x.entity = *this;
	return x;
}

unit::~unit()
{

}

