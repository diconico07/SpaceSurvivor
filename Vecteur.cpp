#include "Vecteur.h"

// Constructors/Destructors
//  

Vecteur::Vecteur ( ) {

}

Vecteur::~Vecteur ( ) { }

//  
// Methods
//  


// Accessor methods
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

/**
 * @param  X
 * @param  Y
 */
void setXY (int X, int Y )
{
  x=X;
  y=Y;
}

