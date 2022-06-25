///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Programmer's Name: Parjan Ameen
// File Name:         DeckClassType.cpp
// Associated File:   DeckClassType.h                                                                                           
// Header File Contains:
//Contains Gets, Sets, prints, and other functions for the DeckClassType
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "DeckClassType.h"

//----------------------------------------------------------------------------------------------------------------------
//DeckClassType - Constructor for the DeckClassType class
//----------------------------------------------------------------------------------------------------------------------
DeckClassType::DeckClassType(void)
{
	//Initialize the tag field
	tagField = 0;
}

//----------------------------------------------------------------------------------------------------------------------
//CreateDeck - Creates the deck 
//----------------------------------------------------------------------------------------------------------------------
void DeckClassType::CreateDeck()
{
	//Local variables
	int index;
	int card = 1;
	int suit = heart;

	for (index = 0; index < DECK_SIZE; index++)
	{
		//Set the card and suit
		deck[index].SetRank(card);
		deck[index].SetSuit(suit);

		//Increment the card
		card++;

		if (card == 14)
		{
			//Set the card equal to one
			card = 1;

			//Increment the suit
			suit++;
		}

		//Increment the tag
		tagField++;
	}
	
}

//----------------------------------------------------------------------------------------------------------------------
//Swap - Swap the items in the deck class
//----------------------------------------------------------------------------------------------------------------------
void DeckClassType::Swap(CardClassType& first, CardClassType& second)
{
	//Set a temp;
	CardClassType temp;

	//Swap the items
	temp = first;
	first = second;
	second = temp;
}

//----------------------------------------------------------------------------------------------------------------------
//ShuffleTheDeck- Shuffle the deck
//----------------------------------------------------------------------------------------------------------------------
void DeckClassType::ShuffleTheDeck()
{
	int randSpot;
	int index;

	/// We go through the whole deck
	for (index = 0; index < DECK_SIZE; index++)
	{
		/// rand function will give you a random number between 0 and the max integer.  The % with deck size
		/// give you a random number between 0 and one less than that number.
		randSpot = rand() % DECK_SIZE;
		/// We then swap the card sport we are on (index) with the random spot
		swap(deck[index], deck[randSpot]);

	}

}

//----------------------------------------------------------------------------------------------------------------------
//PrintTheDeck- Prints the deck
//----------------------------------------------------------------------------------------------------------------------
void DeckClassType::PrintTheDeck()
{
	//Local variables
	int index;


	for (index = 0; index < tagField; index++)
	{
		//Print the deck
		cout << deck[index];

		if (index % 7 == 0)
		{
			//Output a blank space
			cout << endl;
		}

	}

}

//----------------------------------------------------------------------------------------------------------------------
//Sort - Sorts through the deck
//----------------------------------------------------------------------------------------------------------------------
void DeckClassType::Sort(void)
{
	//Local variables
	int indexOfLowest;

	//For loop to run through the deck
	for (int index = 0; index < tagField; index++)
	{
		//Call method to find the index with the smallest rank
		indexOfLowest= FindIndexOfLowest(index);

		//Swap the index with the lowest rank to the current index
		Swap(deck[index], deck[indexOfLowest]);
	}
}

//----------------------------------------------------------------------------------------------------------------------
//FindIndexOfLowest- Finds the index of the lowest rank
//----------------------------------------------------------------------------------------------------------------------
int DeckClassType::FindIndexOfLowest(int position)
{
	//Local variables
	int lowestIndex;

	//Set lowestIndex to position
	lowestIndex = position;

	for (int index = position + 1; index < tagField; index++)
	{
		if (deck[index] < deck[lowestIndex])
		{
			//Set the lowest index
			lowestIndex = index;
		}
	}

	return lowestIndex;
}

//----------------------------------------------------------------------------------------------------------------------
//AddingCard- Adds the card
//----------------------------------------------------------------------------------------------------------------------
void DeckClassType::AddingCard(CardClassType addCard)
{
	//Adds the card 
	deck[tagField] = addCard;

	//Increment the tag field 
	tagField++;
}

//----------------------------------------------------------------------------------------------------------------------
//RemovingCard- Prints the deck
//----------------------------------------------------------------------------------------------------------------------
void DeckClassType::RemovingCard(int position)
{
	//Set card
	deck[position] = deck[tagField- 1];

	//Decrement the deck tag
	tagField--;
}

DeckClassType::~DeckClassType(void)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DeckClassType - Destructor that prints to the screen stating when the object goes out of memory
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	//Declare the counter variable
	static int counter = 0;

	//Increment the counter
	counter++;
}