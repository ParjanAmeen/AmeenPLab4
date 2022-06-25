///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Programmer's Name: Parjan Ameen
// File Name:         GoFishClassType.cpp
// Associated File:   GoFishClassType.h                                                                                           
// Header File Contains:
//Contains Gets, Sets, prints, and other functions for the GoFishClassType
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GoFishClassType.h"

//----------------------------------------------------------------------------------------------------------------------
//GoFishClassType - Constructor for the GoFishClassType class
//----------------------------------------------------------------------------------------------------------------------
GoFishClassType::GoFishClassType(void)
{
	playerBooksCounter = 0;
	computerBooksCounter = 0;
	choosingPlayer = false;
	playChoice = false;
	firstPlayer = false;
	FirstPlayer();
}

//----------------------------------------------------------------------------------------------------------------------
//FirstPlayer - Decides who goes first
//----------------------------------------------------------------------------------------------------------------------
void GoFishClassType::FirstPlayer(void)
{
	if (rand() % 2 == 1)
	{
		//Assign first player to true
		firstPlayer = true;
	}
	else
	{
		//Assign first player to false
		firstPlayer = false;
	}

}

//----------------------------------------------------------------------------------------------------------------------
//SetStacks - Set the deck to a stack
//----------------------------------------------------------------------------------------------------------------------
void GoFishClassType::SetStack(DeckClassType aDeck)
{
	for (int index = 0; index < aDeck.GetTagField(); index++)
	{
		//Push the cards in the deck to the stack
		goFishStack.Push(goFishStack.GetANode(aDeck.GetCardsPosition(index)));
	}
}

//----------------------------------------------------------------------------------------------------------------------
//SetHands - Sets the hands for the computer and player 
//----------------------------------------------------------------------------------------------------------------------
void GoFishClassType::SetHands()
{
	//Local pointer
	nodePtr ptr;

	for (int index = 0; index < 7; index++)
	{
		//Popping off of main stack
		ptr = goFishStack.Pop();

		//Set the players hand
		playersHand.SetACard(ptr->dataCard, playersHand.GetTagField());

		//Set the tag
		playersHand.SetTagField(playersHand.GetTagField() + 1);

		//Popping off of the main stack
		ptr = goFishStack.Pop();

		//Set the computers hand
		computersHand.SetACard(ptr->dataCard, computersHand.GetTagField());

		//Set the tag 
		computersHand.SetTagField(computersHand.GetTagField() + 1);
	}

	//Delete the pointer
	delete ptr;
}

//----------------------------------------------------------------------------------------------------------------------
//ComputersTurn - What the computer does on its turn
//----------------------------------------------------------------------------------------------------------------------
void GoFishClassType::ComputersTurn()
{
	//Create local variables
	int rankChoice;
	bool cardFound;
	CardClassType currentCard;
	nodePtr fishPile;

	do {
		//Choose a card for the computer
		currentCard = computersHand.GetCardsPosition(rand() % computersHand.GetTagField());

		//Assign the rank input
		rankChoice = currentCard.GetRank();

		//Assign card found
		cardFound = false;

		//Output a statement for the computer
		cout << "The computer asks for " << currentCard << endl;

		for (int counter = 0; counter < playersHand.GetTagField(); counter++)
		{
			//Assign current card
			currentCard = playersHand.GetCardsPosition(counter);

			if (rankChoice == currentCard.GetRank())
			{
				//Print message
				cout << "You give the CPU your" << currentCard << "." << endl;

				//Add card to the CPUs hand
				computersHand.AddingCard(currentCard);

				//Remove the card from the players hand
				playersHand.RemovingCard(counter);

				//Output the players hand
				OutputDivider(static_cast<ofstream&>(cout), '*', WIDTH);
				cout << "This is your hand" << endl;
				OutputDivider(static_cast<ofstream&>(cout), '*', WIDTH);
				playersHand.PrintTheDeck();
				cout << endl;
				OutputDivider(static_cast<ofstream&>(cout), '*', WIDTH);

				//Assign card found to true
				cardFound = true;
			}
		}

		if (!cardFound)
		{
			//Print a message
			cout << "The card was not found. Picking a card from the go fish pile" << endl;

			//Conditional to check if the center stack is empty
			if (goFishStack.IsEmpty())
			{
				//Print empty stack message
				cout << "The pile is empty. There are no more cards" << endl;
			}
			else
			{
				//Pop off of the go fish pile
				fishPile = goFishStack.Pop();

				//Add the card popped off to the computers hand
				computersHand.AddingCard(fishPile->dataCard);

				if (fishPile->dataCard.GetRank() == rankChoice)
				{
					//Output what the card that was pulled
					cout << "The card picked up was " << fishPile->dataCard << endl;

					//Assign the card found to true
					cardFound = true;
				}
			}
		}

	} while (cardFound);
}

