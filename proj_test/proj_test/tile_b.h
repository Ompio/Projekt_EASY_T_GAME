#pragma once
#include "f_sfml.h"
class tile_b
{
	bool empty;
	int xcord;
	int ycord;
	sf::Sprite tile;
	sf::Texture battle_tile_null;
<<<<<<< HEAD:proj_test/proj_test/tile_b.h
	sf::FloatRect tile_box;
	struct interaction;
=======
>>>>>>> cebeb1624b917a18b8b5045b5eb6ef2c578cd745:GraTurowa/GraTurowa/tile_b.h
 public:
	tile_b();
	tile_b(bool b, int x, int y, sf::Sprite t);
	void show_tile(sf::RenderWindow& window);
<<<<<<< HEAD:proj_test/proj_test/tile_b.h
	void check_interaction(sf::RenderWindow& window);
=======
>>>>>>> cebeb1624b917a18b8b5045b5eb6ef2c578cd745:GraTurowa/GraTurowa/tile_b.h
};

