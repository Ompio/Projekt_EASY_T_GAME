#include "tile_b.h"
//#include "f_sfml.h"
tile_b::tile_b() {
	if (!battle_tile_null.loadFromFile("battle_tile_null.png"))
	{
		std::cout << "nie udalo sie otworzyc pliku";
	}
	tile.setTexture(battle_tile_null);
	empty = true;
	xcord = 0;
	ycord = 0;
}
tile_b::tile_b(bool b, int x, int y, sf::Sprite t) {
		empty = b;
		xcord = x;
		ycord = y;
		tile = t;
}
void tile_b::show_tile(sf::RenderWindow& window) {
		window.draw(tile);
}