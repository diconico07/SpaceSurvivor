#include "Vecteur.h"

// Constructors/Destructors
//  

Vecteur::Vecteur(int Module, float Argument){
  this->setModuleArgument(Module,Argument);
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
void Vecteur::setX ( int new_var )	 {
                x = new_var;
}

/**
 * Get the value of x
 * @return the value of x
 */
float Vecteur::getX( )	 {
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
float Vecteur::getY ( )	 {
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

/**
  *
  */
void Vecteur::setModuleArgument (int Module, float Argument ){
    x=Module*std::cos(Argument*M_PI/180);
    y=Module*std::sin(Argument*M_PI/180);
    }

int Vecteur::getModule(){
  return std::sqrt(x*x+y*y);
}

float Vecteur::getArgument(){
  return (std::atan2(y,x)*180/M_PI);
}

void Vecteur::setModule(int module){
  float argument=this->getArgument();
  x=module*std::cos(argument*M_PI/180);
  y=module*std::sin(argument*M_PI/180);
}

// Surchage opérateurs
//

Vecteur& Vecteur::operator+=(Vecteur vecteur){
    x+=vecteur.getX();
    y+=vecteur.getY();
    return *this;
}

Vecteur& Vecteur::operator+(Vecteur vecteur){
    return (Vecteur) *this+=vecteur;
}

Vecteur& Vecteur::operator-=(Vecteur vecteur){
    x-=vecteur.getX();
    y-=vecteur.getY();
    return *this;
}

Vecteur& Vecteur::operator-(Vecteur vecteur){
    return (Vecteur) *this-=vecteur;
}

Vecteur operator*(const int i,Vecteur vecteur){
  return Vecteur(vecteur.getX()*i,vecteur.getY()*i);
}

Vecteur operator*(Vecteur vecteur,const int i){
  return Vecteur(vecteur.getX()*i,vecteur.getY()*i);
}
