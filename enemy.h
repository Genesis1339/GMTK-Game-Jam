#pragma once

#include <iostream>
#include "raylib.h"

class enemy
{

public:

	Vector2 enemyPos;

	float width;
	float height;

	float enemySpeed;

	int health;
	int damage;

	Color color;

	enemy();
	void drawEnemy();


};