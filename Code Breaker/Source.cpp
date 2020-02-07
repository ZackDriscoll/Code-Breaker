//Code Breaker / Word Jumble
//Author: Zack Driscoll
//The classic word jumble game where the player can ask for a hint

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//Display title
	cout << "\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";

	bool playAgain = false;
	char usersPlayAgainChoice;

	do
	{
		//Make user do 3 rounds for 1 game.
		for (int i = 0; i < 3; i++)
		{
			cout << "Welcome to round " << i + 1 << " of 3.";

			enum fields { WORD, HINT, NUM_FIELDS };
			const int NUM_WORDS = 5;
			const string WORDS[NUM_WORDS][NUM_FIELDS] =
			{
				{"wall", "Do you feel you're banging your head against something?"},
				{"glasses", "These might help you see the answer."},
				{"labored", "Going slowly, is it?"},
				{"persistent", "Keep at it."},
				{"jumble", "It's what the game is all about."}
			};

			enum difficulty { EASY, MEDIUM, HARD, NUM_DIFF_LEVELS };
			cout << "There are " << NUM_DIFF_LEVELS << " difficulty levels.";

			srand(static_cast<unsigned int>(time(0)));
			int choice = (rand() % NUM_WORDS);

			//Word to guess
			string theWord = WORDS[choice][WORD];

			//Hint for the word
			string theHint = WORDS[choice][HINT];

			//Creates a jumbled version of the word
			string jumble = theWord;
			int length = jumble.size();

			for (int i = 0; i < length; i++)
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}

			cout << "Enter 'hint' for a hint.\n";
			cout << "Enter 'quit' to quit the game.\n\n";
			cout << "The jumble is: " << jumble;

			string guess;
			cout << "\n\nYour guess: ";
			cin >> guess;

			while ((guess != theWord) && (guess != "quit"))
			{
				if (guess == "hint")
				{
					cout << theHint;
				}
				else
				{
					cout << "Sorry, that's not it.";
				}

				cout << "\n\nYour guess:";
				cin >> guess;

				if (guess == theWord)
				{
					cout << "\nThat's it! You guessed it!\n";
				}
			}
		}

		cout << "You have completed 3 rounds and the game is over!\n";

		cout << "\nWould you like to play again? (y/n) ";
		cin >> usersPlayAgainChoice;

		if (usersPlayAgainChoice == 'y')
		{
			playAgain = true;
		}
		else
		{
			playAgain = false;
		}
		
	} while (playAgain);

	cout << "Thanks for playing!";
	
	return 0;
} 