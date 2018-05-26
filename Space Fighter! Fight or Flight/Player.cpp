#include "Player.h"

Player::Player()
{

}

Player::Player(char tempSymbol, int tempY, int tempX, int tempHealth) : Sprite(tempSymbol, tempY, tempX, tempHealth)
{

}

void Player::player_action(char map[20][50], char *key, AIList *aiList)
{
	//Perform action based off of user keystroke
	player_move(map, key);
	player_shoot(map, key, aiList);
}

void Player::player_move(char map[20][50], char *key)
{
	//Move player left if 'a' is hit
	if (*key == 'a')
	{
		Sprite::move(map, 0, -1);
	}

	//Move player right if 'd' is hit
	if (*key == 'd')
	{
		Sprite::move(map, 0, 1);
	}
}

void Player::player_shoot(char map[20][50], char *key, AIList *aiList)
{
	//Add new Bullet to aiList if Spacebar is pressed
	if (*key == ' ')
	{
		Bullet *bullet = new Bullet('|', 0, 0, 1);
		bullet->set_position(yPos - 1, xPos);
		map[0][0] = 219;
		aiList->add(bullet);
	}
}