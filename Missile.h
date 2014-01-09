
#ifndef MISSILE_H
#define MISSILE_H

#include <string>
#include <iostream>
#include "Vecteur.h"
#include "Collision.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/**
  * class Missile
  * 
  */

class Missile
{
protected:

    // Static Protected attributes
    //

    // Protected attributes
    //

    Vecteur position;
    Vecteur vitesse;
    sf::Sprite sprite[4];
    int size;
    sf::Vector2u windowSize;
    sf::Sound createSound;

public:

	// Constructors/Destructors
    //

	Missile ( );
    virtual ~Missile ( );

    //
    //Methods
    //

    //Accessors methods
    //

    void setPosition ( Vecteur new_var );
    void setVitesse ( Vecteur new_var );
    void setSize ( int new_var );

    int getSize ( );
    Vecteur getVitesse ( );
    Vecteur getPosition ( );

    //Other methods
    //

    virtual void move ( );
    virtual bool collide (Missile *c );
    sf::Sprite getSprite (int n);
    virtual void destroy(std::vector<Missile*> *objectList)=0;

};

#endif // MISSILE_H
