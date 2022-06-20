#include "unit.h"
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
	damage_max=2000;
	damage_min=1000;
	health=10;
	health_b=1;
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

void unit::attack_M(std::vector<std::vector<int> >& map,coords x, std::vector<std::pair<bool,std::shared_ptr<unit>>>& loadedEntities)
{
	for (auto& entity : loadedEntities) {
		if (entity.second->get_coords() == x) {
			this->deal_damage(entity.second);
			std::cout << std::endl << " udalo sie zaatakowaæ jednostce " << entity_id << std::endl;
			break;
		}
	}
	
	//this->deal_damage(enemy);
}


void unit::deal_damage(std::shared_ptr<unit>& enemy)
{
	srand(time(NULL));
	int damage=0;
	for (int i = 0; i < amount; i++) {
		damage += rand() % (damage_max - damage_min) + damage_min;
	}
	enemy->modify_Hp(-damage);
	std::cout << std::endl << damage << " <- damage " << std::endl;
}

void unit::modify_Hp(int hp_value)
{
	health += hp_value;
	amount = ((health-1) / health_b)+1;
	std::cout <<"health :" << health <<" amount: " <<amount<< std::endl;
}

bool unit::check_living(std::vector<std::vector<int> >& map, std::vector<std::pair<bool, std::shared_ptr<unit>>>& loadedEntities)
{
	std::vector<std::pair<bool, std::shared_ptr<unit>>>::iterator it1 = loadedEntities.begin();;
	for (auto& entity : loadedEntities) {
		if (entity.second->entity_id == entity_id) {
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


void unit::show_range(std::vector<std::vector<int> >& map)
{
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

void unit::show_attack(std::vector<std::vector<int>>& map, std::vector<coords>& oponent_friend)
{
	for (auto& oponents : oponent_friend) {

		map[oponents.x][oponents.y] = 2;
	}

	
	/*for (int i = 1; i > 0; i--) {
		for (int j = 1; j >= 0; j--) {

			if (place.y + i < 11 && place.x + j < 15 && map[place.x + j][place.y + i] > 10) {
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
	}*/
}

bool unit::check_attack(std::vector<std::vector<int>>& map, bool orientation_m , std::vector<coords>& oponent_friend,std::vector<std::pair<bool, std::shared_ptr<unit>>>& loadedEntities)
{
	//bool orientation = orientation_m;
	oponent_friend.clear();
	//bool attack_possibility = false;
	coords oponent_location;

	for (int i = 1; i > 0; i--) {
		for (int j = 1; j >= 0; j--) {

			if (place.y + i < 11 && place.x + j < 15 && map[place.x + j][place.y + i] > 10 ){
				oponent_location.x = (place.x + j);
				oponent_location.y = (place.y + i);
				oponent_friend.push_back(oponent_location);
			}
			if (place.y - i >= 0 && place.x - j >= 0 && map[place.x - j][place.y - i] > 10) {
				oponent_location.x = (place.x - j);
				oponent_location.y = (place.y - i);
				oponent_friend.push_back(oponent_location);
			}
			if (place.x + i < 15 && place.y - j >= 0 && map[place.x + i][place.y - j] > 10) {
				oponent_location.x = (place.x + i);
				oponent_location.y = (place.y - j);
				oponent_friend.push_back(oponent_location);
			}
			if (place.x - i >= 0 && place.y + j < 11 && map[place.x - i][place.y + j] > 10) {
				oponent_location.x = (place.x - i);
				oponent_location.y = (place.y + j);
				oponent_friend.push_back(oponent_location);
			}
		}
	}
	if (oponent_friend.empty())return false;
	for (int i = 0; i < oponent_friend.size(); i++) {
		for (auto& entity : loadedEntities)
			if (!oponent_friend.empty() && oponent_friend[i] == entity.second->get_coords() && entity.first == orientation_m) {
				oponent_friend.erase(oponent_friend.begin() + i);
				i--;
				break;
			}
	}
	if (oponent_friend.empty())return false;
	return true;
}

void unit::move(std::vector<std::vector<int> >& map, coords x)
{
	map[place.x][place.y] = 0;
	map[x.x][x.y] = entity_id;
	place.x = x.x;
	place.y = x.y;
}

sf::Texture unit::get_texture()
{
	return sf::Texture(looks);
}

coords unit::get_coords()
{
	return place;
}

int unit::get_id()
{
	return entity_id;
}

int unit::get_speed()
{
	return speed;
}

int unit::get_hp()
{
	return health;
}

int unit::get_b_hp()
{
	return health_b;
}

int unit::get_quantity()
{
	return amount;
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
	return x;
}

unit::~unit()
{

}

