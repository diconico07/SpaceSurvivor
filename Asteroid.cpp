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
 Asteroid::Asteroid (Vecteur Position, Vecteur Vitesse, int Size ,sf::Vector2u window)
{
     name="asteroid";
     vitesse=Vitesse;
     windowSize=window;
     size=256/(Size+2);
     position=Position;

     sf::Texture *texture=new sf::Texture();
     Collision::CreateTextureAndBitmask(*texture,"ressources/asteroid.png");
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

Missile Asteroid::split(Missile *asteroid, sf::RenderWindow *Window){
    Vecteur *nPos = new Vecteur(asteroid->getPosition().getX()+3*asteroid->getVitesse().getX(),asteroid->getPosition().getY()+3*asteroid->getVitesse().getY());
    Vecteur *nVit =new Vecteur(std::rand()%6-3,std::rand()%6-3);
    Missile *ast1 = new Asteroid(*nPos,*nVit,asteroid->getSize()-1,Window->getSize());
    asteroid->setSize(asteroid->getSize()-1);
    asteroid->setVitesse(Vecteur(std::rand()%6-3,std::rand()%6-3));
    return ast1;
}

/**
 */




