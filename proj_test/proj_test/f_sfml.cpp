#include "f_sfml.h"
bool isSpriteHover(sf::FloatRect sprite, sf::RenderWindow& window)
{
    sf::Vector2f mp;
    mp.x = sf::Mouse::getPosition(window).x;
    mp.y = sf::Mouse::getPosition(window).y;
<<<<<<< HEAD:proj_test/proj_test/f_sfml.cpp
    if (sprite.contains(mp)) {
        return true;
=======
    //std::cout << mp.x << ":X | Y:" << mp.y << std::endl;
    if (sprite.contains(mp)) {
        return true;
        //std::cout << "beka" << std::endl;
>>>>>>> cebeb1624b917a18b8b5045b5eb6ef2c578cd745:GraTurowa/GraTurowa/f_sfml.cpp
    }
    return false;
}