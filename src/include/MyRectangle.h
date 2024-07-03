#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
class MyRectangle : public Shape
{
protected:

    int RectangleTop ;

    int RectangleLeft;

    int RectangleBottom;

    int RectangleRight;


    void AreaCalculation() final;


public:

    MyRectangle( int Top, int Left, int Bottom, int Right);

    MyRectangle();

    ~MyRectangle() override = default;


    const std::string & GetName() final;


    int ReturnRectangleTop() const;

    int ReturnRectangleBottom() const;

    int ReturnRectangleLeft() const;

    int ReturnRectangleRight() const;


    double DistanceToOriginA() const;

    double DistanceToOriginB() const;

    double DistanceToOriginC() const;

    double DistanceToOriginD() const;


    void SetCord(int Top, int Bottom, int Left, int Right);
};

#endif
