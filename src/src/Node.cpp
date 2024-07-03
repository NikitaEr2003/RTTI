#include "Node.h"

Node::Node(): FigurePtr(nullptr), Next(nullptr), Prev(nullptr){}

Node::~Node()
{
    delete this->FigurePtr;
}
Node * Node::ReturnNext() const
{
    return this->Next;
}

Node* Node::ReturnPrev() const
{
    return this->Prev;
}

Shape *Node::ReturnShape() const
{
    return this->FigurePtr;
}