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
tile_b::tile_b(bool b, int x, int y, sf::Texture t) {
		empty = b;
		xcord = x;
		ycord = y;
		battle_tile_basic = t;
		tile.setTexture(battle_tile_basic);
		tile.setPosition(200+x*40.f, 50+y*40.f);
		entity.setScale(2.f, 2.f);
		entity.setOrigin(22.f, 42.f);
		entity.setPosition(200 + x * 40.f, 50 + y * 40.f);
		tile_box = tile.getGlobalBounds();
}

void tile_b::show_tile(sf::RenderWindow& window) {
		window.draw(tile);
}

void tile_b::show_entity(sf::RenderWindow& window, sf::Texture entityTexture)
{
	entity.setTexture(entityTexture);
	window.draw(entity);
}

void tile_b::tile_properties(sf::RenderWindow& window, std::vector<std::vector<int> > map,coords& x)
{
	
	switch (map[xcord][ycord])
	{
	case 0:
		tile.setColor(sf::Color{ 55, 55, 55, 55 });
		break;
	case 1:
		check_interaction(window,x);
		break;
	default:
		tile.setColor(sf::Color::Transparent);
		break;
	}
}

void tile_b::check_interaction(sf::RenderWindow& window, coords& x) {
	if (isSpriteHover(tile_box, window)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			tile.setColor(sf::Color::Red);
			x.x = xcord;
			x.y = ycord;
		}
		else tile.setColor(sf::Color(14, 136, 200, 255));
	}
	else tile.setColor(sf::Color::Green);
}
