#include <game.h>
#include <menu.h>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Space Survivor");
    Menu *menu = new Menu(&window);
    while(1){
        switch(menu->playMenu()){
        case JOUER:
        {
            Game *game=new Game(&window);
            game->playGame();
            delete game;
            break;
        }
        case CREDITS:
            break;
        case HIGHSCORES:
            menu->play_HS();
            break;
        case QUITTER:
            return EXIT_SUCCESS;
        }
    }
}


