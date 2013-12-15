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

void Missile::move(){
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

bool Missile::collide(Missile *c){
  unsigned int a=0,b=0;
  bool out=false;
  if(position.getX()<0+size || position.getX()>800-size)
    a++;
  if(position.getY()<0+size || position.getY()>600-size)
    a++;
  if(a==2)
    a++;

  if(c->getPosition().getX()<0+size || c->getPosition().getX()>800-size)
    b++;
  if(c->getPosition().getY()<0+size || c->getPosition().getY()>600-size)
    b++;
  if(a==2)
    b++;

  for(int i=0;i<=a;i++)
    for(int j=0;j<=a;j++)
      out|=Collision::PixelPerfectTest(sprite[i],c->getSprite(j));
  return out;
}
