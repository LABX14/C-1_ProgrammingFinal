#pragma once
#include <iostream>
#include <string>

/*
	This will be used to store the variable for the game and player.
*/

bool isNotAnswer = true;
bool isPlayerDead = false;
bool isPlayerWin = false;

// This stores the numbers number for the final project
int* playerHealth;
int playerNumberInput;
int maxHealth = 100;
int randomNumberInput;
int randomNumber;
int randomNumberResult;

// This will store the input of the player
std::string playerName;
std::string gamePlayLoop = "y";
std::string playerInput;

// This list is the functions stored to be used in the project.
void StartOfGame();
void SituationOne();
void SituationTwo();
void SituationThree();

