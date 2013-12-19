#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
const int spacementSelector=90;

enum choix {
    JOUER,
    HIGHSCORES,
    CREDITS,
    QUITTER
};

class Menu
{
private:
    //Attributes
    sf::RenderWindow *Window;
    sf::Sprite back;
    std::vector<sf::Text*> listeMenu;
public:
    //Constructors/destructor
    Menu();
    Menu(sf::RenderWindow *window);
    ~Menu();

    //methods
    enum choix playMenu();
};

#endif // MENU_H