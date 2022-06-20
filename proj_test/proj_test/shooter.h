#pragma once
#include "unit.h"
class shooter :
    public unit
{
    std::vector<coords> shooting_targets;
public:
    shooter();
    shooter(int id, int a, int def, int min, int max, int zd, int z, int s, std::string filename, int q);
    bool check_attack(std::vector<std::vector<int> >& map, bool orientation_m, std::vector<coords>& oponent_friend, std::vector<std::pair<bool, std::shared_ptr<unit>>>& loadedEntities);
    void show_attack(std::vector<std::vector<int> >& map, std::vector<coords>& oponent_friend);
    void attack_M(std::vector<std::vector<int> >& map, coords x, std::vector<std::pair<bool, std::shared_ptr<unit>>>& loadedEntities);
    void deal_ranged_damage(std::shared_ptr<unit>& enemy);
};

