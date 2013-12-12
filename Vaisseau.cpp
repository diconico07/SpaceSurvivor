#include "Vaisseau.h"

// Constructors/Destructors
//  

Vaisseau::Vaisseau ( ):Missile() {
    accLineaire=0;
    accAngulaire=0;
    vitesseAngulaire=0;
    angle=0;
    position.setXY(100,100);
    sf::Texture *texture=new Texture();
    texture->loadFromFile("ressource/vaisseau.png");
    sprite.setTexture(texture);
}

Vaisseau::~Vaisseau ( ) {
  delete sprite.getTexture();
}

//  
// Methods
//  


// Accessor methods
//  

/**
 * Set the value of accLineaire
 * @param new_var the new value of accLineaire
 */
void Vaisseau::setAccLineaire ( int new_var )	 {
                accLineaire = new_var;
}

/**
 * Get the value of accLineaire
 * @return the value of accLineaire
 */
int Vaisseau::getAccLineaire ( )	 {
        return accLineaire;
}

/**
 * Set the value of accAngulaire
 * @param new_var the new value of accAngulaire
 */
void Vaisseau::setAccAngulaire ( int new_var )	 {
                accAngulaire = new_var;
}

/**
 * Get the value of accAngulaire
 * @return the value of accAngulaire
 */
int Vaisseau::getAccAngulaire ( )	 {
        return accAngulaire;
}

//Other methods
//


void Vaisseau::move(){
  Vecteur accel;
  accel.setModuleArgument(accLineaire,angle);

  position+=vitesse;
  vitesse+=accel;

  angle+=vitesseAngulaire;
  vitesseAngulaire+=accAngulaire;
}

/**
 * @return bool
 * @param  missile1
 */
bool Vaisseau::collide (Missile *missile1 )
{
}


