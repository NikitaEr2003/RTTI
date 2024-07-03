#include "MyRectangle.h"

MyRectangle::MyRectangle(int Top, int Left, int Bottom, int Right) : RectangleTop(Top), RectangleLeft(Left), RectangleBottom(Bottom), RectangleRight(Right)
{
	AreaCalculation();

 	Name = "MyRectangle";

	this->DistanceFromNullPoint = DistanceToOriginA()+DistanceToOriginB()+DistanceToOriginC()+DistanceToOriginD();

}

MyRectangle::MyRectangle() :RectangleTop(0), RectangleLeft(0), RectangleBottom(0), RectangleRight(0)
{
	Name = "MyRectangle";
}

const std::string & MyRectangle::GetName()
{
	return this->Name;
}

void MyRectangle::AreaCalculation()
{
	double Length = RectangleRight - RectangleLeft;

	double Width = RectangleTop - RectangleBottom;

	Area= Length * Width;

    Area = std::round(Area * 10) / 10.0;
}

int MyRectangle::ReturnRectangleTop () const
{
	return this->RectangleTop;
}

int MyRectangle::ReturnRectangleBottom() const
{
	return this->RectangleBottom;
}

int MyRectangle::ReturnRectangleLeft() const
{
	return this->RectangleLeft;
}

int MyRectangle::ReturnRectangleRight() const
{
	return this->RectangleRight;
}

double MyRectangle::DistanceToOriginA() const
{
	return std::sqrt(RectangleLeft*RectangleLeft+RectangleTop*RectangleTop);
}

double MyRectangle::DistanceToOriginB() const
{
	return std::sqrt(RectangleRight*RectangleRight+RectangleTop*RectangleTop);
}

double MyRectangle::DistanceToOriginC() const
{
	return std::sqrt(RectangleRight*RectangleRight+RectangleBottom*RectangleBottom);
}

double MyRectangle::DistanceToOriginD() const
{
	return std::sqrt(RectangleLeft*RectangleLeft+RectangleBottom*RectangleBottom);
}

void MyRectangle::SetCord(int Top, int Bottom, int Left, int Right)
{
    this->RectangleTop = Top;
    this->RectangleBottom = Bottom;
    this->RectangleLeft = Left;
    this->RectangleRight = Right;
}





