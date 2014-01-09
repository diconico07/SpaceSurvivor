
#ifndef VAISSEAU_H
#define VAISSEAU_H
#include "Missile.h"
#include "Projectile.h"
#include "Vecteur.h"

#include <string>
#include <iostream>
#define VITESSE_MAX 20
/**
  * class Vaisseau
  * 
  */

class Vaisseau : virtual public Missile
{
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

	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	Vaisseau (sf::Vector2u window);

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
      * @brief get the value of Angle
      * @return
      */
     int getAngle();

	/**
	 * @return Projectile*
	 */
	Projectile* tir ( );


	/**
	 */
	void move ( );
	void destroy(std::vector<Missile *> *objectList, std::vector<sf::Sound> *soundList);




};

#endif // VAISSEAU_H
