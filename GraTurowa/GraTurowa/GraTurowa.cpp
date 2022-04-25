#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class przycisk {
public:
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 500), "Fun and interactive game");

    bool high = true;

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
    

     while (window.isOpen())
    {
         //std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << std::endl;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
                window.close();
            if (event.type == sf::Event::Resized) {
                std::cout << event.size.height << " " << event.size.width<<std::endl;
                if (high == true)
                    high=false;
                else high = true;
            }
        }



        window.clear();
        //window.draw(miastoS);
        if (high==true)
            usuS.setTexture(usuT);
        else usuS.setTexture(usuHT);
        window.draw(usuS);
        window.display();
    }

    return 0;
}