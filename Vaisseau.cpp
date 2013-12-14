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
    texture->setSmooth(true);

    sprite[0].setTexture(*texture);
    sprite[0].setPosition(100,100);
    sprite[0].setOrigin(size/2,size/2);

    sprite[1].setTexture(*texture);
    sprite[1].setPosition(-size,-size);
    sprite[1].setOrigin(size/2,size/2);

    sprite[2].setTexture(*texture);
    sprite[2].setPosition(-size,-size);
    sprite[2].setOrigin(size/2,size/2);

    sprite[3].setTexture(*texture);
    sprite[3].setPosition(-size,-size);
    sprite[3].setOrigin(size/2,size/2);
}

Vaisseau::~Vaisseau ( ) {
  delete sprite[0].getTexture();
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

int Vaisseau::getAngle(){
    return angle;
}

//Other methods
//


void Vaisseau::move(){
  Vecteur accel;
  accel.setModuleArgument(accLineaire,angle);

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

  if(vitesseAngulaire>VITESSE_MAX)
    vitesseAngulaire=VITESSE_MAX;
  if(vitesse.getModule()>VITESSE_MAX)
    vitesse.setModule(VITESSE_MAX);

  accAngulaire=0;
  accLineaire=0;

  sprite[0].setPosition(position.getX(),position.getY());
  sprite[0].setRotation(angle+90);

  sprite[1].setRotation(angle+90);
  sprite[2].setRotation(angle+90);
  sprite[3].setRotation(angle+90);

  if(position.getX()>800-size && position.getY()>600-size){
    sprite[1].setPosition(position.getX()-800,position.getY()-600);
    sprite[2].setPosition(position.getX()-800,position.getY());
    sprite[3].setPosition(position.getX(),position.getY()-600);
  }
  else if(position.getX()>800-size && position.getY()<0+size){
    sprite[1].setPosition(position.getX()-800,position.getY()+600);
    sprite[2].setPosition(position.getX()-800,position.getY());
    sprite[3].setPosition(position.getX(),position.getY()+600);
  }
  else if(position.getX()<0+size && position.getY()<0+size){
    sprite[1].setPosition(position.getX()+800,position.getY()+600);
    sprite[2].setPosition(position.getX()+800,position.getY());
    sprite[3].setPosition(position.getX(),position.getY()+600);
  }
  else if(position.getX()<0+size && position.getY()>600-size){
    sprite[1].setPosition(position.getX()+800,position.getY()-600);
    sprite[2].setPosition(position.getX()+800,position.getY());
    sprite[3].setPosition(position.getX(),position.getY()-600);
  }
  else if(position.getX()>800-size){
    sprite[1].setPosition(position.getX()-800,position.getY());
    sprite[2].setPosition(-size,-size);
    sprite[3].setPosition(-size,-size);
  }
  else if(position.getY()>600-size){
    sprite[1].setPosition(position.getX(),position.getY()-600);
    sprite[2].setPosition(-size,-size);
    sprite[3].setPosition(-size,-size);
  }
  else if(position.getX()<0+size){
    sprite[1].setPosition(position.getX()+800,position.getY());
    sprite[2].setPosition(-size,-size);
    sprite[3].setPosition(-size,-size);
  }
  else if(position.getY()<0+size){
    sprite[1].setPosition(position.getX(),position.getY()+600);
    sprite[2].setPosition(-size,-size);
    sprite[3].setPosition(-size,-size);
  }
  else{
    sprite[1].setPosition(-size,-size);
    sprite[2].setPosition(-size,-size);
    sprite[3].setPosition(-size,-size);
  }
}

/**
 * @return bool
 * @param  missile1
 */
bool Vaisseau::collide (Missile *missile1 )
{
}


