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



     //Creates needed sprites and sets their properties
     sprite[0].setTexture(Ressources::getAsteroid());
     sprite[0].setPosition(Position.getX(),Position.getY());
     sprite[0].setScale(1/((float)Size+3),1/((float)Size+3));
     sprite[0].setOrigin(size/2,size/2);

     sprite[1].setTexture(Ressources::getAsteroid());
     sprite[1].setPosition(-size,-size);
     sprite[1].setScale(1/((float)Size+3),1/((float)Size+3));
     sprite[1].setOrigin(size/2,size/2);

     sprite[2].setTexture(Ressources::getAsteroid());
     sprite[2].setPosition(-size,-size);
     sprite[2].setScale(1/((float)Size+3),1/((float)Size+3));
     sprite[2].setOrigin(size/2,size/2);

     sprite[3].setTexture(Ressources::getAsteroid());
     sprite[3].setPosition(-size,-size);
     sprite[3].setScale(1/((float)Size+3),1/((float)Size+3));
     sprite[3].setOrigin(size/2,size/2);
}

 //
 // Methods
 //

 void Asteroid::destroy(std::vector<Missile *> *objectList, std::vector<sf::Sound> *soundList, std::vector<Animation> *animationList){

   //Load explosion sound and adds it to the vector then play it
   sf::Sound death;
   soundList->push_back(death);
   soundList->back().setBuffer(Ressources::getExplosionSound());
   soundList->back().play();

   Animation animation(windowSize);
   animationList->push_back(animation);
   for(int i=0; i<12;i++)
    animationList->back().addFrame(sf::IntRect(0+256*(i%3),0+128*(i/3),256,128));
   animationList->back().setTexture(Ressources::getExplosion());
   animationList->back().setPosition(sf::Vector2f(position.getX()-size/2,position.getY()-size/2));
   animationList->back().setSize(size);

   //Split asteroids if necessary
   if(size>256/(4+2)){
       Vecteur Vitesse;
       do
        Vitesse.setXY(std::rand()%6-3,std::rand()%6-3);
       while(Vitesse.getModule()==0);
       int Size=256/size+1;
       //Sets new asteroids position
       Vecteur Position1=position+(((256/(Size+3))/Vitesse.getModule())+3)*Vitesse;
       Vecteur Position2=position-(((256/(Size+3))/Vitesse.getModule())+3)*Vitesse;
       //Generate new asteroids and adds them to the vector
       Asteroid *ast1=new Asteroid(Position1,Vitesse,Size,windowSize);
       Asteroid *ast2=new Asteroid(Position2,-1*Vitesse,Size,windowSize);
       objectList->push_back(ast1);
       objectList->push_back(ast2);
   }


 }

/**
 */




