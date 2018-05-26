#include "Level.h"
#include "Monster.h"
#include <Windows.h>
#include <iostream>
#include <random>
using namespace std;

char map[20][50] = 
{
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 219 },
	{ 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219 }
};

Level::Level() : MAXMONSTERS(10), ADDMONSTER(5000), SIMULATEAI(500), DISPLAYMAP(75)
{
	monsterCount = 0;
	currentTime = 0;
	lastTimeAddMonster = 0;
	lastTimeSimulateAI = 0;
	lastTimeDisplayMap = 0;
}
Level::Level(Player *tempPlayer, AIList *tempList) : MAXMONSTERS(10), ADDMONSTER(5000), SIMULATEAI(500), DISPLAYMAP(75)
{
	monsterCount = 0;
	currentTime = 0;
	lastTimeAddMonster = 6000;
	lastTimeSimulateAI = 0;
	lastTimeDisplayMap = 0;
	player = tempPlayer;
	aiList = tempList;
	aiList->monstersLeft = MAXMONSTERS;
	map[player->yPos][player->xPos] = player->symbol;
}
void Level::update()
{
	add_monster();
	simulate_ai();
	display_map();
}
void Level::key_action(char *key)
{
	player->player_action(map, key, aiList);
}
string Level::win_condition()
{
	if (aiList->empty_monsters() && monsterCount == MAXMONSTERS)
	{
		if (player->health > 0)
		{
			return "win";
		}
	}

	if (player->health <= 0)
	{
		return "lose";
	}

	return " ";
}
void Level::add_monster()
{
	//Get the last time function was entered
	currentTime = timeGetTime() - lastTimeAddMonster;

	//Perform function if set time passed
	if (currentTime > ADDMONSTER)
	{
		if (monsterCount < MAXMONSTERS)
		{
			//Create random xPos for monster
			std::default_random_engine randomGenerator(timeGetTime());
			std::uniform_int_distribution<int> randomXPos(1, 38);

			//Create a new monster instance
			Monster *monster = new Monster('m', 0, randomXPos(randomGenerator), 1, timeGetTime(), player);

			//Add monster to aiList
			aiList->add(monster);

			map[monster->yPos][monster->xPos] = monster->symbol;

			//Add to one to monster count
			monsterCount++;

			//Update last time this function was performed
			lastTimeAddMonster = timeGetTime();
		}
	}
}
void Level::simulate_ai()
{
	//Get the last time function was entered
	currentTime = timeGetTime() - lastTimeSimulateAI;

	//Perform function if set time passed
	if (currentTime > SIMULATEAI)
	{
		//Call simulate() function from each index in aiList
		aiList->simulate(map);

		//Update last time this function was performed
		lastTimeSimulateAI = timeGetTime();
	}
}
void Level::display_map()
{
	//Get the last time function was entered
	currentTime = timeGetTime() - lastTimeDisplayMap;

	//Perform function if set time passed
	if (currentTime > DISPLAYMAP)
	{
		//Clear screen
		system("cls");

		//Display map and HUD
		for (int i = 0; i < 20; i++)
		{
			cout << map[i] << endl;
		}
		cout << "| " << "Lives: " << player->health << " | Monsters Left: " << aiList->monstersLeft << " |" << endl;
		cout << "----------------------------------------" << endl;
		cout << "      Press 'P' to Pause Game";

		//Update last time this function was performed
		lastTimeDisplayMap = timeGetTime();
	}
}