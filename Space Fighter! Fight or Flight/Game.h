#pragma once
#ifndef Game_h
#define Game_h

#include "Level.h"
#include "AIList.h"
#include "Player.h"
#include <string>

class Game
{
public:		//Functions
			Game();
			void run_game();

private:	//Functions
			void game_condition();
			void main_menu();
			void pause_game();
			bool key_press();

			//Variables
			bool gameIsRunning;
			const int GAMESTATE_MAINMENU, GAMESTATE_PLAYGAME;
			int currentGameState;
			char *key;
			std::string exitMessage;
			AIList *aiList;
			Player *player;
			Level *level;
};

#endif // !Game_h