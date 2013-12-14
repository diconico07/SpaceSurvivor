#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>

#include "Missile.h"
#include "Vaisseau.h"
#include "Asteroid.h"
#include "Vecteur.h"
const int Nombre_asteroids= 12;

int main()
{
    std::vector<Missile*> listeMissiles;

    Vaisseau *joueur=new Vaisseau();
    listeMissiles.push_back(joueur);

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800,600), "Space Survivor");
    // Load a sprite to display
    sf::Texture background;
    background.loadFromFile("ressources/background.jpg");
    background.setRepeated(true);
    //background.setSmooth(true);
    sf::Sprite back(background);
    back.setColor(sf::Color::Blue);
    //back.scale(2,2);
    back.setTextureRect(sf::IntRect(0,0,800,600));


    //creating test asteroids field
    Vecteur *position = new Vecteur();
    Vecteur *vitesse = new Vecteur();
    int size;
    for(int i=0;i<10;i++){
        position->setXY(std::rand()%400,std::rand()%300);
        vitesse->setXY(std::rand()%20,std::rand()%20);
        size = std::rand()%3;
        Asteroid *asteroid= new Asteroid(*position,*vitesse,size);
        listeMissiles.push_back(asteroid);
    }
    delete(position);
    delete(vitesse);

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

            if (event.type == sf::Event::KeyPressed)
              switch(event.key.code){
                case sf::Keyboard::Up :
                  joueur->setAccLineaire(2);
                  break;
                case sf::Keyboard::Down :
                  joueur->setAccLineaire(-2);
                  break;
                case sf::Keyboard::Left :
                  joueur->setAccAngulaire(1);
                  break;
                case sf::Keyboard::Right :
                  joueur->setAccAngulaire(-1);
                  break;
                case sf::Keyboard::Escape :
                  window.close();
                default:
                  break;
                }
        }
        // Clear screen
        window.clear();
        // Draw the sprites
        window.draw(back);
        for(unsigned int i=0;i<listeMissiles.size();i++){
            listeMissiles[i]->move();
        }
        /*for(unsigned int i=0;i<listeMissiles.size();i++){ //TODO fix the collide loop
            for(unsigned int j=i+1;j<listeMissiles.size();i++)
              listeMissiles[i]->collide(listeMissiles[i]);
        }*/
        for(unsigned int i=0;i<listeMissiles.size();i++){
          window.draw(listeMissiles[i]->getSprite());
        }

        // Update the window
        window.display();
    }
    for(unsigned int i=0;i<listeMissiles.size();i++)
      delete listeMissiles[i];
    return EXIT_SUCCESS;
}