//----------------------------------------------------------------------------------------------------------------------
//PlayersTurn - What the player does on their turn
//----------------------------------------------------------------------------------------------------------------------
void GoFishClassType::PlayersTurn()
{
	//Create local variables
	CardClassType currentCard;
	int rankChoice;
	bool cardFound;
	string input;
	nodePtr fishPile;

	do {

		//Conditional to check autoPlay
		if (!playChoice)
		{
			//Choose card to ask for  
			cout << "What rank do you want: ";
			cin >> input;
			cout << endl;

			//Assigning the rank choice
			rankChoice = RankInput(input);

			//While loop to run until a valid rank has been taken
			while (!CheckHand(true, rankChoice))
			{
				//Output a statement that the card is not in the players hand and ask again
				cout << "The card you choose is not in your hand please choose another card." << endl;
				cin >> input;
				cout << endl;

				//Assigning rank choice
				rankChoice = RankInput(input);
			}
		}
		else
		{
			//Reseting the input
			input = " ";

			//Assign the current card
			currentCard = playersHand.GetCardsPosition(rand() % playersHand.GetTagField());

			//Assign rank choice
			rankChoice = currentCard.GetRank();

			//Output a statement asking the computer for the card
			cout << "The card asked for is " << currentCard << endl;
		}

		//Reset cardFound to false for the new search
		cardFound = false;

		for (int counter = 0; counter < computersHand.GetTagField(); counter++)
		{
			//Assign the current card
			currentCard = computersHand.GetCardsPosition(counter);

			if (rankChoice == currentCard.GetRank())
			{
				//Output what the computer handed over
				cout << "The computer gives you " << currentCard << "." << endl;

				//Adding the card to the players hand
				playersHand.AddingCard(currentCard);

				//Removing the card from the computers hand
				computersHand.RemovingCard(counter);

				//Set cardFound to true
				cardFound = true;
			}
		}

		if (!cardFound)
		{
			//Output a statement stating the card couldn't be found
			cout << "The card was not found" << endl;

			if (goFishStack.IsEmpty())
			{
				//Output a statement that the fish stack was empty
				cout << "The go fish stack is empty" << endl;
			}
			else
			{
				//Pop the card from the go fish stack
				fishPile = goFishStack.Pop();

				//Add the popped card 
				playersHand.AddingCard(fishPile->dataCard);

				if (fishPile->dataCard.GetRank() == rankChoice)
				{
					//Print message
					cout << "The card picked up was " << fishPile->dataCard << endl;

					//Set cardFound to true
					cardFound = true;
				}
				else
				{
					//Output a statement for the card picked up
					cout << "You picked up the " << fishPile->dataCard << endl;
				}
			}
		}
	} while (cardFound);
}

