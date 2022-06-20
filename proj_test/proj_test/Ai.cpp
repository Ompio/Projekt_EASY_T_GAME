#include "Ai.h"

Ai::Ai()
{
	enemy_focus = 0;
}

void Ai::find_enemy(std::vector<std::pair<bool, std::shared_ptr<unit>>>& loadedEntities)
{
	int min_hp=999999999;
	for (int i = 0; i < loadedEntities.size(); i++) {
		if (loadedEntities[i].first) {
			if (loadedEntities[i].second->get_hp() < min_hp) {
				min_hp = loadedEntities[i].second->get_hp();
				enemy_focus = i;
			}
		}
	}
}

coords Ai::seek_enemy(int seeker_m, std::vector<std::vector<int>>& map, std::vector<std::pair<bool, std::shared_ptr<unit>>>& loadedEntities)
{
	
	coords target = loadedEntities[enemy_focus].second->get_coords();
	coords seeker = loadedEntities[seeker_m].second->get_coords();
	coords move_location;
	bool attack_capable = false;

	for (int i = 1; i > 0; i--) {
		for (int j = 1; j >= 0; j--) {

			if (target.y + i < 11 && target.x + j < 15 && map[target.x + j][target.y + i] == 1) {
				move_location.x = (target.x + j);
				move_location.y	= (target.y + i);
				attack_capable = true;
				return move_location;
			}

			if (target.y - i >= 0 && target.x - j >= 0 && map[target.x - j][target.y - i] == 1) {
				move_location.x = (target.x - j);
				move_location.y = (target.y - i);
				attack_capable = true;
				return move_location;
			}

			if (target.x + i < 15 && target.y - j >= 0 && map[target.x + i][target.y - j] == 1) {
				move_location.x = (target.x + i);
				move_location.y = (target.y - j);
				attack_capable = true;
				return move_location;
			}

			if (target.x - i >= 0 && target.y + j < 11 && map[target.x - i][target.y + j] == 1) {
				move_location.x = (target.x - i);
				move_location.y = (target.y + j);
				attack_capable = true;
				return move_location;
			}
		}
	}

	if (!attack_capable)
	{
		
		if (seeker.y < target.y) {
			for (int j = target.y; j >=0 ; j--) 
				if (seeker.x < target.x) {
					for (int i = 14; i >=0; i--) {
						if (map[i][j] == 1) {
							move_location.x = (i);
							move_location.y = (j);
							return move_location;
						}
					}
				}
				else {
					for (int i = 0; i < 15; i++) {
						if (map[i][j] == 1) {
							move_location.x = (i);
							move_location.y = (j);
							return move_location;
						}
					}
				}
		}
		else {
			for (int j = target.y; j < 11; j++){
				if (seeker.x < target.x) {
					for (int i = 14; i >= 0; i--) {
						if (map[i][j] == 1) {
							move_location.x = (i);
							move_location.y = (j);
							return move_location;
						}
					}
				}
				else {
					for (int i = 0; i < 15; i++) {
						if (map[i][j] == 1) {
						move_location.x = (i);
						move_location.y = (j);
						return move_location;
						}		
					}
				}
			}
		}

	}
	
}

coords Ai::attack_enemy(std::vector<std::vector<int>>& map)
{
	coords move_location;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 11; j++) {
			if (map[i][j] == 2) {
				move_location.x = (i);
				move_location.y = (j);
				
			}
		}
	}
	return move_location;
}
