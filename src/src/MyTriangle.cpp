#include "MyTriangle.h"
MyTriangle::MyTriangle(int X1, int Y1, int X2, int Y2, int X3, int Y3)
    : TreugX1(X1), TreugY1(Y1), TreugX2(X2), TreugY2(Y2), TreugX3(X3), TreugY3(Y3)
    {

        Name = "MyTriangle";

        AreaCalculation();

        this->DistanceFromNullPoint = DistanceToOriginA()+DistanceToOriginB()+DistanceToOriginC();
}

MyTriangle::MyTriangle()
    : TreugX1(0), TreugY1(0), TreugX2(0), TreugY2(0), TreugX3(0), TreugY3(0)
    {

    Name = "MyTriangle";

    }

void MyTriangle::AreaCalculation()
{
    Area = 0.5 * std::abs(TreugX1 * (TreugY2 - TreugY3) + TreugX2 * (TreugY3 - TreugY1) + TreugX3 * (TreugY1 - TreugY2));

    Area = std::round(Area * 10) / 10.0;
    
}

void MyTriangle::SetCord(int X1, int Y1, int X2, int Y2, int X3, int Y3)
{
    this->TreugX1 = X1;
    this->TreugY1 = Y1;
    this->TreugX2 = X2;
    this->TreugY2 = Y2;
    this->TreugX3 = X3;
    this->TreugY3 = Y3;

}
const std::string & MyTriangle::GetName()
{
    return this->Name;
}

int MyTriangle::ReturnTreugX1() const
{
    return this->TreugX1;
}

int MyTriangle::ReturnTreugY1() const
{
    return this->TreugY1;
}

int MyTriangle::ReturnTreugX2() const
{
    return this->TreugX2;
}

int MyTriangle::ReturnTreugY2() const
{
    return this->TreugY2;
}

int MyTriangle::ReturnTreugX3() const
{
    return this->TreugX3;
}

int MyTriangle::ReturnTreugY3() const
{
    return this->TreugY3;
}

double MyTriangle::DistanceToOriginA() const
{
    return std::sqrt(TreugX1*TreugX1+TreugY1*TreugY1);
}

double MyTriangle::DistanceToOriginB() const
 {
    return std::sqrt(TreugX2*TreugX2+TreugY2*TreugY2);
}

double MyTriangle::DistanceToOriginC() const
{
    return std::sqrt(TreugX3*TreugX3+TreugY3*TreugY3);
}
    



