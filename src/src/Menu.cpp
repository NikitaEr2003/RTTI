#include "Menu.h"
Menu::Menu()
{
	this->Doublelist = new MyList;
}

Menu::~Menu()
{

delete this->Doublelist;

this->Doublelist = nullptr;

}

void Menu::FastBackToMenu()
{
    std::cout << "Back to the menu...\n";
}

void Menu::BackToMenu()
{
	std::string ReturnToMenu;
	std::cout << "Return to menu? Press any key)\n";
	std::cin >> ReturnToMenu;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	FastBackToMenu();
}

void Menu::MayMenu() const
{  while (true)
    {
    std::cout <<"\tMenu of your list of shapes\n";
    std::cout<< "Print list -> (1)\n";
    std::cout<< "Add shape -> (2)\n";
    std::cout<< "Delete figure -> (3)\n";
    std::cout<< "Sorting the list -> (4)\n";
    std::cout<< "Write figures to file -> (5)\n";
    std::cout<< "Read figures from file -> (6)\n";
    std::cout<< "Exit program -> (7)\n";
    int NumberSelection;
    bool Answer = false;
    bool CaseOne = false;
    do
    {
        std::cin>> NumberSelection;
        if(NumberSelection <= 0 || NumberSelection >7)
        {
            std::cout << "Input Error\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }else
        {

            Answer= true;

        }
    }

    while(!Answer);

    bool ChoiceSize = false;

    switch(NumberSelection)
    {
        case 1: std::cout<<(*this->Doublelist); CaseOne = true; break;

        case 2:

            size_t Choice;

        while(!ChoiceSize)
        {
            std::cout << "Do you want to add to the end, to the beginning, or to any place?\n";
            std::cout << "1 -> Add to the beginning\n";
            std::cout << "2 -> Add to the end\n";
            std::cout << "3 -> Add to any place\n";
            std::cin >> Choice;

            if(Choice < 1 || Choice > 3)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Input Error\n";
            }else
            {
                ChoiceSize = true;
            }
        }

        if(Choice == 1)
        {
            this->Doublelist->PushFront();
        }else if(Choice == 2)
        {
            this->Doublelist->PushBack();
        }else if (Choice == 3)
        {
            this->Doublelist->InsertByNumber();
        }
        break;

        case 3:

            if (this->Doublelist->ReturnCount() == 0)
            {
                std::cout << "Your list is empty\n";
                break;
            }

            int Number;

        while(true)
        {
            std::cout << "PopBack -> (1)\n";
            std::cout << "PopFront -> (2)\n";
            std::cout << "DeleteByNumber -> (3)\n";
            std::cout << "RemovalByAreaSize -> (4)\n";
            std::cout << "DeleteAll-> (5)\n";
            std::cin >> Number;
            if (std::cin.fail() || Number < 1 || Number > 5)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << std::endl;
                std::cout << "Input error\n";
            }else
            {
                break;
            }
        }

        if(Number == 1){
            this->Doublelist->PopBack();
        }else if (Number == 2){
            this->Doublelist->PopFront();
        }else if (Number == 3){

            int MNumber;

            while(true)
            {
                std::cout << "Enter a number\n";
                std::cin >>MNumber;
                if (std::cin.fail() || MNumber < 1 || MNumber > Doublelist->ReturnCount())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << std::endl;
                    std::cout << "Input error\n";
                }else
                {
                    break;
                }
            }
            this->Doublelist->DeleteByNumber(MNumber);
        }else if (Number == 4){

            double MayArea = 0;
            while(true)
            {
                std::cout <<"Enter an Area\n";
                std::cin >>MayArea;
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << std::endl;
                    std::cout << "Input error\n";
                }else
                {
                    break;
                }
            }
            this->Doublelist->RemovalByAreaSize(MayArea);

        }else if (Number == 5){
            this->Doublelist->DeleteAllNodes();
        }
        break;

        case 4:
            if (this->Doublelist->ReturnCount()  <=1)
            {
                std::cout << "Your list is empty or one element\n";
                break;
            }
            int NumberFour;

        while(true)
        {
            std::cout << "SortingByArea-> (1)\n";
            std::cout << "SortingByNullPoint -> (2)\n";
            std::cout << "SortingByColor-> (3)\n";
            std::cin >> NumberFour;
            if (std::cin.fail() || NumberFour < 1 || NumberFour > 3)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << std::endl;
                std::cout << "Input error\n";
            }else
            {
                break;
            }
        }
        if (NumberFour == 1)
        {
            this->Doublelist->SortingByArea();
        }else if (NumberFour == 2)
        {
            this->Doublelist->SortingByNullPoint();
        }else if (NumberFour == 3)
        {
            this->Doublelist->SortingByColor();
        }
        break;

        case 5: this->Doublelist->WriteToFile(); break;

        case 6: this->Doublelist->ReadFromFile(); break;

        case 7: std:: cout << "You have logged out of the program \n"; return ;

        default: std::cout << "Error \n"; return;
    }

    if (!CaseOne)
    {
        Menu::FastBackToMenu();
    } else
    {
        Menu::BackToMenu();
    }
    CustomSleep();
    CustomClear();
}
}

