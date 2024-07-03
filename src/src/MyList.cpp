#include "MyList.h"
#include <fstream>

MyList::MyList() : Head(nullptr), Tail(nullptr), Count(0){}

void MyList::PushFront()
{
	Shape* Ptr = AddNewElement();
    if (Ptr == nullptr)
    {
        return;
    }
	Node* Cur = new Node;
	Cur->Prev = nullptr;
	Cur->FigurePtr = Ptr;
	Cur->Next = Head;
	if (Head != nullptr)
    {
		Head->Prev = Cur;
	}else
    {
		Tail = Cur;
	}
	Head = Cur;
	Count++;
}

void MyList::PushBack()
{
	Shape* Ptr = AddNewElement();
    if (Ptr == nullptr)
    {
        return;
    }
	Node* Cur = new Node;
	Cur->Next = nullptr;
	Cur->Prev = Tail;
	Cur->FigurePtr = Ptr;
	if (Tail != nullptr)
    {
		Tail->Next = Cur;
	}else
    {
		Head = Cur;
	}
	Tail = Cur;
	Count++;
}

void MyList::PopBack()
{
	Node* PtrTail = Tail;

	if (Tail->Prev != nullptr)
    {
		Tail = Tail->Prev;
		Tail->Next = nullptr;
	}else
    {
		Head = nullptr;
		Tail = nullptr;
	}
	delete PtrTail;
	Count--;
}

void MyList::PopFront()
{
	Node* PtrHead = Head;
	if (Head->Next != nullptr)
    {
		Head = Head->Next;
		Head->Prev = nullptr;
	}else
    {
		Head = nullptr;
		Tail = nullptr;
	}
	delete PtrHead;
	Count--;
}

Shape* CreateCircle()
{
    Shape * Ptr = nullptr;

    try
    {
    	int X, Y, Radius;
    do
    {
        std::cout << "Enter the x coordinate for Circle:  ";

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            std::cout << "Input error\n";
        }

    }
    while (!(std::cin >> X));

    do
    {
        std::cout << "Enter the y coordinate for Circle:  ";

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            std::cout << "Input error\n";
        }

    }
    while (!(std::cin >> Y));

    do
    {
        std::cout << "Enter radius for Circle:  ";

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            std::cout << "Input error\n";
        }
    }
    while (!(std::cin >> Radius));
        if (Radius <= 0)
        {

            throw MyEx("your radius is not correct\n");
        }

        Ptr = new MyCircle(X,Y,Radius);
    }
    catch(MyEx& exception){
        std::cerr << "Error Circle: " << exception.what() << std::endl;

    }

    return Ptr;
}

Shape* CreateRectangle()
{
    Shape * Ptr = nullptr;

    try
    {
    	int Top, Bottom, Left, Right;

        do
        {
            std::cout << "Enter the bottom coordinate for Rectangle:  ";

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << std::endl;
                std::cout << "Input error\n";
            }
        }
        while (!(std::cin >> Bottom));
        do
    {
        std::cout << "Enter the top coordinate for Rectangle:  ";

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            std::cout << "Input error\n";
        }
    }
    while (!(std::cin >> Top));


    do
    {
        std::cout << "Enter the left coordinate for Rectangle:  ";

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            std::cout << "Input error\n";
        }
    }
    while (!(std::cin >> Left));

    do
    {
        std::cout << "Enter the right coordinate for Rectangle:  ";

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            std::cout << "Input error\n";
        }
    }
    while (!(std::cin >> Right));
    if (Left > Right)
    {
        throw MyEx("Your left coordinate is greater than your right\n");
    }
    if (Bottom > Top)
    {
        throw MyEx("Your bottom coordinate is greater than your top coordinate\n");
    }
    if (Bottom == Top)
    {
    	throw MyEx("Your bottom = top\n");
    }
    if (Left == Right)
    {
    	throw MyEx("Your left = right\n");
    }
    Ptr = new MyRectangle(Top,Left,Bottom,Right);}
    catch(MyEx &exception)
    {
        std::cerr << "Error Rectangle: " << exception.what() << std::endl;
    }

    return Ptr;
}

