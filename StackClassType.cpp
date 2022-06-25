///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Programmer's Name: Parjan Ameen
// File Name:         StackClassType.cpp
// Associated File:   StackClassType.h                                                                                           
// Header File Contains:
//Contains Gets, Sets, prints, and other functions for the StackClassType
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "StackClassType.h"

//----------------------------------------------------------------------------------------------------------------------
//CreateList - Creates an empty stack 
//----------------------------------------------------------------------------------------------------------------------
void StackClassType::CreateAStack(void)
{
	//Creates an empty list
	top = NULL;
}

//----------------------------------------------------------------------------------------------------------------------
//IsEmpty - Tests to see if the list is empty, if start of list is null
//----------------------------------------------------------------------------------------------------------------------
bool StackClassType::IsEmpty(void)
{
	return (top == NULL);
}

//----------------------------------------------------------------------------------------------------------------------
//GetANode - Creates a node for the stack
//----------------------------------------------------------------------------------------------------------------------
nodePtr StackClassType::GetANode(CardClassType card)
{
	//Local variables
	int rank = 0;
	int suit = 0;

	//Create a node to set the ptr to the address of this node
	nodePtr ptr = new node;

	//Assign rank and suit a value
	rank = card.GetRank();
	suit = card.GetSuit();

	//Assign the rank
	ptr->dataCard.SetRank(rank); 

	//Call the suit
	ptr->dataCard.SetSuit(suit);

	//Set the link to NULL
	ptr->link = NULL;

	return ptr;
}

//----------------------------------------------------------------------------------------------------------------------
//GetTop - Locates and returns the top of the stack
//----------------------------------------------------------------------------------------------------------------------
CardClassType StackClassType::GetTop()
{
	//Local object
	CardClassType newCard;

	//Call the set rank and suit
	newCard.SetRank(top->dataCard.GetRank());
	newCard.SetSuit(top->dataCard.GetSuit());

	return newCard;
}

//----------------------------------------------------------------------------------------------------------------------
//Push - Pushes the stack
//----------------------------------------------------------------------------------------------------------------------
void StackClassType::Push(nodePtr aNode)
{
	//Check to see if the stack is empty
	if (IsEmpty())
	{
		//Assign the top to the local pointer
		top = aNode;
	}

	else
	{
		//Assign the link to the top
		aNode->link = top;

		//Assign the top to the pointer
		top = aNode;
	}
}

//----------------------------------------------------------------------------------------------------------------------
//Pop - Pops off of the stack
//----------------------------------------------------------------------------------------------------------------------
nodePtr StackClassType::Pop()
{
	//Local pointers and variables
	nodePtr ptr;

	//Set pointer to the top of the stack
	ptr = top;

	//Check to see if the stack is empty
	if (IsEmpty())
	{
		//Print the error message to the screen
		cout << "Can't pop off of the stack" << endl;
	}

	else
	{
		//Move the node along
		top = top->link;

		//Set the link to NULL
		ptr->link = NULL;
	}

	return ptr; 
}

//----------------------------------------------------------------------------------------------------------------------
//DestroyStack - Removes all of the items from the stack when the method is called
//----------------------------------------------------------------------------------------------------------------------
void StackClassType::DestroyStack()
{
	//Local node
	nodePtr newNode;

	//While there are nodes in the linked list
	while (!IsEmpty())
	{
		//Assign newNode a value - Set node to the first item in the list
		newNode = top;

		//Assign mewNode's stack a value - Sever pointer from the list
		top = top->link;

		//Assigning newNode's stack a value of NULL
		newNode->link = NULL;

		//Free the memory for this pointer
		delete newNode;
	}
}