#pragma once
#ifndef Player_h
#define Player_h

#include "AIList.h"
#include "Sprite.h"
#include "Bullet.h"

class Player : public Sprite
{
public:		//Functions
			Player();
			Player(char tempSymbol, int tempY, int tempX, int tempHealth);
			void player_action(char map[20][50], char *key, AIList *aiList);

private:	//Functions
			void player_move(char map[20][50], char *key);
			void player_shoot(char map[20][50], char *key, AIList *aiList);
};

#endif // !Player_h