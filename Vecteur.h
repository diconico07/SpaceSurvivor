
#ifndef VECTEUR_H
#define VECTEUR_H

#include <string>

/**
  * class Vecteur
  * 
  */

class Vecteur
{
public:

	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	Vecteur ( );

	/**
	 * Empty Destructor
	 */
	virtual ~Vecteur ( );

	// Static Public attributes
	//  

	// Public attributes
	//  


	// Public attribute accessor methods
	//  


	// Public attribute accessor methods
	//  



	/**
	 * @param  X
	 * @param  Y
	 */
	 Vecteur (int X = 0, int Y = 0 )
	{
	}


	/**
	 * @param  module
	 */
	void setModule (int module )
	{
	}


	/**
	 * @param  Argument
	 */
	void setArgument (float Argument = 0 )
	{
	}


	/**
	 * @param  X
	 */
	void setX (int X = 0 )
	{
	}


	/**
	 * @param  Y
	 */
	void setY (int Y = 0 )
	{
	}


	/**
	 * @param  X
	 * @param  Y
	 */
	void setXY (int X, int Y )
	{
	}


	/**
	 * @return int
	 */
	int getX ( )
	{
	}


	/**
	 * @return int
	 */
	int getY ( )
	{
	}


	/**
	 * @return int
	 */
	int getModule ( )
	{
	}


	/**
	 * @return float
	 */
	float getArgument ( )
	{
	}


	/**
	 * @param  Module
	 * @param  Argument
	 */
	void setModuleArgument (int Module, float Argument )
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

	int x;
	int y;
public:


	// Private attribute accessor methods
	//  

private:

public:


	// Private attribute accessor methods
	//  


	/**
	 * Set the value of x
	 * @param new_var the new value of x
	 */
	void setX ( int new_var )	 {
			x = new_var;
	}

	/**
	 * Get the value of x
	 * @return the value of x
	 */
	int getX ( )	 {
		return x;
	}

	/**
	 * Set the value of y
	 * @param new_var the new value of y
	 */
	void setY ( int new_var )	 {
			y = new_var;
	}

	/**
	 * Get the value of y
	 * @return the value of y
	 */
	int getY ( )	 {
		return y;
	}
private:


	void initAttributes ( ) ;

};

#endif // VECTEUR_H
