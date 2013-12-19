#include <game.h>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1024,768), "Space Survivor");
    Game *game=new Game(&window);
    game->playGame();
    return EXIT_SUCCESS;
}
