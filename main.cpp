#include <game.h>
#include <menu.h>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Space Survivor");
    Menu *menu = new Menu(&window);
    menu->playMenu();
    Game *game=new Game(&window);
    game->playGame();

    return EXIT_SUCCESS;
}
