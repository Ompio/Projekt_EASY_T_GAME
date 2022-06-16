#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
//#include "unit.h"
struct coords {
    int x;
    int y;
    bool unit;
    bool operator == (const coords& a);
};
struct unit_coords {
    int entity_id;
    sf::Texture texture;
    coords place;
    //unit entity;
};
bool isSpriteHover(sf::FloatRect sprite, sf::RenderWindow& window);
coords find_in_map(std::vector<std::vector<int> >& map, int entity_id);
bool interactionBuffor(coords& x);
void clearIBuffor(coords& x);
void clearMap(std::vector<std::vector<int> >& map);