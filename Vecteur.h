
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

	Vecteur (int X = 0, int Y = 0 ):x(X),y(Y){}
	virtual ~Vecteur ( );

     void setX ( int new_var );
     int getX ( );
     void setY ( int new_var );
     int getY ( );
     void setXY (int X, int Y );
    void setModule (int module );
    void setArgument (float Argument = 0 );
    int getModule ( );
    float getArgument ( );
	void setModuleArgument (int Module, float Argument );

    Vecteur& Vecteur::operator+=(Vecteur vecteur);

};

#endif // VECTEUR_H
