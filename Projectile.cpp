#include "Projectile.h"

// Constructors/Destructors
//  

Projectile::Projectile ( ):Missile() {
    life=0;
}

Projectile::~Projectile ( ) {
  delete sprite[0].getTexture();
}

Projectile::Projectile(Vecteur Position, Vecteur Vitesse,int Angle){
    vitesse=Vitesse;
    position=Position;
    sf::Texture *texture=new sf::Texture();
    texture->loadFromFile("ressources/projectile.png");
    texture->setSmooth(true);
    size=16;

    sprite[0].setTexture(*texture);
    sprite[0].setPosition(Position.getX(),Position.getY());
    sprite[0].setScale(0.5,0.5);
    sprite[0].setOrigin(size/2,size/2);
    sprite[0].setRotation(Angle+90);

    sprite[1].setTexture(*texture);
    sprite[1].setPosition(-size,-size);
    sprite[1].setScale(0.5,0.5);
    sprite[1].setOrigin(size/2,size/2);
    sprite[1].setRotation(Angle+90);

    sprite[2].setTexture(*texture);
    sprite[2].setPosition(-size,-size);
    sprite[2].setScale(0.5,0.5);
    sprite[2].setOrigin(size/2,size/2);
    sprite[2].setRotation(Angle+90);

    sprite[3].setTexture(*texture);
    sprite[3].setPosition(-size,-size);
    sprite[3].setScale(0.5,0.5);
    sprite[3].setOrigin(size/2,size/2);
    sprite[3].setRotation(Angle+90);
}

//  
// Methods
//  


// Accessor methods
//  

int Projectile::getLife(){
    return life;
}

// Other methods
//  

/**
 */
void Projectile::move ( )
{
    position+=vitesse;
    life--;
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

    if(life<0)
      throw 10;
}

/**
 * @return bool
 * @param  missile1
 */
bool Projectile::collide (Missile *missile1 )
{
}
