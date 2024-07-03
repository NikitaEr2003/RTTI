#ifndef MENU_H
#define MENU_H
#include "MyList.h"
class Menu
{
public:

	MyList *Doublelist;


    Menu() ;

	~Menu() ;


	void MayMenu() const;

	void static BackToMenu() ;

    void static FastBackToMenu() ;


    friend class MyList;

};
#endif