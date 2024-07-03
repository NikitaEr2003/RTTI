#ifndef NODE_H
#define NODE_H
#include "Shape.h"
class Node
{

protected:

	Shape* FigurePtr;

	Node* Next;

	Node* Prev;


     Node();

    ~Node();


	friend class MyList;


public:


    Node * ReturnNext() const;

    Node* ReturnPrev() const;

    Shape *ReturnShape() const;

};
#endif