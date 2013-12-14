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
Asteroid::~Asteroid ( ) { }

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

     sprite.setTexture(*texture);
     sprite.setPosition(Position.getX(),Position.getY());
     sprite.setScale(1/((float)Size+3),1/((float)Size+3));
     sprite.setOrigin(size/2,size/2);
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


    sprite.setPosition(position.getX(),position.getY());
}

/**
 * @return bool
 * @param  missile1
 */
bool Asteroid::collide (Missile *missile1 )
{
}


