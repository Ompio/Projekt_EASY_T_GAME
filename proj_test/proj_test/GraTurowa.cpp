//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <iostream>
#include "f_sfml.h"
#include "tile_b.h"
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
    
    sf::FloatRect tile_box = battle_tile.getGlobalBounds();
    battle_tile.setOrigin(tile_box.width/2,tile_box.height/2);
    //battle_tile.setPosition(50.f, 25.f);
    tile_box = battle_tile.getGlobalBounds();
    std::cout << tile_box.height << tile_box.width;
    
    //dane
    
    int mapa[15][11];
    tile_b map[15][11];
  
    std::vector<std::vector<tile_b> > vec;
    for (int i = 0; i < 15; i++) {
        // Vector to store column elements
        std::vector<tile_b> v1;

        for (int j = 0; j < 11; j++) {
            v1.push_back(tile_b (true, i, j, battle_tile));
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
                 vec[i][j].check_interaction(window);
                 vec[i][j].show_tile(window);
                 //std::cout << std::endl;
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

        
        
        

        

        window.display(); //NIe ruszaj
     }
     //miałem spory zastuj z powodu choroby ostatnio :(

    return 0;
}