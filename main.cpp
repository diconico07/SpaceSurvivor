#include <game.h>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Space Survivor");
    Game *game=new Game(&window);
    game->playGame();
    return EXIT_SUCCESS;
}
