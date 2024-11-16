/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#pragma once


class Velocity;        // for Position::add()
class Acceleration;    // for Position::add()
class TestPosition;    // for the unit tests
class TestLander;      // for the unit tests

/*********************************************
 * POSITION
 * A single position on the screen
 *********************************************/
class Position
{
   friend TestPosition;    // for the unit tests
   friend TestLander;      // for the unit tests
   
public:
   // constructors
    Position() ;
    Position(const Position & pos) ;
   Position(double x, double y);

   // getters
    double getMetersX() const;
    double getMetersY() const;
    bool operator == (const Position & rhs) const;
    bool operator != (const Position & rhs) const;
    double getZoom();
    double getPixelsX();
    double getPixelsY();

   // setters
    void setMetersX(double x) ;
    void setMetersY(double y) ;
    void addX(double x);
    void addY(double y) ;
    void add (const Acceleration & a, const Velocity & v, double t);
    Position & operator = (const Position & rhs);
    void setZoom(double metersFromPixels);
    void setPixelsX(double xPixels);
    void setPixelsY(double yPixels);

    
    void addMetersX(double x);
    void addMetersY(double y);
    void addPixelsX(double x, double metersFromPixels);
    void addPixelsY(double y, double metersFromPixels);
    void add(Acceleration &a, Velocity &v);
    

private:
    double x;           // horizontal position
    double y;           // vertical position
    static double metersFromPixels;
};

