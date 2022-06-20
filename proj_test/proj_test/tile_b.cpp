#include "tile_b.h"

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

tile_b::tile_b(bool b, int x, int y, sf::Texture t, sf::Font& font) {
		empty = b;
		xcord = x;
		ycord = y;
		arial = font;
		battle_tile_basic = t;
		tile.setTexture(battle_tile_basic);
		tile.setPosition(200+x*40.f, 50+y*40.f);
		entity.setScale(3/2.f, 3/2.f);
		entity.setOrigin(19.f, 35.f);
		entity.setPosition(200 + x * 40.f, 50 + y * 40.f);
		stats.setPosition(200 + x * 40.f, 85 + y * 40.f);
		tile_box = tile.getGlobalBounds();
}

tile_b::tile_b(bool b, int x, int y, sf::Sprite t)
{
	empty = b;
	xcord = x;
	ycord = y;
	tile = t;
	if (xcord == -2)
	tile.setPosition(200 + 16 * 40.f, 50 + y * 40.f);
	if (xcord == -3)
	tile.setPosition(205 + 17 * 40.f, 50 + y * 40.f);
	tile.setScale(1/3.f, 1/3.f);
	tile_box = tile.getGlobalBounds();
	//konstruktor przyciskow wait i defend
}

void tile_b::show_tile(sf::RenderWindow& window) {
		window.draw(tile);
}

void tile_b::show_entity(sf::RenderWindow& window, sf::Texture entityTexture, sf::Color unit_color, int _b_hp, int _hp, int _quantity)
{
	entity.setTexture(entityTexture);
	entity.setColor(unit_color);
	auto old_position = entity.getPosition();
	if (unit_color == sf::Color::Red) {
		entity.setScale(-3 / 2.f, 3 / 2.f);
		entity.move(40.f, 0.f);
	}
	int o_hp = _hp % _b_hp;
	std::string string_stats=std::to_string(_quantity)+", hp: "+std::to_string((o_hp==0)? _b_hp: o_hp)+"/" + std::to_string(_b_hp);
	stats.setString(string_stats);
	stats.setFont(arial);
	stats.setCharacterSize(10);
	stats.setFillColor(sf::Color::Black);
	stats.setOutlineColor(sf::Color::Black);
	window.draw(entity);
	window.draw(stats);
	entity.setPosition(old_position);
}

void tile_b::tile_properties(sf::RenderWindow& window, std::vector<std::vector<int> > map,coords& x)
{
	
	switch (map[xcord][ycord])
	{
	case 0:
		tile.setColor(sf::Color{ 55, 55, 55, 55 });
		break;
	case 1:
		check_interaction(window, x);
		break;
	case 2:
		check_interaction(window, x);
		break;
	case 3:
		check_interaction(window, x);
		break;
	default:
		/*check_interaction(window, x);
		x.unit = true;*/
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


//std::vector<std::pair<bool, std::shared_ptr<unit>>> loadedEntities
//.second