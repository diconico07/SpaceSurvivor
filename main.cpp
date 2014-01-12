#include <game.h>
#include <menu.h>

sf::Texture EXPLOSION, PROJECTILE, ASTEROID, VESSEL;
sf::SoundBuffer EXPLOSION_SOUND, FIRE_SOUND, DEATH_SOUND;

int main()
{
    Ressources::load();
    // Create the main window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Space Survivor");
    Menu *menu = new Menu(&window);
    while(1){
        switch(menu->playMenu()){
        case JOUER: //Launch the game
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