Shape* CreateTriangle()
{

    Shape* Ptr = nullptr;


    try
    {
    	int X1, X2, X3, Y1, Y2, Y3;
    do
    {
        std::cout << "Enter the x1 coordinate for Triangle:  ";

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            std::cout << "Input error\n";
        }
    }
    while (!(std::cin >> X1));
    do
    {
        std::cout << "Enter the y1 coordinate for Triangle:  ";

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            std::cout << "Input error\n";
        }
    }
    while (!(std::cin >> Y1));

    do
    {
        std::cout << "Enter the x2 coordinate for Triangle:  ";

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            std::cout << "Input error\n";
        }
    }
    while (!(std::cin >> X2));
    do
    {
        std::cout << "Enter the y2 coordinate for Triangle:  ";

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            std::cout << "Input error\n";
        }
    }
    while (!(std::cin >> Y2));
    do
    {
        std::cout << "Enter the x3 coordinate for Triangle:  ";

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            std::cout << "Input error\n";
        }
    }
    while (!(std::cin >> X3));

    do
    {
        std::cout << "Enter the y3 coordinate for Triangle:  ";

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            std::cout << "Input error\n";
        }
    }
    while (!(std::cin >> Y3));

    if (X1 == X2 && Y1 == Y2)
    {
        throw MyEx("the first and second vertices are the same\n");
    }
    if (X2 == X3 && Y2 == Y3)
    {
        throw MyEx("the second and third vertices coincide\n");
    }
    if (X3 == X1 && Y3 == Y1)
    {
        throw MyEx("the third and first vertices are the same\n");
    }
    if((X2 - X1) * (Y3 - Y1) == (X3 - X1) * (Y2 - Y1))
    {
        throw MyEx("points lie on the same plane\n");
    }
        Ptr = new MyTriangle(X1,Y1,X2,Y2,X3,Y3);}

    catch(MyEx &exception)
    {
        std::cerr << "Error Triangle: " << exception.what() << std::endl;
    }

    return Ptr;
}

