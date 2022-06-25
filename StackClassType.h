///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Programmer's Name: Parjan Ameen
// File Name:         StackClassType.h
// Associated File:   StackClassType.cpp                                                                                           
// Header File Contains:
//Contains Gets, Sets, prints, and other functions for the StackClassType
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef StackClassType_h
#define StackClassType_h
//---------------------------------------------------------------------------------------------------------------------
#include "Standards.h"
#include "CardClassType.h"


//Defining a structure node
struct node
{
	CardClassType dataCard;
	node* link;  

};

//Creating a type definition, this is a pointer to the node
typedef node* nodePtr;

//Definition of the class - StackClassType
class StackClassType
{

private:

	//Pointer for the top of the stack
	nodePtr top;

public:

	//Constructor(s)---------------------------------------------------------------------------------------------------
	StackClassType() { CreateAStack(); };

	//Other Methods----------------------------------------------------------------------------------------------------
	bool IsEmpty();   
	nodePtr GetANode(CardClassType card);   
	CardClassType GetTop();
	void Push(nodePtr aNode);
	nodePtr Pop();
	void CreateAStack();
	void DestroyStack();

	//Destructor-------------------------------------------------------------------------------------------------------
	~StackClassType() { DestroyStack(); };
};


#endif 
