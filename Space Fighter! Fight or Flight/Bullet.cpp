#include "Bullet.h"

Bullet::Bullet()
{

}
Bullet::Bullet(char tempSymbol, int tempY, int tempX, int tempHealth) : Sprite(tempSymbol, tempY, tempX, tempHealth)
{

}
void Bullet::simulate(char map[20][50])
{
	move(map, -1, 0);
}
bool Bullet::valid_move(char map[20][50], int yMove, int xMove)
{
	//Allow Bullet to move
	if ((map[yMove][xMove] == ' ') && (yMove >= 0))
	{
		return true;
	}
	else
	{
		//Delete Bullet
		delete_sprite(map);

		return false;
	}
}
void Bullet::set_position(int tempY, int tempX)
{
	yPos = tempY;
	xPos = tempX;
}