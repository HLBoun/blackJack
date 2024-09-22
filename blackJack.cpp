// Name: Huthsady Legend Boun
// Professor: Edwards
// Date: September 22, 2024
// Project: Bugfixing/Refactoring Blackjack Program.
// Method for solving: Played the program multiple times to try and recreate the issue (before even looking at code.) Determined that an Ace was only detected if it was the last number. Apparent loop-scope issue, seen by experience. 


#include <iostream>
#include <cctype>
using namespace std;


// Function to convert card values to numeric scores
int getCardValue(char card) {
	switch (card) {
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return card - '0'; // Convert char to int
	case 't':
	case 'T':
	case 'j':
	case 'J':
	case 'q':
	case 'Q':
	case 'k':
	case 'K':
		return 10; // Face cards are scored as 10
	case 'a':
	case 'A':
		return 11; // Ace can be scored as 11
	default:
		return 0; // Invalid input
	}
}
int main()
{
	int numCards;
	char card;
	int totalScore = 0;
	int numAces = 0;

	// Input number of cards
	cout << "Enter the number of cards (2-5): ";
	cout << "Enter: one character >> 0-9 or J, Q, K, A ONLY " << endl;
	cout << "Enter Your Card Count Here >> ";
	cin >> numCards;

	if (isdigit(numCards + '0'))
	{
		cout << "Number of Cards entered is a Digit - Ok to proceed. " << endl;
	}
	else
	{
		cout << "The number of cards is not a digit - Abort" << endl;
		return 0;
	}
	// Validate number of cards
	while (numCards < 2 || numCards > 5) 
	{
		cout << "Invalid input. Please enter a number between 2 and 5: ";
		cin >> numCards;
	}



	// Input card values and calculate total score
	for (int i = 0; i < numCards; ++i)
	{
		cout << "Enter value of card " << i + 1 << ": ";
		cin >> card;

		if (card == 'a' || card == 'A') // If the current iterative card is an ace, add 1 to the ace counter.
		{
			 numAces += 1;
		}

		// Validate card value
		int cardValue = getCardValue(card);
		while (cardValue == 0)
		{
			cout << "Invalid input. Please enter a valid card value: ";
			cin >> card;
			cardValue = getCardValue(card);
		}
		totalScore += cardValue;


		//                                               Pretty much moved this if statement up.
		//if (totalScore > 21)
		//{
			//for (int j = 0; j < i + 1; ++j)
			//{
				//if (card == 'a' || card == 'A') 
				//{
					//numAces += 1;
				//}
			//}

			// Adjust score for aces
		while (numAces > 0 && totalScore > 21)
		{
				totalScore -= 10;
				numAces -= 1;
		}
		
	}


	// Output result
	if (totalScore > 21)
	{
		cout << "Busted" << endl;
	}
	else
	{
		cout << "Total score: " << totalScore << endl;
	}
	return 0;
}