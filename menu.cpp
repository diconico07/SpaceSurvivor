#include "menu.h"

Menu::Menu()
{
}

Menu::Menu(sf::RenderWindow *window){
    Window=window;
    // Load a sprite to display
    sf::Texture *background=new sf::Texture;
    background->loadFromFile("ressources/backmenu.png");
    background->setRepeated(true);
    background->setSmooth(true);
    back=sf::Sprite(*background);
    back.setColor(sf::Color::White);
    //back.scale(2,2);
    back.setScale((float)800/background->getSize().x,(float)600/background->getSize().y);


}

enum choix Menu::playMenu(){
    sf::RectangleShape *cadre= new sf::RectangleShape(sf::Vector2f(600,400));
    cadre->setPosition(sf::Vector2f(100,100));
    cadre->setFillColor(sf::Color::Transparent);
    cadre->setOutlineThickness(3);
    cadre->setOutlineColor(sf::Color::Black);
    sf::Font font ;
    font.loadFromFile("ressources/CookieMonster.ttf");
    sf::Text *jouer=new sf::Text("Jouer",font,24);
    jouer->setPosition(sf::Vector2f(120,120));
    listeMenu.push_back(jouer);
    while(Window->isOpen()){
        sf::Event event;
        while (Window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window->close();
            if (event.type == sf::Event::KeyPressed)
                switch (event.key.code) {
                case sf::Keyboard::Space:
                    return JOUER;
                    break;
                default:
                    break;
                }
            //Draw the sprites
            Window->draw(back);
            Window->draw(*cadre);
            for(unsigned int i=0;i<listeMenu.size();i++){
                Window->draw(*listeMenu[i]);
            }
            // Update the window
            Window->display();
        }
    }
}
