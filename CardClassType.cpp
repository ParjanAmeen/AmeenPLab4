///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Programmer's Name: Parjan Ameen
// File Name:         CardClassType.cpp
// Associated File:   CardClassType.h                                                                                           
// Header File Contains:
//Contains Gets, Sets, prints, and other functions for the CardClassType
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "CardClassType.h"

//----------------------------------------------------------------------------------------------------------------------
//CardClassType - Constructor for the CardClassType class
//----------------------------------------------------------------------------------------------------------------------
CardClassType::CardClassType(void)
{
	//Initializing the member variables
	rank = 0;
	suit = 0;

}

//----------------------------------------------------------------------------------------------------------------------
//PrintACard - Prints out a card with the rank and suit
//----------------------------------------------------------------------------------------------------------------------
void CardClassType::PrintACard(void)
{
	//Local variables
	char printChar;

	if (rank >= 2 && rank <= 10)
	{
		cout << setw(5) << rank << (char)suit;
	}
	else
	{
		if (rank == 11)
		{
			printChar = 'J';
		}
		else if (rank == 12)
		{
			printChar = 'Q';
		}
		else if (rank == 13)
		{
			printChar = 'K';
		}
		else
		{
			printChar = 'A';
		}

		cout << setw(5) << printChar << (char)suit;
	}

}

bool CardClassType::operator<(CardClassType& card) 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//operator < - overloads the < operator
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	if (rank < card.GetRank())
	{
		//Return true
		return true;
	}

	else
	{
		//Return false
		return false;
	}
}

bool CardClassType::operator>(CardClassType& card)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//operator > - overloads the < operator
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	if (rank > card.GetRank())
	{
		//Return true
		return true;
	}

	else
	{
		//Return false
		return false;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//operator << - overloads the << operator
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& os, CardClassType& card)
{
	//Call print a card
	card.PrintACard();

	return os;
}

CardClassType::~CardClassType(void)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CardClassType - Destructor that prints to the screen stating when the object goes out of memory
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	//Declare the counter variable
	static int counter = 0;

	//Increment the counter
	counter++;
}