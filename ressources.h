#ifndef RESSOURCES_H
#define RESSOURCES_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Collision.h"

namespace Ressources {
  void load();

  sf::Texture& getExplosion();
  sf::Texture& getProjectile();
  sf::Texture& getVessel();
  sf::Texture& getAsteroid();

  sf::SoundBuffer& getExplosionSound();
  sf::SoundBuffer& getFireSound();
  sf::SoundBuffer& getDeathSound();
}

#endif
