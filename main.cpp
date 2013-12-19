#include <game.h>
#include <SFML/Graphics.hpp>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800,600), "Space Survivor");
    Game *game=new Game(&window);
    game->playGame();
    return EXIT_SUCCESS;
}
