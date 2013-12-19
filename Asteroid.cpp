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

 void Asteroid::destroy(std::vector<Missile *> *objectList){
   //Split asteroids
   if(size>256/(4+2)){
       Vecteur Vitesse=Vecteur(std::rand()%6-3,std::rand()%6-3);
       int Size=256/size+1;
       Vecteur Position1=position+(256/(Size+3))*Vitesse;
       Vecteur Position2=position-(256/(Size+3))*Vitesse;
       Asteroid *ast1=new Asteroid(Position1,Vitesse,Size,windowSize);
       Asteroid *ast2=new Asteroid(Position2,Vitesse,Size,windowSize);
       objectList->push_back(ast1);
       objectList->push_back(ast2);
   }


 }

/**
 */




