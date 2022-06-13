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


    sf::Texture usuT;
    usuT.setSmooth(true);
    if (!usuT.loadFromFile("sus.png"))
    {
        std::cout << "nie udalo sie otworzyc pliku";
    }
    sf::Sprite usuS;


    sf::Texture usuHT;
    //usuHT.setSmooth(true);
    if (!usuHT.loadFromFile("susHIGH.png"))
    {
        std::cout << "nie udalo sie otworzyc pliku";
    }

    
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
   
    
    //dane
    
    std::vector<texturesL> loadedEntities;
    unit blob;
    loadedEntities.push_back(blob.pushToLoaded());

    std::vector<std::vector<int> > mapa;
    for (int i = 0; i < 15; i++) {
        std::vector<int> v1;
        for (int j = 0; j < 11; j++) {
            v1.push_back(0);
        }
        mapa.push_back(v1);
    }

    mapa[3][5] = 99;
    coords PresedTile;
    PresedTile.y = 0;
    clearIBuffor(PresedTile);
  
    std::vector<std::vector<tile_b> > vec;
    for (int i = 0; i < 15; i++) {
        // Vector to store column elements
        std::vector<tile_b> v1;

        for (int j = 0; j < 11; j++) {
            v1.push_back(tile_b (true, i, j, battle_tile_basic));
        }
        vec.push_back(v1);
    }

    tlo.setTexture(walka_tlo);
    //ustawianie tekstury tła

     while (window.isOpen())
    {
         //std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << std::endl;
         window.clear();

         window.draw(tlo);

         for (int i = 0; i < 15; i++)
             for (int j = 0; j < 11; j++) {
                 vec[i][j].tile_properties(window,mapa,PresedTile);
                 if (mapa[i][j] >= 0 && mapa[i][j] <= 1)
                 vec[i][j].show_tile(window);
                 else
                 {

                     sf::Texture entityTexture;
                     for (int k = 0; k < loadedEntities.size(); k++)
                         if (loadedEntities[k].entity_id == mapa[i][j])
                             entityTexture = loadedEntities[k].texture;
                     
                     vec[i][j].show_entity(window, entityTexture);
                 }
             };

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
                window.close();
            if (event.type == sf::Event::Resized) {
                window.setSize(sf::Vector2u(1000, 500));
            }
            
            if (event.type == sf::Event::MouseButtonPressed)
            {

            }

        }
        //^eventy testowe - juz nie testowe
        
        if (high == true) {
            blob.show_range(mapa);
            high = false;
        }
       if (interactionBuffor(PresedTile)) {
            blob.move(mapa,PresedTile);
            clearIBuffor(PresedTile);
            clearMap(mapa);
            high = true;
        }

        /*to do:
        1. zmienić rodzaj loadedEntities na bardziej optymalny niz vector
        2. zrobić porządek z skalą i origin płytek i obiektów bo przyprawia o płacz Q-Q
        */

        

        window.display(); //NIe ruszaj
     }

    return 0;
}