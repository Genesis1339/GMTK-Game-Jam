#include <iostream>

#include <string>

#include <vector>
#include <algorithm>

#include "raylib.h"

#include "building.h"
#include "enemy.h"


class gameState
{

public:

	float shopButtonWidth;
	float shopButtonHeight; 
	Color shopButtonColor; 
	Vector2 shopButtonPos;

	float shopWidth;
	float shopHeight;
	Vector2 shopPos;

	bool mouseOverUI;

	Vector2 basePosition;
	float baseWidth;
	float baseHeight;
	
	Color baseColor;

	int playerHealth;

	int currentEnemyCount;
	int waveSpawnNo;

	int waveIncrementAmount;

	int currentWave;
	int currentGold;

	bool isShopOpen;

	int repairValue;

	int waveBonus;

	bool buildPhase;

	float countdownTimer;
	float enemyCountdown;

	enum buildingMaterial
	{

		WOOD = 0,
		BRICK = 1,
		METAL = 2

	};

	buildingMaterial currentMaterial;

	std::vector<building> buildings;
	std::vector<enemy> enemies;

	gameState();

	void shopButton();
	void shop();

	void buyWoodMaterial();
	void buyBrickMaterial();
	void buyMetalMaterial();


	void playerDeath();
	void deathScreen();

	void playAgainButton();
	void quitButton();

	void drawPlayerBase();

	void enemyCollisionWithBase();

	void buildCountdown();
	void drawCountdown();

	void enemyAttackCountdown();
	void drawEnemyAttackCountdown();

	void countdown();

	void drawWaveCount();
	void drawCurrentGold();

	void controls();

	void drawBuilding();
	void destroyBuilding();

	void displayBuildingHealth();

	void repairBuilding();

	void spawnEnemy();
	void moveEnemy();

	void enemyCollision();
	void enemyDeath();
	void enemyDestruction();

	void displayEnemyHealth();

	void newWave();

	void nextWave();

};