//----------------------------------------------------------------------------------------------------------------------
//IfOut - If you run out of cards
//----------------------------------------------------------------------------------------------------------------------
void GoFishClassType::IfOut(bool player)
{
	//Local variables
	nodePtr ptr;

	if (player)
	{
		if (playersHand.GetTagField() == 0)
		{
			//Print message 
			cout << "You are out of cards" << endl;

			for (int counter = 0; counter < 7; counter++)
			{
				//Check if the middle stack is empty
				if (goFishStack.IsEmpty())
				{
					break;
				}

				//Pop a card off of the go fish stack
				ptr = goFishStack.Pop();

				//Adding a card to the players hand
				playersHand.AddingCard(ptr->dataCard);
			}
		}
	}
	else
	{
		if (computersHand.GetTagField() == 0)
		{
			for (int counter = 0; counter < 7; counter++)
			{
				if (goFishStack.IsEmpty())
				{
					break;
				}

				//Popping a card off of the go fish stack
				ptr = goFishStack.Pop();

				//Adding the card to the players hand
				computersHand.AddingCard(ptr->dataCard);
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
//RankInput - Checks the users input
//----------------------------------------------------------------------------------------------------------------------
int GoFishClassType::RankInput(string rankChoice)
{
	//Local variables
	int rankInput = 0;

	if (rankChoice == "2" || rankChoice == "3" || rankChoice == "4" || rankChoice == "5" || rankChoice == "6" || 
		rankChoice == "7" || rankChoice == "8" || rankChoice == "9" || rankChoice == "10" || rankChoice == "J" || 
		rankChoice == "Q" || rankChoice == "K" || rankChoice == "A")
	{
		if (rankChoice == "J")
		{
			rankInput = 11;
		}
		else if (rankChoice == "Q")
		{
			rankInput = 12;
		}
		else if (rankChoice == "K")
		{
			rankInput = 13;
		}
		else if (rankChoice == "A")
		{
			rankInput = 1;
		}
		else
		{
			rankInput = stoi(rankChoice);
		}
	}
	else
	{
		//Get a new input
		cout << "Enter a valid input";
		cin >> rankChoice;
		cout << endl;
	}

	return rankInput;

}

//----------------------------------------------------------------------------------------------------------------------
//CheckHand - Checks to see if the users input is in the hand
//----------------------------------------------------------------------------------------------------------------------
bool GoFishClassType::CheckHand(bool player, int rankInput)
{
	//Local variable 
	bool checkDeck = false;

	if (player)
	{
		for (int counter = 0; counter < playersHand.GetTagField(); counter++)
		{
			if (rankInput == playersHand.GetCardsPosition(counter).GetRank())
			{
				//Set inDeck to true
				checkDeck = true;
			}
		}
	}
	else
	{
		for (int counter = 0; counter < computersHand.GetTagField(); counter++)
		{
			if (rankInput == computersHand.GetCardsPosition(counter).GetRank())
			{
				//Set inDeck to true
				checkDeck = true;
			}
		}
	}
	return checkDeck;
}

//----------------------------------------------------------------------------------------------------------------------
//BookCheck - Check to see if the book is in the hands
//----------------------------------------------------------------------------------------------------------------------
void GoFishClassType::BookCheck(bool player)
{
	//Local variables
	int matchedCards[4];
	int numberOfMathces = 0;
	int rankToMatch;

	if (player)
	{
		//Sorting through the hand
		playersHand.Sort();

		for (int counter = 0; counter < playersHand.GetTagField(); counter++)
		{
			//Assign the number of matches
			numberOfMathces = 0;

			//Assign rank to match
			rankToMatch = playersHand.GetCardsPosition(counter).GetRank();

			for (int index = 0; index < playersHand.GetTagField(); index++)
			{
				if (playersHand.GetCardsPosition(index).GetRank() == rankToMatch)
				{
					//Add on to the array
					matchedCards[numberOfMathces] = index;

					//Increment the counter
					numberOfMathces++;
				}
			}

			//Check for a book of matched cards
			if (numberOfMathces == 4)
			{
				//Output a statement that there are some books
				cout << "You have gotten books that are: " << playersHand.GetCardsPosition(matchedCards[0]).GetRank() << endl;

				for (int match = 0; match < 4; match++)
				{
					//Push the card on the players book stack
					playerBooks.Push(playerBooks.GetANode(
						playersHand.GetCardsPosition(matchedCards[match])));

					//Removing the card
					playersHand.RemovingCard(matchedCards[match]);
				}
			}
		}
	}
	else
	{
		//Sorting through the hand
		computersHand.Sort();

		for (int counter = 0; counter < computersHand.GetTagField(); counter++)
		{
			//Assign the number of matches
			numberOfMathces = 0;

			//Assign rank to match
			rankToMatch = computersHand.GetCardsPosition(counter).GetRank();

			for (int index = 0; index < computersHand.GetTagField(); index++)
			{
				if (computersHand.GetCardsPosition(index).GetRank() == rankToMatch)
				{
					//Add on to the array
					matchedCards[numberOfMathces] = index;

					//Increment the counter
					numberOfMathces++;
				}
			}

			//Check for a book of matched cards
			if (numberOfMathces == 4)
			{
				//Output a statement that there are some books
				cout << "You have gotten books that are: " << computersHand.GetCardsPosition(matchedCards[0]).GetRank() << endl;

				for (int match = 0; match < 4; match++)
				{
					//Push the card onto the computers books
					computerBooks.Push(computerBooks.GetANode(computersHand.GetCardsPosition(matchedCards[match])));

					//Removing the card
					computersHand.RemovingCard(matchedCards[match]);
				}
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
//BookCounter - Check for books in hand
//----------------------------------------------------------------------------------------------------------------------
void GoFishClassType::BooksCounter()
{
	//Local variables
	nodePtr ptr;
	int cardCounter = 0;

	
	while (!playerBooks.IsEmpty())
	{
		//Pop cards off of the players books
		ptr = playerBooks.Pop();

		//Free memory
		delete ptr;

		//Increment cardCounter
		cardCounter++;

		if (cardCounter == 4)
		{
			//Increment players books
			playerBooksCounter++;

			//Set cardCounter
			cardCounter = 0;
		}
	}

	while (!computerBooks.IsEmpty())
	{
		//Pop a card off of the computers books
		ptr = computerBooks.Pop();

		//Free the memory
		delete ptr;

		//Increment cardCounter
		cardCounter++;

		if (cardCounter == 4)
		{
			//Increment computers books counter
			computerBooksCounter++;

			//Set cardCounter
			cardCounter = 0;
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
//gameChoice - Have the player choose if he would like the computer to play for him 
//----------------------------------------------------------------------------------------------------------------------
void GoFishClassType::GameChoice(void)
{
	//Local variables
	int choice = 0;

	//Output a divider to the screen
	OutputDivider(static_cast<ofstream&>(cout), '.', WIDTH);

	//Ask the user if they would like to play or have the computer play for them
	cout << "Would you like to have the computer play or play for yourself?(Type a 1 to have the computer";
	cout << "play type a 2 to play yourself): ";

	//Output a divider to the screen
	OutputDivider(static_cast<ofstream&>(cout), '.', WIDTH);

	//Take in the users choice
	cin >> choice;

	//Output a space
	cout << endl;

	if (choice == 1)
	{
		//Assign the play choice to true
		playChoice = true;
	}

	else if (choice == 2)
	{
		//Assign the play choice to false
		playChoice = false;
	}

	//Error testing 
	else
	{
		//Call the gameChoice again recursively
		GameChoice();
	}

}


//----------------------------------------------------------------------------------------------------------------------
//GoFishGame - The card game Go fish
//----------------------------------------------------------------------------------------------------------------------
void GoFishClassType::GoFishGame()
{
	//Local variable
	bool switchTurn;

	//Assign the switch turn variable
	switchTurn = firstPlayer;

	while (playersHand.GetTagField() != 0 && computersHand.GetTagField() != 0)
	{
		//Output the players hand
		OutputDivider(static_cast<ofstream&>(cout), '*', WIDTH);
		cout << "This is your hand" << endl;
		OutputDivider(static_cast<ofstream&>(cout), '*', WIDTH);
		playersHand.PrintTheDeck();
		cout << endl;
		OutputDivider(static_cast<ofstream&>(cout), '*', WIDTH);


			if (switchTurn)
			{
				if (!playChoice)
				{
					//Call game choice
					GameChoice();
				}

				//Player takes their turn
				PlayersTurn();

				//Sort the players hand
				playersHand.Sort();
			}
			else
			{
				//CPU takes its turn
				ComputersTurn();

				//Sort the computers hand
				computersHand.Sort();
			}

			//Draw cards if the other players hand is now empty
			IfOut(!switchTurn);

			//Check hand for books
			BookCheck(switchTurn);

			//Switch the value of switch turn to change turns
			switchTurn = !switchTurn;

	}
	//Count the books
	BooksCounter();
	
	if (playerBooksCounter > computerBooksCounter)
	{
		//Output a win message
		cout << "You have won" << endl;
		cout << "The computer had " << computerBooksCounter << endl;
		cout << "The player had " << playerBooksCounter << endl;
	}
	else
	{
		//Output a loss message
		cout << "You have lost :(" << endl;
		cout << "The computer had " << computerBooksCounter << endl;
		cout << "The player had " << playerBooksCounter << endl;
	}
}

//----------------------------------------------------------------------------------------------------------------------
//GoFishClassType - Destructor for the go fish class type
//----------------------------------------------------------------------------------------------------------------------
GoFishClassType::~GoFishClassType(void)
{
	//Declare the counter variable
	static int counter = 0;

	//Increment the counter
	counter++;
}


