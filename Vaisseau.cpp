#include "Vaisseau.h"

// Constructors/Destructors
//  

Vaisseau::Vaisseau ( ):Missile() {
    accLineaire=0;
    accAngulaire=0;
    vitesseAngulaire=0;
    angle=0;
    size=48;
    position.setXY(100,100);
    sf::Texture *texture=new sf::Texture();
    texture->loadFromFile("ressources/vaisseau.png");

    sprite.setTexture(*texture);
    sprite.setPosition(100,100);
    sprite.setOrigin(size/2,size/2);
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
  accel.setModuleArgument(-accLineaire,-angle);

  position+=vitesse;

  if(position.getX()>800)
    position.setX(position.getX()-800);
  if(position.getY()>600)
    position.setY(position.getY()-600);
  if(position.getX()<0)
    position.setX(position.getX()+800);
  if(position.getY()<0)
    position.setY(position.getY()+600);
  vitesse+=accel;

  angle+=vitesseAngulaire;
  vitesseAngulaire-=accAngulaire;

  accAngulaire=0;
  accLineaire=0;

  sprite.setPosition(position.getX(),position.getY());
  sprite.setRotation(angle);
}

/**
 * @return bool
 * @param  missile1
 */
bool Vaisseau::collide (Missile *missile1 )
{
}


