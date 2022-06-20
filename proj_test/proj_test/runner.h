#pragma once
#include "unit.h"
class runner :
    public unit
{
    coords starting_place;
public:
    runner();
    runner(int id, int a, int def, int min, int max, int zd, int z, int s, std::string filename, int q);
    void attack_M(std::vector<std::vector<int> >& map, coords x, std::vector<std::pair<bool, std::shared_ptr<unit>>>& loadedEntities);
    void move(std::vector<std::vector<int> >& map, coords x);
};

