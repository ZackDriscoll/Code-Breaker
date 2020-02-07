//Code Breaker
//Author: Zack Driscoll
//CIA Code Breaking simulation

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//Display title
	cout << "\t\tGreetings user, and welcome to the Code Breaker simulation.\n\n";
	cout << "Unscramble the letters to make a word.\n";

	bool goAgain = false;
	char usersGoAgainChoice;

	do
	{
		//Make user do 3 rounds for 1 game.
		for (int i = 0; i < 3; i++)
		{
			cout << "\n\nWelcome to round " << i + 1 << " of 3.";

			enum fields { WORD, HINT, NUM_FIELDS };
			const int NUM_WORDS = 10;
			const string WORDS[NUM_WORDS][NUM_FIELDS] =
			{
				{"intelligence", "Seeking information are we?"},
				{"glasses", "These might help you see the answer."},
				{"labored", "Going slowly, is it?"},
				{"persistent", "Keep at it."},
				{"armory", "Do you need a weapon?"},
				{"agent", "So, you wish to become a CIA..."},
				{"ghost", "Never seen. Never heard."},
				{"motivation", "What drives you?"},
				{"phishing", "Common hacker tactic."},
				{"service", "Your country thanks you for your..."}
			};

			enum difficulty { EASY, MEDIUM, HARD, NUM_DIFF_LEVELS };
			cout << "\n\nThere are " << NUM_DIFF_LEVELS << " difficulty levels.";

			srand(static_cast<unsigned int>(time(0)));
			int choice = (rand() % NUM_WORDS);

			//Word to guess
			string theWord = WORDS[choice][WORD];

			//Hint for the word
			string theHint = WORDS[choice][HINT];

			//Creates a scrambled version of the word
			string code = theWord;
			int length = code.size();

			for (int i = 0; i < length; i++)
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = code[index1];
				code[index1] = code[index2];
				code[index2] = temp;
			}

			cout << "Should you have trouble unscrambling the code, enter 'hint' for a hint.\n";
			cout << "If you are done unscrambling words, enter 'quit' to quit the game.\n\n";
			cout << "The scrambled code word is: " << code;

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
					cout << "Sorry, your guess is incorrect. Try again.";
				}

				cout << "\n\nYour guess:";
				cin >> guess;

				if (guess == theWord)
				{
					cout << "\nYou have successfully unscrambled the word. Good work.\n";
				}
			}
		}

		cout << "You have completed 3 rounds and the simulation is over!\n";

		cout << "\nWould you like to go again? (y/n) ";
		cin >> usersGoAgainChoice;

		if (usersGoAgainChoice == 'y')
		{
			goAgain = true;
		}
		else
		{
			goAgain = false;
		}
		
	} while (goAgain);

	cout << "Thanks for playing!";
	
	return 0;
} 