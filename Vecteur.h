
#ifndef VECTEUR_H
#define VECTEUR_H

#include <string>

/**
  * class Vecteur
  * 
  */

class Vecteur
{
private:

    // Static Private attributes
    //

    // Private attributes
    //

    int x;
    int y;

public:

	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	/**
	 * Full constructor
	 * @param  X
	 * @param  Y
	 */
	Vecteur (int X = 0, int Y = 0 ):x(X),y(Y){}


	/**
	 * Empty Destructor
	 */
	virtual ~Vecteur ( );


	// Public attribute accessor methods
	//  



	 /**
	  * Set the value of x
	  * @param new_var the new value of x
	  */
	 void setX ( int new_var );
	 /**
	  * Get the value of x
	  * @return the value of x
	  */
	 int getX ( );

         /**
          * Set the value of y
          * @param new_var the new value of y
          */
         void setY ( int new_var );

         /**
          * Get the value of y
          * @return the value of y
          */
         int getY ( );

         /**
          * @param  X
          * @param  Y
          */
         void setXY (int X, int Y );

	/**
	 * @param  module
	 */
	void setModule (int module );


	/**
	 * @param  Argument
	 */
	void setArgument (float Argument = 0 );

	/**
	 * @return int
	 */
	int getModule ( );


	/**
	 * @return float
	 */
	float getArgument ( );

	/**
	 * @param  Module
	 * @param  Argument
	 */
	void setModuleArgument (int Module, float Argument );


};

#endif // VECTEUR_H
