#include "functions.h"

bool isSpriteHover(sf::FloatRect sprite, sf::RenderWindow& window)
{
    sf::Vector2f mp;
    mp.x = sf::Mouse::getPosition(window).x;
    mp.y = sf::Mouse::getPosition(window).y;
    if (sprite.contains(mp)) {
        return true;
    }
    return false;
}

coords find_in_map(std::vector<std::vector<int> >&map, int entity_id) {
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

bool interactionBuffor(coords& x)
{
    if (x.x == -1)
        return false;
    else return true;
}

void clearIBuffor(coords& x)
{
    x.x = -1;
}

void clearMap(std::vector<std::vector<int>>& map)
{
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 11; j++) {
            if (map[i][j] == 1)map[i][j] = 0;
        };
}

bool coords::operator==(const coords& a)
{
    if (a.x == x && a.y == y)
        return true;
    else return false;
}
