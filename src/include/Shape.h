#ifndef SHAPE_H
#define SHAPE_H
#include "CustomSleep.h"
#include "CustomClear.h"
#include <iostream>
#include "MyEx.h"
#include <cmath>
#include <limits>
#include <iomanip>
#include <string>

enum Colors
{
    GREEN = 1, RED, YELLOW, BLUE, BLACK
};

class Shape
{
public:


    virtual ~Shape() = default;


protected:

    std::string Name;

    Colors Color;


    virtual void AreaCalculation() = 0;

    void SetReadColor(const std::string &);

    void SetReadName(const std::string&);

    void SetReadArea(const std::string&);

    void SetReadDistanceFromNullPoint(const std::string &);


    friend class MyList;

public:


    double DistanceFromNullPoint;

    double Area;

    std::string ReturnColor() const;


    Shape();


    void SetColor();

    virtual const std::string & GetName();

    Colors ReturnEnumColor() const;

};
#endif