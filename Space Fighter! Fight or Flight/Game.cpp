#include "Game.h"
#include <iostream>
#include <conio.h>
using namespace std;

Game::Game() : GAMESTATE_MAINMENU(1), GAMESTATE_PLAYGAME(2)
{
	gameIsRunning = true;
	currentGameState = 1;
	key = new char;
	exitMessage = " ";
	aiList = new AIList;
	player = new Player('^', 18, 20, 5);
	level = new Level(player, aiList);
};
void Game::run_game()
{
	while (gameIsRunning)
	{
		while (!key_press() && gameIsRunning)
		{
			game_condition();

			if (currentGameState == GAMESTATE_PLAYGAME)
			{
				level->update();
			}
			else if (currentGameState == GAMESTATE_MAINMENU)
			{
				main_menu();
			}
		}

		level->key_action(key);
	}

	system("cls");
	cout << exitMessage << endl << endl;
	system("pause>nul");
};
void Game::game_condition()
{
	//Pause game if user enters 'p'
	if (*key == 'p')
	{
		pause_game();
	}

	//Game over and player won
	if (level->win_condition() == "win")
	{
		exitMessage = "You have won!";
		gameIsRunning = false;
	}

	//Game over and player lost
	if (level->win_condition() == "lose")
	{
		exitMessage = "You have lost.";
		gameIsRunning = false;
	}
};
void Game::main_menu()
{
	char menuChoice = '0';
	bool validChoice = false;

	//Get menu option from user
	while (!validChoice)
	{
		system("cls");

		cout << "Space Fighter! Fight or Flight" << endl;
		cout << "------------------------------" << endl;
		cout << "1. Play!" << endl;
		cout << "2. Controls" << endl;
		cout << "3. Quit Game" << endl;
		cout << "------------------------------" << endl;
		cout << "Enter choice: ";
		cin >> menuChoice;

		if (menuChoice == '1' || menuChoice == '2' || menuChoice == '3')
		{
			validChoice = true;
		}
	}

	//Play game if choice is 1
	if (menuChoice == '1')
	{
		currentGameState = 2;
	}
	//Display objective and controls if choice is 2
	else if (menuChoice == '2')
	{
		system("cls");

		cout << "            ----------------------------              " << endl;
		cout << "            |      Game Objective      |              " << endl;
		cout << "------------------------------------------------------" << endl;
		cout << "| Defeat all the enemies without losing your 5 lives |" << endl;
		cout << "| Losing all of your lives will result in game over  |" << endl;
		cout << "------------------------------------------------------" << endl << endl << endl;

		cout << "              ------------------------            " << endl;
		cout << "              |       Controls       |            " << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "| Use 'a' to move left and 'd' to move right     |" << endl;
		cout << "| Press the \"SPACEBAR\" to fire shots at enemies  |" << endl;
		cout << "--------------------------------------------------" << endl << endl;

		system("pause");
	}
	//Exit game if choice is 3
	else if (menuChoice == '3')
	{
		exitMessage = "You have exited the game.";
		gameIsRunning = false;
	}
};
void Game::pause_game()
{
	char menuChoice = '0';
	bool validChoice = false;

	//Get menu option from user
	while (!validChoice)
	{
		system("cls");

		cout << "Game Paused" << endl;
		cout << "-------------" << endl;
		cout << "1. Continue" << endl;
		cout << "2. Main Menu" << endl;
		cout << "3. Quit Game" << endl;
		cout << "-------------" << endl;
		cout << "Enter choice: ";
		cin >> menuChoice;

		if (menuChoice == '1' || menuChoice == '2' || menuChoice == '3')
		{
			validChoice = true;
		}
	}

	//Continue game if choice is 1
	if (menuChoice == '1')
	{
		return;
	}
	//Return to main menu if choice is 2
	else if (menuChoice == '2')
	{
		currentGameState = 1;
	}
	//Exit game if choice is 3
	else if (menuChoice == '3')
	{
		exitMessage = "You have exited the game.";
		gameIsRunning = false;
	}
};
bool Game::key_press()
{
	//Get key if keyboard hit and return true
	if (_kbhit())
	{
		*key = _getch();
		return true;
	}
	//Keyboard was not hit and return false
	else
	{
		return false;
	}
};