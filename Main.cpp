///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Students Name: Parjan Ameen
// Course:        CST-202: Data Structures
// Program  Name: Lab 4                                                                                                
// Date:          3/23/22
//
//---------------------------------------------------------------------------------------------------------------------
// Program Description:
//	In this program the game Go Fish is played between a user and the computer. A deck of 52 cards is shuffled and then 
//	handed out 1 after the other until the user and computer each have a hand of 7 cards. The user has the choice to 
//	either play manually or have the program run through and play the whole game automatically at any point in time. 
//  The objective is to get more books than the other player. A book is 4 cards with the same rank. When a book is 
//  found it is pushed onto a separate stack and then compared with the other players books to determine who had the 
//	higher amount of books. The winner is announced at the end of the game along with how many books each player had. 
//	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Standards.h"
#include "GoFishClassType.h"

int main(void)
{
	//Variable to output to a file
	ofstream fout;

	//Variables to input from a file
	ifstream fin;

	//Go fish class object
	GoFishClassType goFish;

	//Deck class object
	DeckClassType deckObject;

	//Initial set up of program & List---------------------------------------------------------------------------------

	//Set up fixed point output for the file
	fout << fixed << setprecision(2);

	//Call to output the course heading to the screen
	OutputHeading(static_cast<ofstream&> (cout));

	//Go Fish Game-----------------------------------------------------------------------------------------------------

	//Call for the random seed function
	srand((unsigned int)time(NULL));

	//Creating the deck
	deckObject.CreateDeck();

	//Shuffle the deck
	deckObject.ShuffleTheDeck();

	//Set the stack to deal out
	goFish.SetStack(deckObject);

	//Deal out to both hands from the stack
	goFish.SetHands();

	//Run the go fish game
	goFish.GoFishGame();

	return 0;
}