#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Text.hpp>

enum choix {
    JOUER,
    CREDITS,
    QUITTER
};

class Menu
{
public:
    //Attributes
    sf::RenderWindow *Window;
    sf::Sprite back;
    std::vector<sf::Text*> listeMenu;
    //Constructors/destructor
    Menu();
    Menu(sf::RenderWindow *window);
    ~Menu();

    //methods
    enum choix playMenu();
};

#endif // MENU_H
