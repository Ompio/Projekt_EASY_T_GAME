#include "unit.h"

unit::unit()
{
	if (!looks.loadFromFile("battle_tile_null.png"))
	{
		std::cout << "nie udalo sie otworzyc pliku";
	}
	unit_id=99;
	attack=10;
	defense=5;
	damage_max=20;
	damage_min=10;
	health=1000;
	health_b=1000;
	speed=5;
	quantity = 1;
}

unit::unit(int id, int a, int o, int min, int max, int zd, int z, int s, sf::Sprite l int q)
{
}

void unit::fight()
{
}

void unit::show_range(int& map)
{
}

void unit::move(int& map)
{
}