Shape* MyList::AddNewElement()
{
	int NumOfShape = 0;
	Shape* Ptr = nullptr;
	do
    {
        std::cout << "What shape do you want to add?\n";

		std::cout << "1 - Circle, 2 - Rectangle, 3 - Triangle\n";
		
		std::cin >> NumOfShape;

		if (NumOfShape == 1)
        {
			Ptr = CreateCircle();
		}else if (NumOfShape == 2)
        {
			Ptr = CreateRectangle();
		}else if (NumOfShape == 3)
        {
			Ptr = CreateTriangle();
		}else
        {
			if (std::cin.fail())
            {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
            std::cout << "There is no such digit\n";
		}
	}
    while (NumOfShape < 1 || NumOfShape > 3);
    if(Ptr!= nullptr)
    {
	Ptr->SetColor();
    }
    return Ptr;
}

void MyList::RemovalByAreaSize(double Area)
{
	if (Area <= 0)
    {
        std::cout << "Your shape area is not correct\n";
		return;
	}
	    bool Search = false;
		Node* PtrHead = this->Head;
		while (PtrHead != nullptr)
        {
			if (PtrHead->FigurePtr->Area == Area)
            {
				if (PtrHead == Head)
                {
					if (Head->Next != nullptr)
                    {
						Head = Head->Next;
						Head->Prev = nullptr;

					}else
                    {
						Head = nullptr;
						Tail = nullptr;

					}
				}else if (PtrHead == Tail)
                {
					if (Tail->Prev != nullptr)
                    {
						Tail = Tail->Prev;
						Tail->Next = nullptr;
					}else
                    {
						Tail = nullptr;
						Head = nullptr;
					}
				}else
                {
					Node* PrevNode = PtrHead->Prev;
					Node* NextNode = PtrHead->Next;
					PrevNode->Next = NextNode;
					NextNode->Prev = PrevNode;

				}
				delete PtrHead;
				Count--;
				Search = true;
				PtrHead = Head;
			}else
            {
				PtrHead = PtrHead->Next;
			}
		}
		if (!Search) {
            std::cout << "There are no elements with such an area\n";
			return;
		}
}

size_t MyList::ReturnCount () const
{
    return this->Count;
}
void MyList::DeleteAllNodes()
{
    Node* PtrHead = Head;

    while (PtrHead != nullptr)
    {
        Node* Next = PtrHead->Next;
        delete PtrHead;
        PtrHead = Next;
    }

    Head = nullptr;
    Tail = nullptr;
    Count = 0;

}

MyList::~MyList()
{
    DeleteAllNodes();
}

void MyList::WriteToFile() const
{
	if (this->Count == 0)
	{
		std::cout << "Your List is empty\n";
		return;
	}

	std::cout << "Specify the path where the file is located \n";
	std::string WayOfFile;
	std::cin >> WayOfFile;
	std::ofstream file(WayOfFile, std::ios::binary);

	if (WayOfFile.ends_with(".txt") || WayOfFile.ends_with(".md"))
	{
		std::cout << "The file extension is suitable for writing)\n";
	}else
	{
		std::cout << "Your file extension should be .txt or .md\n";
		return;
	}

	std::cout << "The file has been opened successfully, check it\n";

	file << this->Count << "\n";
	Node * PtrHead = Head;

	while(PtrHead != nullptr)
	{     Shape * PtrShape = PtrHead->FigurePtr;
        file << PtrHead->ReturnShape()->GetName();
		file <<  "\n";
		file << PtrHead->FigurePtr->ReturnColor();
		file <<  "\n";
		file << PtrHead->FigurePtr->Area;
		file <<  "\n";
		file << PtrHead->FigurePtr->DistanceFromNullPoint;
        file <<  "\n";
        if (typeid(*PtrShape) == typeid(MyTriangle))
        {
            auto *PtrTriangle = dynamic_cast<MyTriangle*>(PtrShape);
            int TX1 = PtrTriangle->ReturnTreugX1();
            file << TX1 <<  "\n";
            int TY1 = PtrTriangle->ReturnTreugY1();
            file << TY1 <<  "\n";
            int TX2 = PtrTriangle->ReturnTreugX2();
            file << TX2 <<  "\n";
            int TY2 = PtrTriangle->ReturnTreugY2();
            file << TY2 <<  "\n";
            int TX3 = PtrTriangle->ReturnTreugX3();
            file << TX3 <<  "\n";
            int TY3 = PtrTriangle->ReturnTreugY3();
            file << TY3 ;
        } else if (typeid(*PtrShape) == typeid(MyRectangle))
        {
            auto * PtrRectangle = dynamic_cast<MyRectangle*>(PtrShape);
            int RLeft = PtrRectangle->ReturnRectangleLeft();
            file << RLeft <<  "\n";
            int RRight = PtrRectangle->ReturnRectangleRight();
            file << RRight <<  "\n";
            int RBottom = PtrRectangle->ReturnRectangleBottom();
            file << RBottom << "\n";
            int RTop = PtrRectangle->ReturnRectangleTop();
            file << RTop ;
        } else if (typeid(*PtrShape) == typeid(MyCircle))
        {
            auto * PtrCircle = dynamic_cast<MyCircle*>(PtrShape);
            int CX = PtrCircle->ReturnCircleX();
            int CY = PtrCircle->ReturnCircleY();
            int CRadius = PtrCircle->ReturnCircleRadius();
            file << CX << "\n";
            file << CY << "\n";
            file << CRadius;
            if (file.fail())
            {
                std::cout << "error\n";
            }
        }
		PtrHead = PtrHead->Next;
		file << '\n';
	}

	file.close();
}

void MyList::ReadFromFile()
{
	std::cout << "Specify the path where the file is located\n";
	std::string WayOfFile;
	std::cin >> WayOfFile;
    if (!(WayOfFile.ends_with(".txt") || WayOfFile.ends_with(".md")))
    {
        std::cout << "Your file extension should be .txt or .md\n";
        return;
    }
    std::ifstream file(WayOfFile);
    if (!file.is_open())
    {
        std::cout << "Error, the file did not open, check the data: " << WayOfFile << std::endl;
        return;
    }

    file.seekg(0, std::ios::end);
    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    if (fileSize == 0)
    {
        std::cout << "Your file is empty...\n";
        file.close();
        return;
    }

    std::cout << "The file has been opened successfully, we are reading information from the file.... \n";

		 size_t MCount;
		 file >> MCount;

            while (MCount)
            {       Node * PtrNode = new Node;
                if( Head == nullptr)
                {
                Head = PtrNode;
                Tail = PtrNode;
                PtrNode->Prev = nullptr;
                PtrNode->Next = nullptr;
                }else
                {

                    Tail->Next = PtrNode;
                    PtrNode->Prev = Tail;
                    PtrNode->Next = nullptr;
                    Tail = PtrNode;
                }

                std::string FigureName;
                file >> FigureName;

                std::string FigureColor;
                file >> FigureColor;

                std::string FigureArea;
                file  >> FigureArea;

                std::string FigureDistanceFromNullPoint;
                file >> FigureDistanceFromNullPoint;

                if (FigureName == "MyTriangle")
                {
                    int TX1,TY1,TX2,TY2,TX3,TY3;
                    file >> TX1;
                    file >> TY1;
                    file >> TX2;
                    file >> TY2;
                    file >> TX3;
                    file >> TY3;
                    PtrNode->FigurePtr = new MyTriangle;
                    Shape * PtrShape = PtrNode->FigurePtr;
                    auto * PtrTriangle = dynamic_cast<MyTriangle*>(PtrShape);
                    PtrTriangle->SetCord(TX1,TY1,TX2,TY2,TX3,TY3);

                } else if (FigureName == "MyRectangle")
                {
                    int RLeft,RRight,RBottom,RTop;
                    file >> RLeft;
                    file >> RRight;
                    file >> RBottom;
                    file >> RTop;
                    PtrNode->FigurePtr = new MyRectangle;
                    Shape * PtrShape = PtrNode->FigurePtr;
                    auto * PtrRectangle = dynamic_cast<MyRectangle*>(PtrShape);
                    PtrRectangle->SetCord(RTop,RBottom,RLeft,RRight);
                } else if (FigureName == "MyCircle")
                {
                    int CX, CY, CRadius;
                  file >> CX;
                  file >> CY;
                  file >> CRadius;
                  PtrNode->FigurePtr = new MyCircle;
                  Shape * PtrShape = PtrNode->FigurePtr;
                  auto * PtrCircle = dynamic_cast<MyCircle*>(PtrShape);
                  PtrCircle->SetCord(CX,CY,CRadius);
                }
                PtrNode->FigurePtr->SetReadName(FigureName);
                PtrNode->FigurePtr->SetReadColor(FigureColor);
                PtrNode->FigurePtr->SetReadArea(FigureArea);
                PtrNode->FigurePtr->SetReadDistanceFromNullPoint(FigureDistanceFromNullPoint);
                MCount--;
                this->Count++;

            }

		file.close();
}

void MyList::DeleteByNumber( int Num)
{
	if (Num <= 0 || Num > Count)
    {
		std::cout << "Check your number please\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
	size_t AllCount = Count;

	if (Num <= AllCount / 2)
    {
		int CountOfElements = 1;
		Node* PtrHead = Head;
		while (PtrHead != nullptr)
        {
			if (Num == CountOfElements)
            {
				if (PtrHead == Head)
                {

					if (PtrHead->Next != nullptr)
                    {
						Head = Head->Next;
						Head->Prev = nullptr;
					}else {
						Head = nullptr;
						Tail = nullptr;
					}
				}else {

					Node* NextNode = PtrHead->Next;
					Node* PrevNode = PtrHead->Prev;

					PrevNode->Next = NextNode;
					NextNode->Prev = PrevNode;
				}

				delete PtrHead;

				Count--;

				break;

			}

			CountOfElements++;
			PtrHead = PtrHead->Next;
		}
	}else if (Num > AllCount / 2)
    {
		size_t CountOfElements = AllCount;
		Node* PtrTail = Tail;
		while (PtrTail != nullptr)
        {
			if (Num == CountOfElements)
            {
				 if (PtrTail == Tail)
                 {
					if (PtrTail->Prev != nullptr)
                    {
						Tail = Tail->Prev;
						Tail->Next = nullptr;
					}
					else
                    {
						Head = nullptr;
						Tail = nullptr;
					}

				}else{
					Node* NextNode = PtrTail->Prev;
					Node* PrevNode = PtrTail->Next;

					NextNode->Next = PrevNode;
					PrevNode->Prev = NextNode;
					
				}

				delete PtrTail;

				Count--;

				break;

			}
			CountOfElements--;
			PtrTail = PtrTail->Prev;
		}
	
	}

}

void MyList::InsertByNumber()
{
    size_t Num;
    if (Count == 0)
    {
        PushFront();
        return;
    }
    std::cout << "Enter a num\n";
    std::cin >> Num;
    if (Num <= 0 || Num > Count)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        PushBack();
        return;
    }

    size_t AllCount = Count;
    size_t AllCount1 = Count;

    AllCount = AllCount/2;
    if (AllCount == 0)
    {
        AllCount = 1;
    }
    Shape * PtrShape = AddNewElement();
    if (PtrShape == nullptr)
    {
        return;
    }
	Node* PtrNode = new Node;
	PtrNode->FigurePtr = PtrShape;
	if (Num <= AllCount )
    {
		int CountOfElements = 1;
		Node* PtrHead = Head;
		while (PtrHead != nullptr)
		{
			if (Num == CountOfElements)
			{
				if (PtrHead == Head)
				{

					PtrHead->Prev = PtrNode;
					PtrNode->Next = PtrHead;
					PtrNode->Prev = nullptr;
					Head = PtrNode;

				}
				else 
				{
					PtrNode->Prev = PtrHead->Prev;
					PtrHead->Prev->Next = PtrNode;
					PtrNode->Next = PtrHead;
					PtrHead->Prev = PtrNode;
				}
				Count++;
                break;

			}

			CountOfElements++;
			PtrHead = PtrHead->Next;

		}

	}
	else if (Num > AllCount )
    {
		size_t CountOfElements_ = AllCount1;
		Node* PtrTail = Tail;
		while (PtrTail!= nullptr)
		{
			if (Num == CountOfElements_)
			{
				if (PtrTail == Tail)
				{


                    PtrTail->Next = nullptr;
					PtrTail->Prev->Next = PtrNode;
					PtrNode->Prev = PtrTail->Prev;
					PtrNode->Next = PtrTail;
					PtrTail->Prev = PtrNode;


				}else
				{

                    PtrNode->Next = PtrTail;
					PtrNode->Prev = PtrTail->Prev;
					PtrTail->Prev->Next = PtrNode;
					PtrTail->Prev = PtrNode;

				}

				Count++;
				break;
			}
				CountOfElements_--;
				PtrTail = PtrTail->Prev;

		}

	}
    
}


void MyList::SortingByArea()
{
	while (true)
    {
		bool Sorted = true;
		Node* Current = Head;
		while (Current->Next != nullptr)
        {
			if (Current->FigurePtr->Area > Current->Next->FigurePtr->Area)
            {
                Node* NodePrev = Current->Prev;
                Node *NodeNext = Current->Next;
               if(NodePrev != nullptr)
               {
                   NodePrev->Next = NodeNext;
                   NodeNext->Prev = NodePrev;
               }else
			   {
				   Head = NodeNext;
                   NodeNext->Prev= nullptr;
               }
               if(NodeNext->Next!= nullptr)
               {

                   Current->Next = NodeNext->Next;
                   NodeNext->Next->Prev = Current;
               }else
               {
				   Tail = Current;
                   Current->Next = nullptr;
               }
               NodeNext->Next = Current;
               Current->Prev = NodeNext;

			   Sorted = false;
            }else
            {
                Current = Current->Next;
            }
		}
		if (Sorted)
	    {
			break;
		}
	}
}

void  MyList::SortingByColor()
{
	std::cout << "What color will be the first one?\n";
	std::cout << "1 -> green, red -> 2, yellow -> 3, blue -> 4, black -> 5\n";
	size_t NumberOfColor;
	bool NumberOfColorBool = false;
	Colors SelectionColor  = Colors::BLACK;
	while(!NumberOfColorBool)
	{
		std::cout << "Enter the color: \n";
		std::cin>> NumberOfColor;

		switch(NumberOfColor)
		{
			case 1:  SelectionColor = Colors::GREEN;  NumberOfColorBool = true; break;

			case 2:  SelectionColor = Colors::RED;  NumberOfColorBool = true; break;

			case 3:  SelectionColor = Colors::YELLOW; NumberOfColorBool = true; break;

			case 4:  SelectionColor = Colors::BLUE; NumberOfColorBool = true; break;

			case 5:  SelectionColor = Colors::BLACK; NumberOfColorBool = true; break;

			default:

				std::cout << "Invalid input. Please try again.\n";

				std::cin.clear();

			    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			    break;
		}
	}

	while (true)
    {
		bool Sorted = true;
		Node* Current = Head;
		while (Current->Next != nullptr)
        {
			if ((Current->FigurePtr->ReturnEnumColor()!= SelectionColor) && (Current->Next->FigurePtr->ReturnEnumColor() == SelectionColor))
			{
				Node* NodePrev = Current->Prev;
				Node *NodeNext = Current->Next;
				if(NodePrev != nullptr){
					NodePrev->Next = NodeNext;
					NodeNext->Prev =NodePrev;
				}
				else
				{
					Head = NodeNext;
					NodeNext->Prev= nullptr;
				}
				if(NodeNext->Next!= nullptr)
                {

					Current->Next = NodeNext->Next;
					NodeNext->Next->Prev = Current;
				}else
                {
					Tail = Current;
					Current->Next = nullptr;
				}
				NodeNext->Next = Current;
				Current->Prev = NodeNext;

				Sorted = false;
			}else
			{
				Current = Current->Next;
			}
		}
		if (Sorted)
		{
			break;
		}
	}
}

void MyList::SortingByNullPoint()
{
	while (true)
    {
		bool Sorted = true;
		Node* Current = Head;
		while (Current->Next != nullptr)
        {
			if (Current->FigurePtr->DistanceFromNullPoint > Current->Next->FigurePtr->DistanceFromNullPoint)
			{
				Node* NodePrev = Current->Prev;
				Node *NodeNext = Current->Next;

				if(NodePrev != nullptr)
                {
					NodePrev->Next = NodeNext;
					NodeNext->Prev = NodePrev;
				}else
				{
					Head = NodeNext;
					NodeNext->Prev= nullptr;
				}
				if(NodeNext->Next!= nullptr)
                {
					Current->Next = NodeNext->Next;
					NodeNext->Next->Prev = Current;
				}else
                {
					Tail = Current;
					Current->Next = nullptr;
				}
				NodeNext->Next = Current;
				Current->Prev = NodeNext;

				Sorted = false;
			}else
			{
				Current = Current->Next;
			}
		}
		if (Sorted)
		{
			break;
		}
	}
}
std::ostream& operator <<(std::ostream& e,const MyList& value)
{
	if (value.Count == 0)
    {
        std::cout << "There are no elements in your list\n";
		return e;
	}
	size_t CountS = 1;
	size_t CountRed = 0;
	size_t CountBlue = 0;
	size_t CountYellow = 0;
	size_t CountBlack = 0;
	size_t CountGreen = 0;
	size_t CountTriangles = 0;
	size_t CountCircles = 0;
	size_t CountRectangles = 0;
	Node* Ptrhead = value.Head;
	while (Ptrhead != nullptr)
    {
		e << "Number: " << CountS++ << std::endl;
		e << Ptrhead->ReturnShape()->GetName()<<":" << std::endl;


		e << "Color: " << Ptrhead->ReturnShape()->ReturnColor() << std::endl;
		e << "Area: "<<Ptrhead->ReturnShape()->Area << std::endl ;
		e << "DistanceFromNullPoint: " <<Ptrhead->ReturnShape()->DistanceFromNullPoint << std::endl;

        Shape *PtrShape = Ptrhead->ReturnShape();

		Shape * PtrrShape = PtrShape;

        if (typeid(*PtrShape) == typeid(MyTriangle))
        {   CountTriangles++;
            auto* PtrTriangle = dynamic_cast<MyTriangle*>(PtrrShape);
            e << "x1: " << std::setw(3) <<  PtrTriangle->ReturnTreugX1() << "  y1: " << std::setw(3) << PtrTriangle->ReturnTreugY1() << std::endl;
            e << "x2: " << std::setw(3) <<  PtrTriangle->ReturnTreugX2() << "  y2: " << std::setw(3) << PtrTriangle->ReturnTreugY2() << std::endl;
            e << "x3: " << std::setw(3) <<  PtrTriangle->ReturnTreugX3() << "  y3: " << std::setw(3) << PtrTriangle->ReturnTreugY3() << std::endl <<std::endl;

		}else if (typeid(*PtrShape) == typeid(MyCircle))
        {
            CountCircles++;
            auto  * PtrCircle = dynamic_cast<MyCircle*>(PtrrShape);
		    e << "x: " << std::setw(3) << PtrCircle->ReturnCircleX() << "  y: " << std::setw(3) << PtrCircle->ReturnCircleY() << std::endl;
            e << "Radius: "<< std::setw(3) << PtrCircle->ReturnCircleRadius() << std::endl << std::endl;

		}else if (typeid(*PtrShape) == typeid(MyRectangle))
        {
			CountRectangles++;
            auto  * PtrRectangle = dynamic_cast<MyRectangle*>(PtrrShape);
            e  << "left: "  << std::setw(3) << PtrRectangle->ReturnRectangleLeft() << "  right: " << std::setw(3) << PtrRectangle->ReturnRectangleRight() << std::endl;
            e  << "bottom: " << std::setw(3) << PtrRectangle->ReturnRectangleBottom() << " top: " << std::setw(3) << PtrRectangle->ReturnRectangleTop() << std::endl <<std::endl;

		}
		 if(PtrShape->ReturnEnumColor() == Colors::GREEN)
		{
			CountGreen++;
		}else if (PtrShape->ReturnEnumColor() == Colors::RED)
		{
			CountRed++;
		}else if (PtrShape->ReturnEnumColor() == Colors::YELLOW)
		{
			CountYellow++;
		}else if (PtrShape->ReturnEnumColor() == Colors::BLUE)
		{
			CountBlue++;
		}else if (PtrShape->ReturnEnumColor() == Colors::BLACK)
		{
			CountBlack++;
		}
		Ptrhead = Ptrhead->ReturnNext();

	}
	size_t TempCount = CountS-1;
    e << std::endl;
	e << "Your Counts: " << TempCount << std::endl;
	e << std::endl;
	e << "Shapes: " << std::endl;
	e << "MyTriangles:  " << CountTriangles << "  ";
	e << "MyCircles:  " << CountCircles << "  ";
	e << "MyRectangles:  " << CountRectangles << std::endl;
	e << std::endl;
	e << "Your Colors: " << std::endl;
	e << "Green:  " << CountGreen << "  ";
	e << "Red:  " << CountRed << "  ";
	e  << "Yellow:  " << CountYellow << "  ";
	e  << "Blue:  " << CountBlue << "  ";
	e  << "Black:  " << CountBlack << "  ";
	e  << std::endl;

	return e;
}

