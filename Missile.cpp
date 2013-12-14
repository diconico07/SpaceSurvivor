#include "Missile.h"

// Constructors/Destructors
//  

Missile::Missile ( ) {
    size = 0;
}


Missile::~Missile ( ) { }

//  
// Methods
//  

// Accessor methods
//

/**
 * Set the value of position
 * @param new_var the new value of position
 */
void Missile::setPosition ( Vecteur new_var )	 {
        position = new_var;
}

/**
 * Get the value of position
 * @return the value of position
 */
Vecteur Missile::getPosition ( )	 {
    return position;
}

/**
 * Set the value of vitesse
 * @param new_var the new value of vitesse
 */
void Missile::setVitesse ( Vecteur new_var )	 {
        vitesse = new_var;
}

/**
 * Get the value of vitesse
 * @return the value of vitesse
 */
Vecteur Missile::getVitesse ( )	 {
    return vitesse;
}

/**
 * Get the value of sprite
 * @return the value of sprite
 */
sf::Sprite Missile::getSprite (int n)	 {
  return sprite[n];
}

/**
 * Get the value of size
 * @return the value of size
 */
int Missile::getSize ( )	 {
    return size;
}

/**
 * Set the value of size
 * @param new_var the new value of size
 */
void Missile::setSize ( int new_var )	 {
        size = new_var;
}

// Other methods
//  

