#ifndef Sprite_h
#define Sprite_h

class Sprite
{
public:		//Functions
			Sprite();
			Sprite(char tempSymbol, int tempY, int tempX, int tempHealth);
			virtual void simulate(char map[20][50]);
			virtual bool valid_move(char map[20][50], int yMove, int xMove);
			void move(char map[20][50], int yCor, int xCor);
			void delete_sprite(char map[20][50]);

			//Variables
			char symbol;
			int yPos, xPos, health;
			Sprite *next, *prev;
};

#endif // !Sprite_h#pragma once