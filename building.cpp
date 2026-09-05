#include "building.h"

building::building()
{

	buildingPos.x = 0;
	buildingPos.y = 0;

	width = 30.0f;
	height = 80.0f;

	//color = BROWN;


	maxHealth = 50;
	health = maxHealth;
	defenseValue = 10;

	price = 25;

}

void building::placeBuilding(int posX, int posY)
{
	
	DrawRectangle(posX, posY, width, height, color);

}

