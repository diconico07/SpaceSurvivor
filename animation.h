
#ifndef ANIMATION_H
#define ANIMATION_H

#include<vector>
#include<string>
#include<SFML/Graphics.hpp>

class Animation
{
  std::vector<sf::IntRect> frames;
  sf::Sprite sprite[4];
  unsigned int position;
  int size;
  sf::Vector2u windowSize;
public:
  Animation(sf::Vector2u windowSize);
  ~Animation();
  void setTexture(sf::Texture &texture);
  void setPosition(sf::Vector2f);
  void setSize(int);
  void addFrame(sf::IntRect);
  void play();
  sf::Sprite getSprite(unsigned int n);
};

#endif // ANIMATION_H
