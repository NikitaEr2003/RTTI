#ifndef MYCIRCLE_H
#define MYCIRCLE_H
#include "Shape.h"
class MyCircle : public Shape
{
protected:


    int CircleX, CircleY, CircleRadius;


    void AreaCalculation()  final;


public:


    MyCircle(int X, int Y, int Radius);

    MyCircle();


    const std::string & GetName() final;


    int ReturnCircleX() const ;

    int ReturnCircleY() const ;

    int ReturnCircleRadius() const ;


    double DistanceToOrigin() const;


    void SetCord(int X, int Y, int Radius);
};
#endif