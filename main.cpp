#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <typeinfo>

#include "Missile.h"
#include "Vaisseau.h"
#include "Asteroid.h"
#include "Vecteur.h"
const int Nombre_asteroids= 6;
const int Vitesse_projectiles=15;
const int shootDelay = 100; //100 millisecondes

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
    for(int i=0;i<Nombre_asteroids;i++){
        position->setXY(std::rand()%750,std::rand()%550);
        vitesse->setXY(std::rand()%6-3,std::rand()%6-3);
        size = std::rand()%5;
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
                  joueur->setAccLineaire(1);
                  break;
                case sf::Keyboard::Down :
                  joueur->setAccLineaire(-1);
                  break;
                case sf::Keyboard::Left :
                  joueur->setAccAngulaire(1);
                  break;
                case sf::Keyboard::Right :
                  joueur->setAccAngulaire(-1);
                  break;
                case sf::Keyboard::Space : { //Creates a new scope in order to allow variable declaration in the switch case
                    Projectile *projectile = new Projectile(joueur->getPosition()+joueur->getVitesse()+Vecteur(joueur->getSize(),(float)joueur->getAngle()),Vecteur(Vitesse_projectiles,(float)joueur->getAngle()),joueur->getAngle());
                  listeMissiles.push_back(projectile);
                  break;
                  }
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
            try{
            listeMissiles[i]->move();
            }
            catch(int e) {
              if(e==10){
                  delete listeMissiles[i];
                  listeMissiles.erase(listeMissiles.begin()+i);
                }
            }

        }
        for(unsigned int i=0;i<listeMissiles.size();i++){
            for(unsigned int j=i+1;j<listeMissiles.size();j++)
              if(listeMissiles[i]->collide(listeMissiles[j])){
                  delete listeMissiles[j];
                  delete listeMissiles[i];
                  listeMissiles.erase(listeMissiles.begin()+j);
                  listeMissiles.erase(listeMissiles.begin()+i);
                }

        }
        for(unsigned int i=0;i<listeMissiles.size();i++){
            for(int j=0;j<4;j++)
              window.draw(listeMissiles[i]->getSprite(j));
        }

        // Update the window
        window.display();
    }
    for(unsigned int i=0;i<listeMissiles.size();i++)
      delete listeMissiles[i];
    return EXIT_SUCCESS;
}
