#include "Projectile.h"

// Constructors/Destructors
//  

Projectile::Projectile ( ):Missile() {
    life=0;
}

Projectile::~Projectile ( ) { }

Projectile::Projectile(Vecteur Position, Vecteur Vitesse,int Angle){
    vitesse=Vitesse;
    position=Position;
    sf::Texture *texture=new sf::Texture();
    texture->loadFromFile("ressources/projectile.png");
    texture->setSmooth(true);

    sprite.setTexture(*texture);
    sprite.setPosition(Position.getX(),Position.getY());
    sprite.setScale(0.5,0.5);
    sprite.setOrigin(size/2,size/2);
    sprite.setRotation(Angle+90);
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

    sprite.setPosition(position.getX(),position.getY());
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
