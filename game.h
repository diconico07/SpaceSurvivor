#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Missile.h"
#include "Vaisseau.h"
#include "Asteroid.h"
#include "Vecteur.h"

const int Nombre_asteroids= 6;
const int Vitesse_projectiles=15;
const int shootDelay = 100; //100 millisecondes
const int asteroidDelay = 1000; //1 seconde

const int safeZone = 300;

class Game
{
public:
    //Attributes
    std::vector<Missile*> listeMissiles;
    std::vector<sf::Sound> listeSound;
    Vaisseau *joueur;
    bool joueurIsAlive;
    bool hardcoreMode;
    sf::RenderWindow *Window;
    sf::Clock fire_delay, asteroid_delay, move_delay,game_delay;
    sf::Sprite back;
    sf::Music music;
    int score;

    //Constructors
    Game();

    Game(sf::RenderWindow *Window);

    ~Game();

    void playGame();
    void spawnAsteroid();

};

#endif // GAME_H
