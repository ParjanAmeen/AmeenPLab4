///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Programmer's Name: Parjan Ameen
// File Name:         DeckClassType.h
// Associated File:   DeckClassType.cpp                                                                                           
// Header File Contains:
//Contains Gets, Sets, prints, and other functions for the DeckClassType
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef DeckClassType_h
#define DeckClassType_h
//---------------------------------------------------------------------------------------------------------------------
#include "Standards.h"
#include "CardClassType.h"

//Constant for the deck size
const int DECK_SIZE = 52;

//Definition of the class - DeckClassType
class DeckClassType
{

private:
	
	//Member variables and arrays
	CardClassType deck[DECK_SIZE];
	int tagField;
	
public:

	//Constructor(s)---------------------------------------------------------------------------------------------------
	DeckClassType(void);

	//Other Methods----------------------------------------------------------------------------------------------------
	void CreateDeck();
	void Swap(CardClassType& first, CardClassType& second);
	void ShuffleTheDeck();
	void PrintTheDeck();
	void SetTagField(int aTagField) { tagField = aTagField; };
	int GetTagField(void) { return tagField; };
	CardClassType GetCardsPosition(int position) { return deck[position]; };
	void SetACard(CardClassType aCard, int position) { deck[position] = aCard; };
	void Sort(void);
	int FindIndexOfLowest(int position);
	void AddingCard(CardClassType addCard);
	void RemovingCard(int position);

	//Destructor-------------------------------------------------------------------------------------------------------
	~DeckClassType(void);
};



#endif 
