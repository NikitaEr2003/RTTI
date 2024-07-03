#include "MyCircle.h"

MyCircle::MyCircle(int X, int Y, int Radius) : CircleX(X), CircleY(Y), CircleRadius(Radius)
{
			AreaCalculation();

			this->Name = "MyCircle";

			this->DistanceFromNullPoint = DistanceToOrigin();
}

MyCircle::MyCircle() : CircleX(0), CircleY(0), CircleRadius(0){}

void MyCircle::SetCord(int X, int Y, int Radius)
{
    this->CircleX = X;
    this->CircleY = Y;
    this->CircleRadius = Radius;
}

const std::string & MyCircle::GetName()
{
	return this->Name;
}

void MyCircle::AreaCalculation()
{
	constexpr  double PI = 3.14159;

	Area = PI * CircleRadius * CircleRadius;

    Area = std::round(Area * 10) / 10.0;
}

int MyCircle::ReturnCircleX() const
{
	return this->CircleX;
}

int MyCircle::ReturnCircleY() const
{
	return this->CircleY;
}

int MyCircle::ReturnCircleRadius() const
{
	return this->CircleRadius;
}

double MyCircle::DistanceToOrigin() const
{
	return std::sqrt(CircleX+CircleX*CircleY+CircleY);
}
