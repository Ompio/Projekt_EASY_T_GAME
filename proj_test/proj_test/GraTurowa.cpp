//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <iostream>
#include "functions.h"
#include "tile_b.h"
#include "unit.h"
#include <vector>

void clearMap(std::vector<std::vector<int>>& map, std::vector<std::shared_ptr<unit>>& loadedEntities)
{
    coords on_map;
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 11; j++) {
            if (map[i][j] <= 2)map[i][j] = 0;
        };
    for (auto& entity : loadedEntities) {
        on_map = entity->get_coords();
        map[on_map.x][on_map.y] = entity->get_id(); 
    }
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 500), "Fun and interactive game");

   

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

    //plytki hud
    sf::Texture defend_texture;
    if (!defend_texture.loadFromFile("defend.png"))
    {
        std::cout << "nie udalo sie otworzyc pliku";
    }
    sf::Sprite defend_sprite;
    defend_sprite.setTexture(defend_texture);

    sf::Texture wait_texture;
    if (!wait_texture.loadFromFile("wait.png"))
    {
        std::cout << "nie udalo sie otworzyc pliku";
    }
    sf::Sprite wait_sprite;
    wait_sprite.setTexture(wait_texture);
    //ustawianie tekstury plytki walki
   
   

    std::vector<std::vector<int> > map;
    for (int i = 0; i < 15; i++) {
        std::vector<int> v1;
        for (int j = 0; j < 11; j++) {
            v1.push_back(0);
        }
        map.push_back(v1);
    }
    
    //map[13][5] = 99;
    //map[13][6] = 11;

    coords PresedTile;
    PresedTile.y = 0;
    clearIBuffor(PresedTile);
    bool Mouse_click_buffor = true;
    bool Move_Attack_buffor = false;
    bool Attack_possibility = false;
    bool drawing_tiles = true;
    //^zmienne walki
  
    std::vector<std::vector<tile_b> > tiles_vector;
    for (int i = 0; i < 15; i++) {
        // Vector to store column elements
        std::vector<tile_b> v1;

        for (int j = 0; j < 11; j++) {
            v1.push_back(tile_b (true, i, j, battle_tile_basic));
        }
        tiles_vector.push_back(v1);
    }

    tile_b wait(true, -2, -1, wait_sprite);
    tile_b defend(true, -3, -1, defend_sprite);
    //^ tekstury interfejsu


    std::vector<std::shared_ptr<unit>> loadedEntities;
    unit blob;
    unit red(11, 20, 10, 10, 5, 200, 20, 4, "PLOMYK1.png", 10);

    loadedEntities.push_back(std::shared_ptr<unit>(new unit()));
    loadedEntities.push_back(std::shared_ptr<unit>(new unit(11, 20, 10, 10, 5, 200, 20, 4, "PLOMYK1.png", 10)));
    loadedEntities.push_back(std::shared_ptr<unit>(new unit(12, 20, 10, 10, 5, 200, 20, 4, "PLOMYK1.png", 10)));

    loadedEntities[0]->set_coords(coords(0, 5));
    loadedEntities[1]->set_coords(coords(13, 6));
    loadedEntities[2]->set_coords(coords(13, 8));

    int unit_tour = 0;
    //dane




    tlo.setTexture(walka_tlo);
    clearMap(map, loadedEntities);
    //ustawianie tekstury tła

    while (window.isOpen())
    {
        //std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << std::endl;
        window.clear();

        window.draw(tlo);

        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 11; j++) {
                tiles_vector[i][j].tile_properties(window, map, PresedTile);
                if (map[i][j] >= 0 && map[i][j] <= 2)
                    tiles_vector[i][j].show_tile(window);
            };
        for(auto& entity : loadedEntities) {
            sf::Texture entityTexture;
            coords _place = entity->get_coords();
            entityTexture = entity->get_texture();
            tiles_vector[_place.x][_place.y].show_entity(window, entityTexture);
        }

        defend.check_interaction(window, PresedTile);
        defend.show_tile(window);
        
        wait.check_interaction(window, PresedTile);
        wait.show_tile(window);

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
        
        if (loadedEntities.empty() != true) {
            
            if (drawing_tiles) {
                if (!Move_Attack_buffor) {
                    if (loadedEntities[unit_tour]->check_living(map, loadedEntities)) {
                        loadedEntities[unit_tour]->show_range(map);
                        drawing_tiles = false;
                    }
                }
                if (Move_Attack_buffor) {
                    if (loadedEntities[unit_tour]->check_living(map, loadedEntities)) {
                        loadedEntities[unit_tour]->show_attack(map);
                        drawing_tiles = false;
                    }
                }
            }
            //^wyswietlanie hud (bardziej modyfikacja)


            if (Mouse_click_buffor) {
                if (!Move_Attack_buffor) {
                    if (interactionBuffor(PresedTile) && PresedTile.x >= 0) {
                        loadedEntities[unit_tour]->move(map, PresedTile);
                        Attack_possibility = loadedEntities[unit_tour]->check_attack(map);

                        Move_Attack_buffor = true;
                        Mouse_click_buffor = false;
                        drawing_tiles = true;
                        clearIBuffor(PresedTile);
                        clearMap(map,loadedEntities);
                    //^interakcja ruchu
                    }
                    if (PresedTile.x==-2) {
                        

                        Move_Attack_buffor = true;
                        Mouse_click_buffor = false;
                        drawing_tiles = true;
                        clearIBuffor(PresedTile);
                        clearMap(map, loadedEntities);
                    }
                    //^interakcja czekania
                    if (PresedTile.x == -3) {


                        unit_tour++;
                        Move_Attack_buffor = false;
                        Mouse_click_buffor = false;
                        drawing_tiles = true;
                        clearIBuffor(PresedTile);
                        clearMap(map, loadedEntities);
                    }
                    //^interakcja pominiecia walki/obrony
                }   
                if (Move_Attack_buffor) {
                    if (Attack_possibility) {
                        if (interactionBuffor(PresedTile) ) {
                            loadedEntities[unit_tour]->attack_M(PresedTile, loadedEntities);

                            unit_tour++;
                            Move_Attack_buffor = false;
                            Mouse_click_buffor = false;
                            drawing_tiles = true;
                            clearIBuffor(PresedTile);
                            clearMap(map, loadedEntities);
                        }
                    }
                    else if (!Attack_possibility) {

                        unit_tour++;
                        Move_Attack_buffor = false;
                        Mouse_click_buffor = false;
                        drawing_tiles = true;
                        clearIBuffor(PresedTile);
                        clearMap(map, loadedEntities);
                    }
                }
            }
           
           //std::cout << unit_tour;
            if (unit_tour >= loadedEntities.size()) {
                unit_tour = 0;
                drawing_tiles = true;
            }
        }
       //^strefa placzu i histerii

        /*to do:  
        * 1. kolejkowalnosc walki
        2. zrobic porzadek z skala i origin płytek i obiektów bo przyprawia o placz Q-Q??????
        3. otrzymywanie obrazen przez cel
        4. typy jednostek (walka zasiegowa, zabija chociaz jeden)
        5. wygrana/przegrana

        */

        

        window.display(); //NIe ruszaj
     }

    return 0;
}