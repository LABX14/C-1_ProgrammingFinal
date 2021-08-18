/* 
	Kaulana Lee 
	8/18/21
	Journey Through the Plains of Montgomery
	This project is an short RPG adventure 
	There will be random encounters that will lead to different endings
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Journey.h"


using namespace std;

int main() {
	// This will reset the game variables
	playerHealth = &maxHealth;
	srand(time(0));
	randomNumber = rand() % 10 + 1;

	while (playerHealth > 0)
	{
		StartOfGame();
		SituationOne();
		SituationTwo();
		SituationThree();

		if (isPlayerWin == true)
			break;
	}

	std::cout << "Wanna play again?" << std::endl;
	
	std::cout << "Enter Reponse: " << std::endl;
	std::cin >> gamePlayLoop;

	if (gamePlayLoop == "y" || gamePlayLoop == "Y")
	{
		main();
	}
	else {
		std::cout << "Thank you for playing!" << std::endl;
	}
}

void StartOfGame()
{
	isPlayerDead = false;
	isNotAnswer = true;

	std::cout << "Greetings player! Welcome to this mini adventure!\n" << std::endl;
	std::cout << "You will go through a short journey through the Plains of Montgomery!\n" << std::endl;
	std::cout << "Before we begin, what is your name?\n" << std::endl;

	std::cout << "Enter Name: " << std::endl;

	// Used to remember the name in the game
	cin >> playerName;

	std::cout << "Ah, nice to meet you, " << playerName << ". We wish you the best of luck on your Journey Through The Plains Of Montgomery!\n" << std::endl;
	std::cout << "Now that we know your name, time for you to head out!\n" << std::endl;

	std::cout << "You will first start off in at the south side of the plain, and your goal is to make it across.\n" << std::endl;
	std::cout << "Your current status is.\n" << std::endl;
	std::cout << "Player Name: \n" << playerName << std::endl;
	std::cout << "Health: \n" << *playerHealth << endl;
}

void SituationOne() 
{
	std::cout << "After traveling down the path, you come across a fork in the path, which path do you go down, the left or the right?\n" << std::endl;
	while (isNotAnswer == true)
	{
		std::cout << "Enter 1 for Right \n" << std::endl;

		std::cout << "Enter 2 for Left \n" << std::endl;

		std::cout << "Enter Response: \n";
		std::cin >> playerNumberInput;

		if (playerNumberInput == 1)
		{
			std::cout << "As you head down to the right, you encounter some large rocks with a narrow path in between.\n" << std::endl;

			std::cout << "You can continue down the path through the rocks or go around them. \n" << std::endl;

			std::cout << "Which path do you decide to take? \n" << std::endl;

			std::cout << "Enter 1 for Around The Rocks" << std::endl;

			std::cout << "Enter 2 for Down the Narrow Path" << std::endl;

			std::cout << "Enter Response: " << std::endl;

			std::cin >> playerNumberInput;
			
			// This is the path that leads the players around the rocks
			if (playerNumberInput == 1)
			{
				std::cout << "You manage to sneak past some bandits that were waiting to ambush you! \n" << std::endl;

				std::cout << "GREAT JOB!\n" << std::endl;

				break;

			}
			else
			{
				std::cout << " You failed to sneak past the bandits and now you have no more money! \n" << std::endl;
				break;
			}
		}

		// This is going down the narrow path
		else if (playerNumberInput == 2)
		{
			std::cout << "You come across some sleeping lions. What would you like to do?\n" << std::endl;

			std::cout << "1: Start walking quietly. \n" << std::endl;

			std::cout << "2: Run through as fast as you can. \n" << std::endl;

			std::cout << "Enter Response:";
			cin >> playerNumberInput;

			if (playerNumberInput == 1)
			{
				std::cout << "You walk pass the sleeping lions without waking them up. \n" << std::endl;

				std::cout << "Smart move. \n" << std::endl;

				//Transfer to the next scenario
				break;
			}

			else
			{
				std::cout << "The lions wake up from your loud running and eat you!\n" << std::endl;

				std::cout << playerName << " has been killed. Try again? \n" << std::endl;

				// Ask to play again
				isPlayerWin = true;
				break;
			}
		}
		else
		{
			isNotAnswer = true;
		}
	}
}

void SituationTwo()
{
	std::cout << playerName << " continues though the Plains of Montgomery.\n" << std::endl;

	std::cout << "As you continue onwards, the heavy rains begins to fall. \n" << std::endl;

	std::cout << "Do you continue on ahead or look for shelter? \n" << std::endl;

	while (isNotAnswer == true)
	{

		std::cout << "1: Continue on ahead! \n" << std::endl;

		std::cout << "2: Look for shelter. \n" << std::endl;

		std::cout << "Enter Response:" << std::endl;
		std::cin >> playerNumberInput;

		std::cout << "\n";

		if (playerNumberInput == 1)
		{
			std::cout << "You can kind of see something ahead of you.\n" << std::endl;

			std::cout << "Do you keep on moving forward? \n" << std::endl;

			std::cout << "1: LETS GO! AHHHH! \n" << std::endl;

			std::cout << "2: I am not trying to die at this point. \n" << std::endl;

			std::cout << "Enter Response:" << std::endl;
			std::cin >> playerNumberInput;

			if (playerNumberInput == 1)
			{
				if (randomNumber <= 5)
				{
					*playerHealth -= 10;
					
					std::cout << "You continue onwards and suddenly the object rushes forward and knocks you down! \n" << std::endl;

					std::cout << "The golem asks you to state your name: \n" << std::endl;

					std::cout << playerName << ": My name is " << playerName << ". What is yours? \n" << std::endl;

					std::cout << "My name is Orvax. So " << playerName << ", what brings you to the Plains of Montgomery? \n" << std::endl;

					std::cout << "1: I am just crossing through." << std::endl;
					std::cout << "2: I am here to slay all the creatures of the Plains of Montogomery!" << std::endl;

					cin >> playerNumberInput;
					if (playerNumberInput == 1)
					{
						std::cout << "Orvax: Well, if that is all, sorry for knocking you down. \n" << std::endl;
						std::cout << "You may go on! \n" << endl;
						std::cout << "Here is your current Health.\n" << endl;
						std::cout << "Health: " << *playerHealth << endl;
						break;
					}
					else
					{
						std::cout << "I can not allow that, you must die! \n" << std::endl;
						std::cout << "You fight the golem and win but took some damage." << std::endl;
						std::cout << "Here is your current Health.\n" << std::endl;
						std::cout << "Health: " << *playerHealth << std::endl;
					}
				}
				else
				{
					*playerHealth -= 30;

					std::cout << "A branch comes flying at you as you look away from the object." << std::endl;
					std::cout << "The branch knocks you out for awhile." << std::endl;
					std::cout << "The storm eventually passes." << std::endl;

					std::cout << "Here is your current Health.\n" << std::endl;

					std::cout << "Health: " << *playerHealth << std::endl;
				}


			}


		}
		else if (playerNumberInput == 2)
		{
			std::cout << "You eventually find shelter and set up camp there." << std::endl;
			std::cout << "After the storm passes, you continue onwards. " << std::endl;
			break;
		}
		else
		{
			isNotAnswer = true;
		}
	}
}


void SituationThree()
{
	std::cout << "You have made it across the Plains of Montgomery!" << std::endl;
	std::cout << "Feel proud of your accomplishment!" << std::endl;
	std::cout << "This is the end of the Journey! Thank you and feel free to come back and play again!" << std::endl;
	isPlayerWin = true;
}