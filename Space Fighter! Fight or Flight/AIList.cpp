#include "AIList.h"

AIList::AIList()
{
	monstersLeft = 0;
	listSize = 0;
	head = 0;
	tail = 0;
}
void AIList::simulate(char map[20][50])
{
	Sprite *current = head;
	char tempSymbol;

	while (current != 0)
	{
		//Get current's symbol
		tempSymbol = current->symbol;

		//Perform simulate() function on Sprites
		current->simulate(map);

		//If Sprite is still alive move on
		if (current->health > 0)
		{
			current = current->next;
		}
		//If Sprite health is 0 delete from list and decrease monsterLeft amount
		else
		{
			Sprite *temp = current;
			current = current->next;
			remove(temp);

			if (tempSymbol == 'm')
			{
				monstersLeft--;
			}
		}
	}
}
void AIList::add(Sprite *ai)
{
	//Add new Sprite to list if list has been initialize
	if (listSize != 0)
	{
		ai->prev = tail;
		tail->next = ai;
		tail = ai;
	}
	//Initialize list if empty
	else
	{
		head = ai;
		tail = ai;
	}

	//Add one to list
	listSize++;
}
bool AIList::empty_monsters()
{
	Sprite *current = head;

	while (current != 0)
	{
		//Return false is monsters are in the list
		if (current->symbol == 'm')
		{
			return false;
		}

		current = current->next;
	}

	//Return true is no monsters are in the list
	return true;
}

void AIList::remove(Sprite *ai)
{
	if (listSize > 1)
	{
		//Set Sprite's next and prev before removing from list
		if (ai != head)
		{
			ai->prev->next = ai->next;
		}

		if (ai != tail)
		{
			ai->next->prev = ai->prev;
		}

		//Set new head and tail if Sprite was the head or tail
		if (ai == head)
		{
			head = ai->next;
		}
		else if (ai == tail)
		{
			tail = ai->prev;
		}
	}
	else
	{
		head = 0;
		tail = 0;
	}

	//Remove one from list
	listSize--;
	delete ai;
}