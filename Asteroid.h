
#ifndef ASTEROID_H
#define ASTEROID_H
#include "Missile.h"

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
    Asteroid (Vecteur Position, Vecteur Vitesse, int Size );

    //Other Methods
    //

    void move ( );
    bool collide (Missile *missile1 );

};

#endif // ASTEROID_H
