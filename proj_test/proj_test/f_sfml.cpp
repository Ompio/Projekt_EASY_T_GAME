#include "f_sfml.h"
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