#pragma once
#ifndef Bullet_h
#define Bullet_h

#include "Sprite.h"

class Bullet : public Sprite
{
public:		//Functions
			Bullet();
			Bullet(char tempSymbol, int tempY, int tempX, int tempHealth);
			void simulate(char map[20][50]);
			bool valid_move(char map[20][50], int yMove, int xMove);
			void set_position(int tempY, int tempX);
};


#endif // !Bullet_h