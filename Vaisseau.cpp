#include "Vaisseau.h"

// Constructors/Destructors
//  

Vaisseau::Vaisseau ( sf::Vector2u window): Missile() {
    windowSize=window;
    accLineaire=0;
    accAngulaire=0;
    vitesseAngulaire=0;
    angle=0;
    size=48;
    position.setXY(windowSize.x/2,windowSize.y/2);

    //Load the texture
    sf::Texture *texture=new sf::Texture();
    Collision::CreateTextureAndBitmask(*texture,"ressources/vaisseau.png");
    texture->setSmooth(true);

    //Sets the sprites properties
    sprite[0].setTexture(*texture);
    sprite[0].setPosition(400,300);
    sprite[0].setOrigin(size/2,size/2);

    sprite[1].setTexture(*texture);
    sprite[1].setPosition(-size,-size);
    sprite[1].setOrigin(size/2,size/2);

    sprite[2].setTexture(*texture);
    sprite[2].setPosition(-size,-size);
    sprite[2].setOrigin(size/2,size/2);

    sprite[3].setTexture(*texture);
    sprite[3].setPosition(-size,-size);
    sprite[3].setOrigin(size/2,size/2);
}

Vaisseau::~Vaisseau ( ) {
  delete sprite[0].getTexture();
}

//  
// Methods
//  


// Accessor methods
//  

/**
 * Set the value of accLineaire
 * @param new_var the new value of accLineaire
 */
void Vaisseau::setAccLineaire ( int new_var )	 {
                accLineaire = new_var;
}

/**
 * Get the value of accLineaire
 * @return the value of accLineaire
 */
int Vaisseau::getAccLineaire ( )	 {
        return accLineaire;
}

/**
 * Set the value of accAngulaire
 * @param new_var the new value of accAngulaire
 */
void Vaisseau::setAccAngulaire ( int new_var )	 {
                accAngulaire = new_var;
}

/**
 * Get the value of accAngulaire
 * @return the value of accAngulaire
 */
int Vaisseau::getAccAngulaire ( )	 {
        return accAngulaire;
}

int Vaisseau::getAngle(){
    return angle;
}

//Other methods
//


void Vaisseau::move(){
  Missile::move();

  Vecteur accel;
  accel.setModuleArgument(accLineaire,angle);

  //Sets speed using acceleration
  vitesse+=accel;

  //Sets angle and angular speed
  angle+=vitesseAngulaire;
  vitesseAngulaire-=accAngulaire;

  //Set a maximum speed
  if(vitesseAngulaire>VITESSE_MAX)
    vitesseAngulaire=VITESSE_MAX;
  if(vitesse.getModule()>VITESSE_MAX)
    vitesse.setModule(VITESSE_MAX);

  //reset the accelerations
  accAngulaire=0;
  accLineaire=0;

  //correctly moves the sprites
  sprite[0].setPosition(position.getX(),position.getY());
  sprite[0].setRotation(angle-90);

  sprite[1].setRotation(angle-90);
  sprite[2].setRotation(angle-90);
  sprite[3].setRotation(angle-90);

}

void Vaisseau::destroy(std::vector<Missile *> *objectList, std::vector<sf::Sound> *soundList){

  //Load death sound adds it to the vector and plays it
  sf::SoundBuffer *buffer=new sf::SoundBuffer();
  if(!buffer->loadFromFile("ressources/death.wav"))
    std::cout<<"Error"<<std::endl;
  sf::Sound death;
  soundList->push_back(death);
  soundList->back().setBuffer(*buffer);
  soundList->back().play();

}


