#pragma once

#include <iostream>
#include "raylib.h"

class building
{

public:

	Vector2 buildingPos;

	float width;
	float height;

	Color color;

	int maxHealth;
	int health;
	int defenseValue;

	int price;

	building();

	void placeBuilding(int posX, int posY);

};