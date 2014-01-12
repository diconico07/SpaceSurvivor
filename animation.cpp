#include "animation.h"

Animation::Animation(sf::Vector2u windowSize):windowSize(windowSize)
{
  position=0;
}

Animation::~Animation(){

}

void Animation::setTexture(sf::Texture& texture){


  sprite[0].setTexture(texture);
  sprite[1].setTexture(texture);
  sprite[2].setTexture(texture);
  sprite[3].setTexture(texture);
  sprite[0].setTextureRect(frames[0]);
  sprite[1].setTextureRect(frames[0]);
  sprite[2].setTextureRect(frames[0]);
  sprite[3].setTextureRect(frames[0]);
}

void Animation::play(){
  if(position==frames.size())
    throw 10;
  else
    position++;

  sprite[0].setTextureRect(frames[position]);
  sprite[1].setTextureRect(frames[position]);
  sprite[2].setTextureRect(frames[position]);
  sprite[3].setTextureRect(frames[position]);
}

void Animation::setPosition(sf::Vector2f spritePosition){
  sprite[0].setPosition(spritePosition);

  //Sets secondary sprites position if necessary in order to get seemless spherical area
  if(spritePosition.x>windowSize.x-size && spritePosition.y>windowSize.y-size){
    sprite[1].setPosition(spritePosition.x-windowSize.x,spritePosition.y-windowSize.y);
    sprite[2].setPosition(spritePosition.x-windowSize.x,spritePosition.y);
    sprite[3].setPosition(spritePosition.x,spritePosition.y-windowSize.y);
  }
  else if(spritePosition.x>windowSize.x-size && spritePosition.y<0+size){
    sprite[1].setPosition(spritePosition.x-windowSize.x,spritePosition.y+windowSize.y);
    sprite[2].setPosition(spritePosition.x-windowSize.x,spritePosition.y);
    sprite[3].setPosition(spritePosition.x,spritePosition.y+windowSize.y);
  }
  else if(spritePosition.x<0+size && spritePosition.y<0+size){
    sprite[1].setPosition(spritePosition.x+windowSize.x,spritePosition.y+windowSize.y);
    sprite[2].setPosition(spritePosition.x+windowSize.x,spritePosition.y);
    sprite[3].setPosition(spritePosition.x,spritePosition.y+windowSize.y);
  }
  else if(spritePosition.x<0+size && spritePosition.y>windowSize.y-size){
    sprite[1].setPosition(spritePosition.x+windowSize.x,spritePosition.y-windowSize.y);
    sprite[2].setPosition(spritePosition.x+windowSize.x,spritePosition.y);
    sprite[3].setPosition(spritePosition.x,spritePosition.y-windowSize.y);
  }
  else if(spritePosition.x>windowSize.x-size){
    sprite[1].setPosition(spritePosition.x-windowSize.x,spritePosition.y);
    sprite[2].setPosition(-size,-size);
    sprite[3].setPosition(-size,-size);
  }
  else if(spritePosition.y>windowSize.y-size){
    sprite[1].setPosition(spritePosition.x,spritePosition.y-windowSize.y);
    sprite[2].setPosition(-size,-size);
    sprite[3].setPosition(-size,-size);
  }
  else if(spritePosition.x<0+size){
    sprite[1].setPosition(spritePosition.x+windowSize.x,spritePosition.y);
    sprite[2].setPosition(-size,-size);
    sprite[3].setPosition(-size,-size);
  }
  else if(spritePosition.y<0+size){
    sprite[1].setPosition(spritePosition.x,spritePosition.y+windowSize.y);
    sprite[2].setPosition(-size,-size);
    sprite[3].setPosition(-size,-size);
  }
  else{
    sprite[1].setPosition(-size,-size);
    sprite[2].setPosition(-size,-size);
    sprite[3].setPosition(-size,-size);
  }
}

void Animation::setSize(int Size){
  size=Size;
  sprite[0].setScale(size/sprite[0].getLocalBounds().height,size/sprite[0].getLocalBounds().width);
  sprite[1].setScale(size/sprite[1].getLocalBounds().height,size/sprite[1].getLocalBounds().width);
  sprite[2].setScale(size/sprite[2].getLocalBounds().height,size/sprite[2].getLocalBounds().width);
  sprite[3].setScale(size/sprite[3].getLocalBounds().height,size/sprite[3].getLocalBounds().width);
}

void Animation::addFrame(sf::IntRect frame){
  frames.push_back(frame);
}

sf::Sprite Animation::getSprite(unsigned int n){
  return n<3?sprite[n]:sprite[0];
}
