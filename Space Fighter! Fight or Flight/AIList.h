#pragma once
#ifndef AIList_h
#define AIList_h

#include "Sprite.h"

class AIList
{
public:		//Functions
			AIList();
			void simulate(char map[20][50]);
			void add(Sprite *ai);
			bool empty_monsters();
			
			//Variables
			int monstersLeft;

private:	//Functions
			void remove(Sprite *ai);

			//Variables
			int listSize;
			Sprite *head, *tail;
};

#endif // !AIList_h