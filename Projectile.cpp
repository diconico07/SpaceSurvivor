#include "Projectile.h"

// Constructors/Destructors
//  

Projectile::Projectile ( ):Missile() {
    life=0;
}

Projectile::~Projectile ( ) {
  delete sprite[0].getTexture();
}

Projectile::Projectile(Vecteur Position, Vecteur Vitesse, int Angle, sf::Vector2u window, std::vector<sf::Sound> *listSound){
    windowSize=window;
    vitesse=Vitesse;
    position=Position;
    sf::Texture *texture=new sf::Texture();
     Collision::CreateTextureAndBitmask(*texture,"ressources/projectile.png");
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

    sf::SoundBuffer* buffer=new sf::SoundBuffer();
    if(!buffer->loadFromFile("ressources/fire.wav"))
      std::cout<<"Error"<<std::endl;
    sf::Sound sound;
    listSound->push_back(sound);
    listSound->back().setBuffer(*buffer);
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
    life--;
    if(life<0)
      throw 10;
}

void Projectile::destroy(std::vector<Missile*> *objectList, std::vector<sf::Sound> *soundList){

}

