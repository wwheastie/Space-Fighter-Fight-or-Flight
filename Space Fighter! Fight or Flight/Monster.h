#pragma once
#ifndef Monster_h
#define Monster_h

#include "Sprite.h"
#include "Player.h"

class Monster : public Sprite
{
public:		//Functions
			Monster();
			Monster(char tempSymbol, int tempY, int tempX, int tempHealth, int seed, Player *player);
			void simulate(char map[20][50]);

private:	//Functions
			bool valid_move(char map[20][50], int yMove, int xMove);
			void randomize_move(char map[20][50]);
			void bullet_attack(char map[20][50]);
			bool valid_xPos(char map[20][50], int xCor);
			
			//Variables
			int randomSeed, moveDownCounter;
			Player *target;
};

#endif // !Monster_h