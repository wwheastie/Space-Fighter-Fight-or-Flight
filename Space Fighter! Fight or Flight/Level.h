#ifndef Level_h
#define Level_h

#include <Windows.h>
#include "AIList.h"
#include "Player.h"
#include <string>

class Level
{
public:		//Functions
			Level();
			Level(Player *tempPlayer, AIList *tempList);
			void update();
			void key_action(char *key);
			std::string win_condition();

private:	//Functions
			void add_monster();
			void simulate_ai();
			void display_map();			
			
			//Variables
			const int MAXMONSTERS;
			int monsterCount;
			const DWORD ADDMONSTER;
			const DWORD SIMULATEAI;
			const DWORD DISPLAYMAP;
			DWORD currentTime;
			DWORD lastTimeAddMonster;
			DWORD lastTimeSimulateAI;
			DWORD lastTimeDisplayMap;
			Player *player;
			AIList *aiList;
};

#endif // !Level_h#pragma once