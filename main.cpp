#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Missile.h"

int main()
{
    std::vector<Missile*> listeMissiles;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Space Survivor");
    // Load a sprite to display


    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the sprites
        for(unsigned int i=0;i<listeMissiles.size();i++){
            listeMissiles[i]->move();
        }
        for(unsigned int i=0;i<listeMissiles.size();i++){
            for(unsigned int j=i+1;j<listeMissiles.size();i++)
              listeMissiles[i]->collide(listeMissiles[i]);
        }
        for(unsigned int i=0;i<listeMissiles.size();i++){
          window.draw(listeMissiles[i]->getSprite());
        }

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
