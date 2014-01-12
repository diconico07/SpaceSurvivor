#include "ressources.h"

namespace Ressources {
  sf::Texture Explosion, Vessel, Projectile, Asteroid;
  sf::SoundBuffer Death, Fire, Explosion_sound;

  void load(){
    Explosion.loadFromFile("ressources/explosion.png");
    Explosion.setSmooth(true);
    Collision::CreateTextureAndBitmask(Vessel,"ressources/vaisseau.png");
    Vessel.setSmooth(true);
    Collision::CreateTextureAndBitmask(Projectile,"ressources/projectile.png");
    Projectile.setSmooth(true);
    Collision::CreateTextureAndBitmask(Asteroid,"ressources/asteroid.png");
    Asteroid.setSmooth(true);

    Fire.loadFromFile("ressources/fire.wav");
    Death.loadFromFile("ressources/death.wav");
    Explosion_sound.loadFromFile("ressources/explosion2.wav");

  }

  sf::Texture& getExplosion(){
    return Explosion;
  }

  sf::Texture& getProjectile(){
    return Projectile;
  }

  sf::Texture& getVessel(){
    return Vessel;
  }

  sf::Texture& getAsteroid(){
    return Asteroid;
  }

  sf::SoundBuffer& getExplosionSound(){
    return Explosion_sound;
  }

  sf::SoundBuffer& getFireSound(){
    return Fire;
  }

  sf::SoundBuffer& getDeathSound(){
    return Death;
  }
}
