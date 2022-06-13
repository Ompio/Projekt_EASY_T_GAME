#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
struct coords {
    int x;
    int y;
};
struct texturesL {
    int entity_id;
    sf::Texture texture;
};
bool isSpriteHover(sf::FloatRect sprite, sf::RenderWindow& window);
coords find_in_map(std::vector<std::vector<int> >& map, int entity_id);
bool interactionBuffor(coords& x);
void clearIBuffor(coords& x);
void clearMap(std::vector<std::vector<int> >& map);
