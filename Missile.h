
#ifndef MISSILE_H
#define MISSILE_H

#include <string>

/**
  * class Missile
  * 
  */

class Missile
{
public:

	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	Missile ( );

	/**
	 * Empty Destructor
	 */
	virtual ~Missile ( );

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
	 */
	void setPosition (Vecteur Position )
	{
	}


	/**
	 * @param  X
	 * @param  Y
	 */
	void setPosition (int X, int Y )
	{
	}


	/**
	 * @return Vecteur
	 */
	Vecteur getPosition ( )
	{
	}


	/**
	 * @param  Vitesse
	 */
	void setVitesse (Vecteur Vitesse )
	{
	}


	/**
	 * @param  X
	 * @param  Y
	 */
	void setVitesse (int X, int Y )
	{
	}


	/**
	 * @param  Module
	 * @param  Argument
	 */
	void setVitesse (int Module, float Argument )
	{
	}


	/**
	 * @return Vecteur
	 */
	Vecteur getVitesse ( )
	{
	}


	/**
	 */
	virtual void move ( )
	{
	}


	/**
	 * @return bool
	 * @param  c
	 */
	virtual bool collide (Missile c )
	{
	}

protected:

	// Static Protected attributes
	//  

	// Protected attributes
	//  

	Vecteur position;
	Vecteur vitesse;
	sf::Sprite sprite;
public:


	// Protected attribute accessor methods
	//  

protected:

public:


	// Protected attribute accessor methods
	//  


	/**
	 * Set the value of position
	 * @param new_var the new value of position
	 */
	void setPosition ( Vecteur new_var )	 {
			position = new_var;
	}

	/**
	 * Get the value of position
	 * @return the value of position
	 */
	Vecteur getPosition ( )	 {
		return position;
	}

	/**
	 * Set the value of vitesse
	 * @param new_var the new value of vitesse
	 */
	void setVitesse ( Vecteur new_var )	 {
			vitesse = new_var;
	}

	/**
	 * Get the value of vitesse
	 * @return the value of vitesse
	 */
	Vecteur getVitesse ( )	 {
		return vitesse;
	}

	/**
	 * Set the value of sprite
	 * @param new_var the new value of sprite
	 */
	void setSprite ( sf::Sprite new_var )	 {
			sprite = new_var;
	}

	/**
	 * Get the value of sprite
	 * @return the value of sprite
	 */
	sf::Sprite getSprite ( )	 {
		return sprite;
	}
protected:


private:

	// Static Private attributes
	//  

	// Private attributes
	//  

	int size;
public:


	// Private attribute accessor methods
	//  

private:

public:


	// Private attribute accessor methods
	//  


	/**
	 * Set the value of size
	 * @param new_var the new value of size
	 */
	void setSize ( int new_var )	 {
			size = new_var;
	}

	/**
	 * Get the value of size
	 * @return the value of size
	 */
	int getSize ( )	 {
		return size;
	}
private:


	void initAttributes ( ) ;

};

#endif // MISSILE_H
