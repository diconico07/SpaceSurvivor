#include "Projectile.h"

// Constructors/Destructors
//  

Projectile::Projectile ( ):Missile() {
    life=0;
}

Projectile::~Projectile ( ) {

}

Projectile::Projectile(Vecteur Position, Vecteur Vitesse, int Angle, sf::Vector2u window, std::vector<sf::Sound> *listSound){
    windowSize=window;
    vitesse=Vitesse;
    position=Position;

    //Load Textures


    size=16;

    //Sets sprites properties
    sprite[0].setTexture(Ressources::getProjectile());
    sprite[0].setPosition(Position.getX(),Position.getY());
    sprite[0].setScale(0.5,0.5);
    sprite[0].setOrigin(size/2,size/2);
    sprite[0].setRotation(Angle+90);

    sprite[1].setTexture(Ressources::getProjectile());
    sprite[1].setPosition(-size,-size);
    sprite[1].setScale(0.5,0.5);
    sprite[1].setOrigin(size/2,size/2);
    sprite[1].setRotation(Angle+90);

    sprite[2].setTexture(Ressources::getProjectile());
    sprite[2].setPosition(-size,-size);
    sprite[2].setScale(0.5,0.5);
    sprite[2].setOrigin(size/2,size/2);
    sprite[2].setRotation(Angle+90);

    sprite[3].setTexture(Ressources::getProjectile());
    sprite[3].setPosition(-size,-size);
    sprite[3].setScale(0.5,0.5);
    sprite[3].setOrigin(size/2,size/2);
    sprite[3].setRotation(Angle+90);

    //Load fire sound, adds it to the vector and plays it
    sf::Sound sound;
    listSound->push_back(sound);
    listSound->back().setBuffer(Ressources::getFireSound());
    listSound->back().setVolume(30);
    listSound->back().play();


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
  Missile::move();
  //decrease life and throw exception to get the Projectile destroyed if the Projectile is no longer alive
    life--;
    if(life<0)
      throw 10;
}

void Projectile::destroy(std::vector<Missile*> *objectList, std::vector<sf::Sound> *soundList, std::vector<Animation> *animationList){

}
