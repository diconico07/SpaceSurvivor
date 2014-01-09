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

    int life=50;

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
     Projectile (Vecteur position, Vecteur vitesse, int Angle, sf::Vector2u window, std::vector<sf::Sound> *listSound);

	/**
	 * Empty Destructor
	 */
	virtual ~Projectile ( );


	// Public attribute accessor methods
	//  

     int getLife();


	/**
	 * @param  missile1
	 */



	/**
	 * penser au life -1
	 * 
	 */
	void move ( );
	void destroy(std::vector<Missile *> *objectList, std::vector<sf::Sound> *soundList);


};

#endif // PROJECTILE_H
