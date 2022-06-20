#include "shooter.h"

shooter::shooter() :unit()
{
}

shooter::shooter(int id, int a, int def, int min, int max, int zd, int z, int s, std::string filename, int q)
	: unit(id, a, def, min, max, zd, z, s, filename, q)
{
}

bool shooter::check_attack(std::vector<std::vector<int>>& map, bool orientation_m, std::vector<coords>& oponent_friend, std::vector<std::pair<bool, std::shared_ptr<unit>>>& loadedEntities)
{
	oponent_friend.clear();
	shooting_targets.clear();
	//bool attack_possibility = false;
	coords oponent_location;
	

	for (int i = 1; i > 0; i--) {
		for (int j = 1; j >= 0; j--) {

			if (place.y + i < 11 && place.x + j < 15 && map[place.x + j][place.y + i] > 10) {
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
	
	if (!oponent_friend.empty()) {
		for (int i = 0; i < oponent_friend.size(); i++) {
			for (auto& entity : loadedEntities)
				if (!oponent_friend.empty() && oponent_friend[i] == entity.second->get_coords() && entity.first == orientation_m) {
					oponent_friend.erase(oponent_friend.begin() + i);
					i--;
					break;
				}
		}
	}
	for (auto& entity : loadedEntities)
		if (!entity.first == orientation_m) {
			shooting_targets.push_back(entity.second->get_coords());
		}
	if (oponent_friend.empty()&&shooting_targets.empty())return false;
	return true;
}

void shooter::show_attack(std::vector<std::vector<int>>& map, std::vector<coords>& oponent_friend)
{
	for (auto& oponents : shooting_targets) {

		map[oponents.x][oponents.y] = 3;
	}
	for (auto& oponents : oponent_friend) {

		map[oponents.x][oponents.y] = 2;
	}

}

void shooter::attack_M(std::vector<std::vector<int>>& map, coords x, std::vector<std::pair<bool, std::shared_ptr<unit>>>& loadedEntities)
{
	for (auto& entity : loadedEntities) {
		if (entity.second->get_coords() == x) {
			for (auto& targets : shooting_targets) {
				if (entity.second->get_coords() == targets)
				{
					this->deal_ranged_damage(entity.second);
					std::cout << std::endl << " udalo sie zaatakowaæ jednostce " << entity_id << std::endl;
					break;
				}
				else { 
					this->deal_damage(entity.second); 
					std::cout << std::endl << " udalo sie zaatakowaæ jednostce " << entity_id << std::endl;
					break;
				}
				
			}
		}
	}
}

void shooter::deal_ranged_damage(std::shared_ptr<unit>& enemy)
{
	srand(time(NULL));
	int damage = 0;
	for (int i = 0; i < amount; i++) {
		damage += rand() % (damage_max - damage_min) + damage_min;
	}
	enemy->modify_Hp(-damage/2);
	std::cout << std::endl << damage/2 << " <- damage " << std::endl;
}
