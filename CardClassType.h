///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Programmer's Name: Parjan Ameen
// File Name:         CardClassType.h
// Associated File:   CardClassType.cpp                                                                                           
// Header File Contains:
//Contains Gets, Sets, prints, and other functions for the CardClassType
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CardClassType_h
#define CardClassType_h
//---------------------------------------------------------------------------------------------------------------------
#include "Standards.h"

//Definition of the class - CardClassType
class CardClassType
{

private:

	//Member variables
	int rank;
	int suit;

public:
	//Constructor(s)---------------------------------------------------------------------------------------------------
	CardClassType(void);

	//Get Methods------------------------------------------------------------------------------------------------------
	int GetRank(void) const { return rank; };
	int GetSuit(void) const { return suit; };

	//Set Methods------------------------------------------------------------------------------------------------------
	void SetRank(int aRank) { rank = aRank; };
	void SetSuit(int aSuit) { suit = aSuit; };

	//Other Methods----------------------------------------------------------------------------------------------------
	void PrintACard(void);
	bool operator<(CardClassType& card);
	bool operator>(CardClassType& card);
	bool operator==(CardClassType card) { return this->rank == card.rank; }
	//Destructor-------------------------------------------------------------------------------------------------------
	~CardClassType(void);
};

//Overloading operators
ostream& operator<<(ostream& os, CardClassType& card);

#endif 
