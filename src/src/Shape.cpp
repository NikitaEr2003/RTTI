#include "Shape.h"

Shape::Shape() : Name("null"), Color(BLACK), DistanceFromNullPoint(0),Area(0) {}

const std::string & Shape::GetName()
{
	return this->Name;
}

std::string Shape::ReturnColor() const
{
    std::string StrColor;
    if (this->Color == Colors::BLACK)
    {
        StrColor = "black";
    }
    else if (this->Color == Colors::BLUE)
    {
        StrColor = "blue";
    }
    else if (this->Color == Colors::GREEN)
    {
        StrColor = "green";
    }
    else if (this->Color == Colors::RED)
    {
        StrColor = "red";
    }
    else if (this->Color == Colors::YELLOW)
    {
        StrColor = "yellow";
    }
    return StrColor;
}

Colors Shape::ReturnEnumColor() const
{
	return this->Color;
}


void Shape::SetColor()
{
	int Choice = 1;

	do
    {
		std::cout << "Choose color:  1-green,  2-red,  3-yellow,  4-blue,  5-black\n";
		std::cin >> Choice;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a digit between 1 and 5.\n";
			continue;
		}

		switch (Choice)
        {
		case 1: this->Color = Colors::GREEN;  break;

		case 2: this->Color = Colors::RED;  break;

		case 3: this->Color = Colors::YELLOW;  break;

		case 4: this->Color = Colors::BLUE;  break;

		case 5: this->Color = Colors::BLACK;  break;

		default:

		std::cout << "There is no such digit. Please choose a digit between 1 and 5.\n";
	     break;
		}

	} while (Choice < 1 || Choice > 5);
}

void Shape::SetReadColor(const std::string &StrColor)
{
	if(StrColor == "yellow")
	{
		this->Color = Colors::YELLOW;
	}
	else if (StrColor == "green")
	{
		this->Color = Colors::GREEN;
	}
	else if (StrColor == "red")
	{
		this->Color = Colors::RED;
	}
	else if (StrColor == "black")
	{
		this->Color = Colors::BLACK;
	}
	else if (StrColor == "blue")
	{
		this->Color = Colors::BLUE;
	}else
	{
		throw MyEx("Unknown color\n");
	}

}

void Shape::SetReadName(const std::string &StrName)
{
	if (StrName == "MyRectangle" || StrName == "MyCircle" || StrName == "MyTriangle")
	{
		this->Name = StrName;
	}else
    {
		throw MyEx("Unknown Name of Shape\n");
	}
}

void Shape::SetReadArea(const std::string &StrArea)
{
	this->Area = std::stod(StrArea);
}

void Shape::SetReadDistanceFromNullPoint(const std::string &StrDistanceFromNullPoint)
{
	this->DistanceFromNullPoint =std::stod(StrDistanceFromNullPoint);
}

