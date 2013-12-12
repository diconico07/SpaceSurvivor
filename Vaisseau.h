
#ifndef VAISSEAU_H
#define VAISSEAU_H
#include "Missile.h"

#include <string>

/**
  * class Vaisseau
  * 
  */

class Vaisseau : virtual public Missile
{
public:

	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	Vaisseau ( );

	/**
	 * @param  position
	 */
	 Vaisseau (Vecteur position );

	/**
	 * Empty Destructor
	 */
	virtual ~Vaisseau ( );


	// Public attribute accessor methods
	//  


	 /**
	  * Set the value of accLineaire
	  * @param new_var the new value of accLineaire
	  */
	 void setAccLineaire ( int new_var );

         /**
          * Get the value of accLineaire
          * @return the value of accLineaire
          */
         int getAccLineaire ( );

         /**
          * Set the value of accAngulaire
          * @param new_var the new value of accAngulaire
          */
         void setAccAngulaire ( int new_var );

         /**
          * Get the value of accAngulaire
          * @return the value of accAngulaire
          */
         int getAccAngulaire ( );

	/**
	 * @return Projectile*
	 */
	Projectile* tir ( );


	/**
	 */
	void move ( );


	/**
	 * @return bool
	 * @param  missile1
	 */
	bool collide (Missile missile1 );


private:

	// Static Private attributes
	//  

	// Private attributes
	//  

	int accLineaire;
	int accAngulaire;
	int vitesseAngulaire;
	int angle;

};

#endif // VAISSEAU_H
