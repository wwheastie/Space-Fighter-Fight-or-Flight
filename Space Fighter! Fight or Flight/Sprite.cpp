#include "Sprite.h"

#include <iostream>

Sprite::Sprite()
{

}
Sprite::Sprite(char tempSymbol, int tempY, int tempX, int tempHealth)
{
	symbol = tempSymbol;
	yPos = tempY;
	xPos = tempX;
	health = tempHealth;
	next = nullptr;
	prev = nullptr;
}
void Sprite::simulate(char map[20][50])
{

}
bool Sprite::valid_move(char map[20][50], int yMove, int xMove)
{
	if (map[yMove][xMove] == ' ')
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Sprite::move(char map[20][50], int yCor, int xCor)
{
	int tempY = yPos + yCor;
	int tempX = xPos + xCor;

	if (valid_move(map, tempY, tempX))
	{
		map[yPos][xPos] = symbol;
		map[yPos][xPos] = ' ';
		yPos += yCor;
		xPos += xCor;
		map[yPos][xPos] = symbol;
	}
}
void Sprite::delete_sprite(char map[20][50])
{
	health--;
	symbol = ' ';
	map[yPos][xPos] = symbol;
}