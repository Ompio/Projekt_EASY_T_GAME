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

coords Ai::seek_enemy(std::vector<std::vector<int>>& map, std::vector<std::pair<bool, std::shared_ptr<unit>>>& loadedEntities)
{
	
	coords target = loadedEntities[enemy_focus].second->get_coords();
	coords move_location;

	for (int i = 1; i > 0; i--) {
		for (int j = 1; j >= 0; j--) {

			if (target.y + i < 11 && target.x + j < 15 && map[target.x + j][target.y + i] == 1) {
				move_location.x = (target.x + j);
				move_location.y	= (target.y + i);
				break;
			}

			if (target.y - i >= 0 && target.x - j >= 0 && map[target.x - j][target.y - i] == 1) {
				move_location.x = (target.x - j);
				move_location.y = (target.y - i);
				break;
			}

			if (target.x + i < 15 && target.y - j >= 0 && map[target.x + i][target.y - j] == 1) {
				move_location.x = (target.x + i);
				move_location.y = (target.y - j);
				break;
			}

			if (target.x - i >= 0 && target.y + j < 11 && map[target.x - i][target.y + j] == 1) {
				move_location.x = (target.x - i);
				move_location.y = (target.y + j);
				break;
			}
		}
	}

	return move_location;
}
