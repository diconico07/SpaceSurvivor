#include "Vecteur.h"

// Constructors/Destructors
//  


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
void Vecteur::setX ( int new_var )	 {
                x = new_var;
}

/**
 * Get the value of x
 * @return the value of x
 */
int Vecteur::getX ( )	 {
        return x;
}

/**
 * Set the value of y
 * @param new_var the new value of y
 */
void Vecteur::setY ( int new_var )	 {
                y = new_var;
}

/**
 * Get the value of y
 * @return the value of y
 */
int Vecteur::getY ( )	 {
        return y;
}

/**
 * @param  X
 * @param  Y
 */
void Vecteur::setXY (int X, int Y )
{
  x=X;
  y=Y;
}

// Surchage opérateurs
//

Vecteur& Vecteur::operator+=(Vecteur vecteur){
    x+=vecteur.getX();
    y+=vecteur.getY();
    return *this;
}
