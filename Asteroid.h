
#ifndef ASTEROID_H
#define ASTEROID_H
#include "Missile.h"
#include <cstdlib>

#include <string>

/**
  * class Asteroid
  * 
  */

class Asteroid : virtual public Missile
{
public:

	// Constructors/Destructors
	//  

    Asteroid ( );
    virtual ~Asteroid ( );
    Asteroid (Vecteur Position, Vecteur Vitesse, int Size , sf::Vector2u window);

    //Other Methods
    //
    void destroy(std::vector<Missile *> *objectList, std::vector<sf::Sound> *soundList, std::vector<Animation> *animationList);
    //void move ( );


};

#endif // ASTEROID_H
