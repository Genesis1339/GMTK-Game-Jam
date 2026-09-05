#include "enemy.h"

enemy::enemy()
{

	enemyPos.x = 0;
	enemyPos.y = 0;

	enemySpeed = 50.0f;

	width = 25.0f;
	height = 25.0f;

	health = 100;
	damage = 10;

	color = RED;



}

void enemy::drawEnemy()
{

	DrawRectangle(enemyPos.x, enemyPos.y, width, height, color);

}
