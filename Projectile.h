#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Missile.h"

#include <string>

/**
  * class Projectile
  * 
  */

class Projectile : virtual public Missile
{
private:

    // Static Private attributes
    //

    // Private attributes
    //

    int life;

public:

	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	Projectile ( );

	/**
	 * @param  position
	 * @param  vitesse
	 */
	 Projectile (Vecteur position, Vecteur vitesse );

	/**
	 * Empty Destructor
	 */
	virtual ~Projectile ( );


	// Public attribute accessor methods
	//  


	/**
	 * @param  missile1
	 */
	bool collide (Missile *missile1 );


	/**
	 * penser au life -1
	 * 
	 */
	void move ( );


};

#endif // PROJECTILE_H
