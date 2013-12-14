
#ifndef VECTEUR_H
#define VECTEUR_H

#include <string>
#include <cmath>

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

    float x;
    float y;

public:

    Vecteur (int X = 0, int Y = 0 ):x(X),y(Y){}
    Vecteur (int Module,float Argument);
    virtual ~Vecteur ( );
    void setX ( int new_var );
    float getX ( );
    void setY ( int new_var );
    float getY ( );
    void setXY (int X, int Y );
    void setModule (int module );
    void setArgument (float Argument = 0 );
    int getModule ( );
    float getArgument ( );
    void setModuleArgument (int Module, float Argument );

    Vecteur& operator+=(Vecteur vecteur);

};

#endif // VECTEUR_H
