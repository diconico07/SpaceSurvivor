#include "Asteroid.h"

// Constructors/Destructors
//  

/**
 * Empty Constructor
 */
Asteroid::Asteroid ( ) {
}

/**
 * Empty Destructor
 */
Asteroid::~Asteroid ( ) {
  delete sprite[0].getTexture();
}

/**
 * @param  Position
 * @param  Vitesse
 * @param  Size
 */
 Asteroid::Asteroid (Vecteur Position, Vecteur Vitesse, int Size )
{
     vitesse=Vitesse;
     size=256/(Size+2);
     position=Position;
     sf::Texture *texture=new sf::Texture();
     texture->loadFromFile("ressources/asteroid.png");
     texture->setSmooth(true);

     sprite[0].setTexture(*texture);
     sprite[0].setPosition(Position.getX(),Position.getY());
     sprite[0].setScale(1/((float)Size+3),1/((float)Size+3));
     sprite[0].setOrigin(size/2,size/2);

     sprite[1].setTexture(*texture);
     sprite[1].setPosition(-size,-size);
     sprite[1].setScale(1/((float)Size+3),1/((float)Size+3));
     sprite[1].setOrigin(size/2,size/2);

     sprite[2].setTexture(*texture);
     sprite[2].setPosition(-size,-size);
     sprite[2].setScale(1/((float)Size+3),1/((float)Size+3));
     sprite[2].setOrigin(size/2,size/2);

     sprite[3].setTexture(*texture);
     sprite[3].setPosition(-size,-size);
     sprite[3].setScale(1/((float)Size+3),1/((float)Size+3));
     sprite[3].setOrigin(size/2,size/2);
}

 //
 // Methods
 //

/**
 */
void Asteroid::move ( )
{

    position+=vitesse;

    if(position.getX()>800)
      position.setX(position.getX()-800);
    if(position.getY()>600)
      position.setY(position.getY()-600);
    if(position.getX()<0)
      position.setX(position.getX()+800);
    if(position.getY()<0)
      position.setY(position.getY()+600);


    sprite[0].setPosition(position.getX(),position.getY());

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
bool Asteroid::collide (Missile *missile1 )
{
}


