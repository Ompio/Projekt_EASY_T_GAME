#pragma once
#include "unit.h"

class Ai
{
	int enemy_focus;

public:
	Ai();
	void find_enemy(std::vector<std::pair<bool, std::shared_ptr<unit>>>& loadedEntities);
	coords seek_enemy(std::vector<std::vector<int> >& map, std::vector<std::pair<bool, std::shared_ptr<unit>>>& loadedEntities);

};

