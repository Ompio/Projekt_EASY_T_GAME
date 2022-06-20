#include "runner.h"

runner::runner():unit()
{
}

runner::runner(int id, int a, int def, int min, int max, int zd, int z, int s, std::string filename, int q)
	: unit(id, a, def, min, max, zd, z, s, filename, q)

{
}

void runner::attack_M(std::vector<std::vector<int> >& map,coords x, std::vector<std::pair<bool, std::shared_ptr<unit>>>& loadedEntities)
{
	for (auto& entity : loadedEntities) {
		if (entity.second->get_coords() == x) {
			this->deal_damage(entity.second);
			std::cout << std::endl << " udalo sie zaatakowaæ jednostce " << entity_id << std::endl;
			break;
		}
	}
	move(map, starting_place);
}

void runner::move(std::vector<std::vector<int>>& map, coords x)
{
	starting_place = place;
	map[place.x][place.y] = 0;
	map[x.x][x.y] = entity_id;
	place.x = x.x;
	place.y = x.y;
}
