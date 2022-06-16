//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <iostream>
#include "functions.h"
#include "tile_b.h"
#include "unit.h"
#include <vector>



int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 500), "Fun and interactive game");

    bool high = true;

    //tekstury

    //tekstury testowe
    sf::Texture miastoT;
    miastoT.setSmooth(true);
    if (!miastoT.loadFromFile("bastion.jpg"))
    {
        std::cout << "nie udalo sie otworzyc pliku";
    }
    sf::Sprite miastoS;
    miastoS.setTexture(miastoT);
    
    //tekstury docelowe

    sf::Texture walka_tlo;
    if (!walka_tlo.loadFromFile("walka_tlo.png"))
    {
        std::cout << "nie udalo sie otworzyc pliku";
    }
    sf::Sprite tlo; 
    tlo.setScale(sf::Vector2f(2.f, 1.f)); // absolute scale factor

    //plytka walki
    sf::Texture battle_tile_basic;
    if (!battle_tile_basic.loadFromFile("battle_tile_basic.png"))
    {
        std::cout << "nie udalo sie otworzyc pliku";
    }

    sf::Sprite battle_tile;
    
    battle_tile.setScale(1.f, 1.f);

    battle_tile.setTexture(battle_tile_basic);

    //ustawianie tekstury plytki walki
   
   

    std::vector<std::vector<int> > mapa;
    for (int i = 0; i < 15; i++) {
        std::vector<int> v1;
        for (int j = 0; j < 11; j++) {
            v1.push_back(0);
        }
        mapa.push_back(v1);
    }


    mapa[13][5] = 99;
    mapa[13][6] = 11;

    coords PresedTile;
    PresedTile.y = 0;
    clearIBuffor(PresedTile);
    bool Mouse_click_buffor = true;
  
    std::vector<std::vector<tile_b> > tiles_vector;
    for (int i = 0; i < 15; i++) {
        // Vector to store column elements
        std::vector<tile_b> v1;

        for (int j = 0; j < 11; j++) {
            v1.push_back(tile_b (true, i, j, battle_tile_basic));
        }
        tiles_vector.push_back(v1);
    }

    std::vector<unit_coords> loadedEntities;
    unit blob;
    unit red(11, 20, 10, 10, 5, 200, 20, 4, "PLOMYK1.png", 10);
    loadedEntities.push_back(blob.pushToLoaded(mapa));
    loadedEntities.push_back(red.pushToLoaded(mapa));


    //dane




    tlo.setTexture(walka_tlo);
    //ustawianie tekstury tła

    while (window.isOpen())
    {
        //std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << std::endl;
        window.clear();

        window.draw(tlo);

        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 11; j++) {
                tiles_vector[i][j].tile_properties(window, mapa, PresedTile);
                if (mapa[i][j] >= 0 && mapa[i][j] <= 2)
                    tiles_vector[i][j].show_tile(window);
            };
        for(auto& entity : loadedEntities) {
            sf::Texture entityTexture;
            entityTexture = entity.texture;
            tiles_vector[entity.place.x][entity.place.y].show_entity(window, entityTexture);
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized) {
                window.setSize(sf::Vector2u(1000, 500));
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.key.code == sf::Mouse::Left) {
                    Mouse_click_buffor = true;
                }
            }

        }
        //^eventy testowe - juz nie testowe

        if(high) {
            if (blob.check_living(mapa,loadedEntities)) {
                blob.show_range(mapa,loadedEntities);
                //blob.show_attack(mapa, loadedEntities);
                high = false;
            }
        }
        if (Mouse_click_buffor) {
            if (interactionBuffor(PresedTile)) {
                blob.move(mapa, PresedTile, loadedEntities);
                //blob.attack_M(PresedTile, loadedEntities);
                clearIBuffor(PresedTile);
                clearMap(mapa);
                high = true;
                blob.modify_Hp(-50);
                blob.check_living(mapa, loadedEntities);
                Mouse_click_buffor = false;
            }
        }

       //^strefa placzu i histerii

        /*to do:
        1. zamienic wszystkie unit_coords na klase  
        2. zrobic porzadek z skala i origin płytek i obiektów bo przyprawia o placz Q-Q
        3. usunac(jest uzywana ale mniej inwazyjnie) funkcję find_in_map i poprawić check_living

        */

        

        window.display(); //NIe ruszaj
     }

    return 0;
}