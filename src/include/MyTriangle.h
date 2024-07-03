#ifndef MYTRIANGLE_H
#define MYTRIANGLE_H
#include "Shape.h"
class MyTriangle : public Shape
{
protected:

    int TreugX1, TreugY1, TreugX2, TreugY2, TreugX3, TreugY3;


    void AreaCalculation()  final;


public:


    MyTriangle(int X1, int Y1, int X2, int Y2, int X3, int Y3);

    MyTriangle();

    ~MyTriangle() override = default;


    const std::string & GetName() final;


    int ReturnTreugX1() const;

    int ReturnTreugY1() const;

    int ReturnTreugX2() const;

    int ReturnTreugY2() const;

    int ReturnTreugX3() const;

    int ReturnTreugY3() const;


    double DistanceToOriginA() const;

    double DistanceToOriginB() const;

    double DistanceToOriginC() const;


    void SetCord(int X1, int Y1, int X2, int Y2, int X3, int Y3);

};
#endif