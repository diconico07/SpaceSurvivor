#include "Missile.h"

// Constructors/Destructors
//  

Missile::Missile ( ) {
initAttributes();
}

Missile::~Missile ( ) { }
// Constructors/Destructors
//


/**
 * Empty Constructor
 */
Missile ( );

/**
 * Empty Destructor
 */
virtual ~Missile ( );

//  
// Methods
//  

// Accessor methods
//

/**
 * Set the value of position
 * @param new_var the new value of position
 */
void setPosition ( Vecteur new_var )	 {
        position = new_var;
}

/**
 * Get the value of position
 * @return the value of position
 */
Vecteur getPosition ( )	 {
    return position;
}

/**
 * Set the value of vitesse
 * @param new_var the new value of vitesse
 */
void setVitesse ( Vecteur new_var )	 {
        vitesse = new_var;
}

/**
 * Get the value of vitesse
 * @return the value of vitesse
 */
Vecteur getVitesse ( )	 {
    return vitesse;
}

/**
 * Get the value of sprite
 * @return the value of sprite
 */
sf::Sprite getSprite ( )	 {
    return sprite;
}


/**
 * Get the value of size
 * @return the value of size
 */
int getSize ( )	 {
    return size;
}

/**
 * Set the value of size
 * @param new_var the new value of size
 */
void setSize ( int new_var )	 {
        size = new_var;
}

// Other methods
//  

/**
 */
virtual void move ( )
{
}

/**
 * @return bool
 * @param  c
 */
virtual bool collide (Missile c )
{
}

