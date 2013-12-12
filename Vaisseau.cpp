#include "Vaisseau.h"

// Constructors/Destructors
//  

Vaisseau::Vaisseau ( ) {
initAttributes();
}

Vaisseau::~Vaisseau ( ) { }

//  
// Methods
//  



// Accessor methods
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

// Other methods
//  

void Vaisseau::initAttributes ( ) {
}

