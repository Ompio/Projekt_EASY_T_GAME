//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <iostream>
#include "functions.h"
#include "tile_b.h"
#include "unit.h"
#include <vector>
#include <stack>
#include <tuple>
#include <ranges>
#include <algorithm>
#include "Ai.h"

void clearMap(std::vector<std::vector<int>>& map, std::vector<std::pair<bool, std::shared_ptr<unit>>> loadedEntities)
{
    coords on_map;
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 11; j++) {
            if (map[i][j] <= 2)map[i][j] = 0;
        };
    for (auto& entity : loadedEntities) {
        on_map = entity.second->get_coords();
        map[on_map.x][on_map.y] = entity.second->get_id();
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
    bool Mouse_click_buffor = false;
    bool Move_Attack_buffor = false;
    bool Ai_buffor = false;
    bool Attack_possibility = false;
    bool drawing_tiles = true;
    bool kop_w_kalendarz = false;
    bool stack_call = false;
    bool tour_done = false;
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


    

    std::vector<std::pair<bool,std::shared_ptr<unit>>> loadedEntities;
    

    loadedEntities.push_back(std::make_pair(true,std::shared_ptr<unit>(new unit())));
    loadedEntities.push_back(std::make_pair(false, std::shared_ptr<unit>(new unit(11, 20, 10, 10, 5, 200, 20, 6, "PLOMYK1.png", 10))));
    loadedEntities.push_back(std::make_pair(true, std::shared_ptr<unit>(new unit(12, 20, 10, 10, 5, 200, 20, 4, "PLOMYK2.png", 10))));
    loadedEntities.push_back(std::make_pair(false, std::shared_ptr<unit>(new unit(13, 20, 10, 10, 5, 200, 20, 5, "PLOMYK1.png", 10))));
    

    loadedEntities[0].second->set_coords(coords(0, 7));
    loadedEntities[1].second->set_coords(coords(13, 6));
    loadedEntities[2].second->set_coords(coords(0, 10));
    loadedEntities[3].second->set_coords(coords(14, 8));

    std::ranges::sort(loadedEntities, [](std::pair<bool, std::shared_ptr<unit>> a, std::pair<bool, std::shared_ptr<unit>> b)
        { return a.second->get_speed() > b.second->get_speed(); });

    std::stack<int> wait_queue;

    Ai enemy;


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
            coords _place = entity.second->get_coords();
            entityTexture = entity.second->get_texture();
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
                    std::cout << "button released" << std::endl;
                }
            }

        }
        //^eventy testowe - juz nie testowe
        
        if (loadedEntities.empty() != true) {
            

            if (drawing_tiles) {
                clearMap(map, loadedEntities);
                if (!Move_Attack_buffor) {
                    if (loadedEntities[unit_tour].second->check_living(map, loadedEntities)) {
                        loadedEntities[unit_tour].second->show_range(map);
                        drawing_tiles = false;
                        if (!loadedEntities[unit_tour].first) {
                            enemy.find_enemy(loadedEntities);
                            Ai_buffor = true;
                        }
                        else Ai_buffor = false;
                    }
                }
                if (Move_Attack_buffor) {
                    if (loadedEntities[unit_tour].second->check_living(map, loadedEntities)) {
                        loadedEntities[unit_tour].second->show_attack(map);
                        drawing_tiles = false;
                    }
                }
                if (!loadedEntities[unit_tour].first) {
                    Mouse_click_buffor = true;
                    std::cout << "tura bota"<< unit_tour << std::endl;

                }
            }
            //^wyswietlanie hud (bardziej modyfikacja)

           

            if (Mouse_click_buffor||Ai_buffor) {
                if (!Move_Attack_buffor) {
                    if (Ai_buffor) {

                    }
                    if (interactionBuffor(PresedTile) && PresedTile.x >= 0) {
                        loadedEntities[unit_tour].second->move(map, PresedTile);
                        Attack_possibility = loadedEntities[unit_tour].second->check_attack(map);

                        Move_Attack_buffor = true;
                        Mouse_click_buffor = false;
                        drawing_tiles = true;
                        clearIBuffor(PresedTile);
                        clearMap(map,loadedEntities);
                    //^interakcja ruchu
                    }
                    if (PresedTile.x==-2) {
                        Attack_possibility = loadedEntities[unit_tour].second->check_attack(map);

                        Move_Attack_buffor = true;
                        Mouse_click_buffor = false;
                        drawing_tiles = true;
                        if(!stack_call)
                        wait_queue.push(unit_tour);
                        clearIBuffor(PresedTile);
                        clearMap(map, loadedEntities);
                    }
                    //^interakcja czekania
                    if (PresedTile.x == -3) {


                        tour_done = true;
                        Move_Attack_buffor = false;
                        Mouse_click_buffor = false;
                        drawing_tiles = true;
                        clearIBuffor(PresedTile);
                        clearMap(map, loadedEntities);
                    }
                    //^interakcja pominiecia walki/obrony
                }   
                if (Move_Attack_buffor) {
                    if (Ai_buffor) {

                    }
                    if (Attack_possibility) {
                        if (interactionBuffor(PresedTile) ) {
                            loadedEntities[unit_tour].second->attack_M(PresedTile, loadedEntities);

                            kop_w_kalendarz = true;
                            tour_done = true;
                            Move_Attack_buffor = false;
                            Mouse_click_buffor = false;
                            drawing_tiles = true;
                            clearIBuffor(PresedTile);
                            clearMap(map, loadedEntities);
                        }
                    }
                    else if (!Attack_possibility) {

                        tour_done = true;
                        Move_Attack_buffor = false;
                        Mouse_click_buffor = false;
                        drawing_tiles = true;
                        clearIBuffor(PresedTile);
                        clearMap(map, loadedEntities);
                    }
                }
            }
            if (kop_w_kalendarz) {
                for (auto& reaper : loadedEntities) {
                    if (!reaper.second->check_living(map, loadedEntities))break;
                    std::cout << "zniwiarz dziala" << std::endl;
                }
                kop_w_kalendarz = false;
            }

           //std::cout << unit_tour;
            if (tour_done && !stack_call) {
                  unit_tour++; 
                  std::cout << "zakonczono ruch" << std::endl;
                  tour_done = false;
               if (unit_tour >= loadedEntities.size()) {
                  stack_call = true;
               }
            }
            if (stack_call) {
                std::cout << "zakonczono ture, czas na czekajki" << std::endl;

                if (wait_queue.empty()) {
                    unit_tour = 0;
                    std::cout << "nowa tura" << std::endl;
                    tour_done = false;
                    stack_call = false;
                }

                else {
                    unit_tour = wait_queue.top();
                    if (tour_done) {
                        tour_done = false;
                        wait_queue.pop();
                    }
                }

                drawing_tiles = true;
            }
        }
       //^strefa placzu i histerii

        /*to do:  
        1. ruch przeciwnika/nasz ruch
        2. zrobic porzadek z skala i origin płytek i obiektów bo przyprawia o placz Q-Q?????? //mozliwe ze pozniej
        3. typy jednostek (walka zasiegowa, zabija chociaz jeden)
        4. wygrana/przegrana

        */

        

        window.display(); //NIe ruszaj
     }

    return 0;
}