
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


	/**
	 * Empty Constructor
	 */
	Asteroid ( );

	/**
	 * Empty Destructor
	 */
	virtual ~Asteroid ( );

	// Static Public attributes
	//  

	// Public attributes
	//  


	// Public attribute accessor methods
	//  


	// Public attribute accessor methods
	//  



	/**
	 * @param  Position
	 * @param  Vitesse
	 * @param  Size
	 */
	 Asteroid (Vecteur Position, Vecteur Vitesse, int Size )
	{
	}


	/**
	 */
	void move ( )
	{
	}


	/**
	 * @return bool
	 * @param  missile1
	 */
	bool collide (Missile missile1 )
	{
	}

};

#endif // ASTEROID_H
