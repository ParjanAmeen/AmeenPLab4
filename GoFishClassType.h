///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Programmer's Name: Parjan Ameen
// File Name:         GoFishClassType.h
// Associated File:   GoFishClassType.cpp                                                                                           
// Header File Contains:
//Contains Gets, Sets, prints, and other functions for the GoFishClassType
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef GoFishClassType_h
#define GoFishClassType_h
//---------------------------------------------------------------------------------------------------------------------
#include "Standards.h"
#include "CardClassType.h"
#include "StackClassType.h" 
#include "DeckClassType.h"

//Definition of the class - GoFishClassType
class GoFishClassType
{

private:

	DeckClassType playersHand;
	DeckClassType computersHand;
	StackClassType goFishStack;
	StackClassType computerBooks;
	StackClassType playerBooks;
	bool choosingPlayer;
	bool playChoice;
	bool firstPlayer;
	int playerBooksCounter;
	int computerBooksCounter;

public:
	//Constructor(s)---------------------------------------------------------------------------------------------------
	GoFishClassType(void);

	//Methods----------------------------------------------------------------------------------------------------------
	void SetHands();
	void SetStack(DeckClassType aDeck);
	void GameChoice(void);
	void GoFishGame();
	void PlayersTurn();
	void ComputersTurn();
	int RankInput(string rankChoice);
	bool CheckHand(bool player, int rankInput);
	void BookCheck(bool player);
	void IfOut(bool player);
	void FirstPlayer(void);
	void BooksCounter(void);

	//Destructor-------------------------------------------------------------------------------------------------------
	~GoFishClassType(void);
};


#endif 
