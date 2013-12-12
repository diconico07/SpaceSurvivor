
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
public:

	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	Projectile ( );

	/**
	 * Empty Destructor
	 */
	virtual ~Projectile ( );

	// Static Public attributes
	//  

	// Public attributes
	//  


	// Public attribute accessor methods
	//  


	// Public attribute accessor methods
	//  



	/**
	 * @param  position
	 * @param  vitesse
	 */
	 Projectile (Vecteur position, Vecteur vitesse )
	{
	}


	/**
	 * @param  missile1
	 */
	void collide (Missile missile1 )
	{
	}


	/**
	 * penser au life -1
	 * 
	 */
	void move ( )
	{
	}

protected:

	// Static Protected attributes
	//  

	// Protected attributes
	//  

public:


	// Protected attribute accessor methods
	//  

protected:

public:


	// Protected attribute accessor methods
	//  

protected:


private:

	// Static Private attributes
	//  

	// Private attributes
	//  

	int life;
public:


	// Private attribute accessor methods
	//  

private:

public:


	// Private attribute accessor methods
	//  


	/**
	 * Set the value of life
	 * @param new_var the new value of life
	 */
	void setLife ( int new_var )	 {
			life = new_var;
	}

	/**
	 * Get the value of life
	 * @return the value of life
	 */
	int getLife ( )	 {
		return life;
	}
private:


	void initAttributes ( ) ;

};

#endif // PROJECTILE_H
