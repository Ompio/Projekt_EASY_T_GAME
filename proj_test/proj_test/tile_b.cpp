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
<<<<<<< HEAD:proj_test/proj_test/tile_b.cpp
		tile.setPosition(200+x*40.f, 50+y*40.f);
		tile_box = tile.getGlobalBounds();
}
void tile_b::show_tile(sf::RenderWindow& window) {
		window.draw(tile);
}
void tile_b::check_interaction(sf::RenderWindow& window) {
	if (isSpriteHover(tile_box, window)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			tile.setColor(sf::Color::Red);
			
		}
		else tile.setColor(sf::Color(14, 136, 200, 255));
	}
	else tile.setColor(sf::Color::Green);
}
=======
}
void tile_b::show_tile(sf::RenderWindow& window) {
		window.draw(tile);
}
>>>>>>> cebeb1624b917a18b8b5045b5eb6ef2c578cd745:GraTurowa/GraTurowa/tile_b.cpp
