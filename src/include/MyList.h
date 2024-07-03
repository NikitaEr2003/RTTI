#ifndef MYLIST_H
#define MYLIST_H
#include "Node.h"
#include <ostream>
#include <iomanip>
#include "MyRectangle.h"
#include "MyCircle.h"
#include "MyTriangle.h"
class Menu;
class MyList
{
protected:

	Node* Head;

	Node* Tail;

	size_t Count;

	static Shape* AddNewElement();

public:

	~MyList();

	MyList();


	void PushFront();

	void PushBack();

	void InsertByNumber();


	void PopBack();

	void PopFront();

	void DeleteByNumber(int num);

	void DeleteAllNodes();

	void RemovalByAreaSize(double Area);

	
	void SortingByArea();

	void SortingByNullPoint();

	void SortingByColor();


	void WriteToFile() const;

	void ReadFromFile();


	friend std::ostream& operator <<(std::ostream& e,const MyList& ptr);


    friend Shape * CreateRectangle();


    friend Shape * CreateTriangle();


    friend Shape * CreateCircle();


    size_t ReturnCount () const;


};
#endif