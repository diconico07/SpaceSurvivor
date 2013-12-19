#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdlib>

#include "Missile.h"
#include "Vaisseau.h"
#include "Asteroid.h"
#include "Vecteur.h"
const int Nombre_asteroids= 6;
const int Vitesse_projectiles=15;
const int shootDelay = 100; //100 millisecondes
const int asteroidDelay = 1000; //1 seconde

class Game
{
public:
    //Attributes
    std::vector<Missile*> listeMissiles;
    Vaisseau *joueur;
    bool joueurIsAlive;
    sf::RenderWindow *Window;
    sf::Clock fire_delay, asteroid_delay;
    sf::Sprite back;

    //Constructors
    Game();

    Game(sf::RenderWindow *Window);

    ~Game();

    void playGame();

};

#endif // GAME_H
