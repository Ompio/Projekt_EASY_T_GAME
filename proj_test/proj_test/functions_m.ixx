module;
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
import  <iostream>;
export module functions_m;



export struct coords {
    int x;
    int y;
    bool operator == (const coords& a);
    coords();
    coords(int x, int y);
};
export struct unit_coords {
    int entity_id;
    sf::Texture texture;
    coords place;
    //unit entity;
};

export bool isSpriteHover(sf::FloatRect sprite, sf::RenderWindow& window)
{
    sf::Vector2f mp;
    mp.x = sf::Mouse::getPosition(window).x;
    mp.y = sf::Mouse::getPosition(window).y;
    if (sprite.contains(mp)) {
        return true;
    }
    return false;
}

export coords find_in_map(std::vector<std::vector<int> >& map, int entity_id) {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 11; j++) {
            if (map[i][j] == entity_id) {
                coords place;
                place.x = i;
                place.y = j;
                return place;
            }
        }
    }
    coords place;
    place.x = -1;
    place.y = -1;
    return place;
}

export bool interactionBuffor(coords& x)
{
    if (x.x == -1)
        return false;
    else return true;
}

export void clearIBuffor(coords& x)
{
    x.x = -1;
}

export bool coords::operator==(const coords& a)
{
    if (a.x == x && a.y == y)
        return true;
    else return false;
}

export coords::coords()
{
    x = -1;
    y = -1;
}

export coords::coords(int _x, int _y)
{
    x = _x;
    y = _y;
}