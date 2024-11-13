/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include "velocity.h" // for M_PI which is 3.14159

class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestAngle;
class TestLander;

 /************************************
  * ANGLE
  ************************************/
class Angle
{
public:
   friend TestAcceleration;
   friend TestVelocity;
   friend TestAngle;
   friend TestLander;
   
   // Constructors
    Angle();
    Angle(const Angle& rhs);
    Angle(double degrees);

   // Getters
    double getDegrees() const ;
    double getRadians() const ;
    double getDX();
    double getDY();
    
    

   // Setters
    void setDegrees(double degrees) ;
    void setRadians(double radians) ;
    void setUp()                    ;
    void setDown()                  ;
    void setRight()                 ;
    void setLeft()                  ;
    void reverse()                  ;
    Angle& add(double delta);
    void setDxDy(double dx, double dy);
    
    int  isLeft()      const { return isLeftPress;  };
    int  isRight()     const { return isRightPress; };

private:
   double normalize(double radians) const;
    
   double radians;
    double dx;
    double dy;
    Velocity velocity;
    
    static int  isLeftPress;          //    "   left       "
    static int  isRightPress;         //    "   right      "
    
    // 360 degrees equals 2 PI radians
};

