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
     accLineaire=0;
     accAngulaire=0;
     vitesseAngulaire=0;
     vitesse.setXY(Vitesse.getX(),Vitesse.getY());
     angle=0;
     size=Size;
     position.setXY(Position.getX(),Position.getY());
     sf::Texture *texture=new sf::Texture();
     texture->loadFromFile("ressources/asteroid.png");
     texture->setSmooth(true);

     sprite.setTexture(*texture);
     sprite.setPosition(Position.getX(),Position.getY());
//     sprite.setOrigin(size/2,size/2);
}

 //
 // Methods
 //

/**
 */
void Asteroid::move ( )
{
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

    sprite.setPosition(position.getX(),position.getY());
    sprite.setRotation(angle+90);
}

/**
 * @return bool
 * @param  missile1
 */
bool Asteroid::collide (Missile *missile1 )
{
}


