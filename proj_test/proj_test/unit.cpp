#include "unit.h"
#include "functions.h"

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
	health=1000;
	health_b=1000;
	speed=4;
	amount = 1;
}

unit::unit(int id, int a, int o, int min, int max, int zd, int z, int s, std::string filename, int q)
{
	if (!looks.loadFromFile(filename))
	{
		std::cout << "nie udalo sie otworzyc pliku";
	}
	entity_id = id;
	attack = a;
	defense = o;
	damage_max = min;
	damage_min = max;
	health = zd;
	health_b = z;
	speed = s;
	amount = q;
}

void unit::fight(unit& enemy)
{

}

void unit::show_range(std::vector<std::vector<int> >& map)
{
	coords place = find_in_map(map,entity_id);
	int count = 0;
	
	for (int i = speed; i > 0; i-- ) {
		for (int j = count; j >= 0; j--) {
			if (place.y + i < 11 && place.x + j < 15) {
					map[place.x + j][place.y + i] = 1;
			}
			if (place.y - i >= 0 && place.x - j >= 0) {
					map[place.x - j][place.y - i] = 1;
			}
			if (place.x + i < 15 && place.y - j >= 0) {
					map[place.x + i][place.y - j] = 1;
			}
			if (place.x - i >= 0 && place.y + j < 11) {
				map[place.x - i][place.y + j] = 1;
			}
		}
		count++;
		std::cout << i << std::endl;
	}
}

void unit::move(std::vector<std::vector<int> >& map, coords x)
{
	coords ZERO = find_in_map(map, entity_id);
	map[ZERO.x][ZERO.y] = 0;
	map[x.x][x.y] = entity_id;
}

sf::Texture unit::shareTexture()
{
	return sf::Texture(looks);
}

texturesL unit::pushToLoaded()
{
	texturesL x;
	x.entity_id = entity_id;
	x.texture = looks;
	return x;
}
