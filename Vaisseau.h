
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
	 * Empty Destructor
	 */
	virtual ~Vaisseau ( );

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
	 */
	 Vaisseau (Vecteur position )
	{
	}


	/**
	 * @return Projectile*
	 */
	Projectile* tir ( )
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

	int accLineaire;
	int accAngulaire;
	int vitesseAngulaire;
	int angle;
public:


	// Private attribute accessor methods
	//  

private:

public:


	// Private attribute accessor methods
	//  


	/**
	 * Set the value of accLineaire
	 * @param new_var the new value of accLineaire
	 */
	void setAccLineaire ( int new_var )	 {
			accLineaire = new_var;
	}

	/**
	 * Get the value of accLineaire
	 * @return the value of accLineaire
	 */
	int getAccLineaire ( )	 {
		return accLineaire;
	}

	/**
	 * Set the value of accAngulaire
	 * @param new_var the new value of accAngulaire
	 */
	void setAccAngulaire ( int new_var )	 {
			accAngulaire = new_var;
	}

	/**
	 * Get the value of accAngulaire
	 * @return the value of accAngulaire
	 */
	int getAccAngulaire ( )	 {
		return accAngulaire;
	}

	/**
	 * Set the value of vitesseAngulaire
	 * @param new_var the new value of vitesseAngulaire
	 */
	void setVitesseAngulaire ( int new_var )	 {
			vitesseAngulaire = new_var;
	}

	/**
	 * Get the value of vitesseAngulaire
	 * @return the value of vitesseAngulaire
	 */
	int getVitesseAngulaire ( )	 {
		return vitesseAngulaire;
	}

	/**
	 * Set the value of angle
	 * @param new_var the new value of angle
	 */
	void setAngle ( int new_var )	 {
			angle = new_var;
	}

	/**
	 * Get the value of angle
	 * @return the value of angle
	 */
	int getAngle ( )	 {
		return angle;
	}
private:


	void initAttributes ( ) ;

};

#endif // VAISSEAU_H
