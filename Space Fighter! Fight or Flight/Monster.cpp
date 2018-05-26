#include "Monster.h"
#include <random>
#include <ctime>

Monster::Monster()
{
	moveDownCounter = 0;
}

Monster::Monster(char tempSymbol, int tempY, int tempX, int tempHealth, int seed, Player *player) : Sprite(tempSymbol, tempY, tempX, tempHealth)
{
	moveDownCounter = 0;
	target = player;
	randomSeed = seed;
}

void Monster::simulate(char map[20][50])
{
	bullet_attack(map);
	randomize_move(map);
}

bool Monster::valid_move(char map[20][50], int yMove, int xMove)
{
	if (map[yMove][xMove] == ' ')
	{
		return true;
	}
	else if ((map[yMove][xMove] == target->symbol) || (yMove == 19))
	{
		//Remove one from player's health
		target->health--;

		//Delete the monster
		delete_sprite(map);

		return false;
	}
}
void Monster::randomize_move(char map[20][50])
{
	std::default_random_engine randomGenerator(time(NULL) + randomSeed);
	std::uniform_int_distribution<int> randomNumber(1, 2);

	if (moveDownCounter == 0)
	{
		move(map, 1, 0);
		moveDownCounter++;
	}
	else
	{
		if (randomNumber(randomGenerator) == 1)
		{
			if (valid_xPos(map, 1))
			{
				move(map, 0, 1);
			}
			else if (valid_xPos(map, -1))
			{
				move(map, 0, -1);
			}			
		}
		else
		{
			if (valid_xPos(map, -1))
			{
				move(map, 0, -1);
			}
			else if (valid_xPos(map, 1))
			{
				move(map, 0, 1);
			}
		}

		moveDownCounter = 0;
	}
}
void Monster::bullet_attack(char map[20][50])
{
	if (map[yPos + 1][xPos] == '|')
	{
		delete_sprite(map);
	}
}
bool Monster::valid_xPos(char map[20][50], int xCor)
{
	int tempY = yPos;
	int tempX = xPos + xCor;

	if (map[tempY][tempX] == ' ')
	{
		return true;
	}
	else
	{
		return false;
	}
}