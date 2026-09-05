#include "gameState.h"


gameState::gameState()
{

	mouseOverUI = false;

	basePosition.x = GetScreenWidth() - 50;
	basePosition.y = 0;
	baseWidth = 50.0f;
	baseHeight = GetScreenHeight();

	baseColor = GREEN;

	playerHealth = 250;

	currentEnemyCount = 0;
	waveSpawnNo = 4;

	waveIncrementAmount = 2;

	currentWave = 1;
	currentGold = 100;

	isShopOpen = false;

	repairValue = 5;

	waveBonus = 0;

	buildPhase = true;

	countdownTimer = 60.0f;
	enemyCountdown = 30.0f;

	currentMaterial = buildingMaterial::WOOD;

}

void gameState::shopButton()
{

	mouseOverUI = false;

	float shopButtonWidth = 200.0f;
	float shopButtonHeight = 100.0f;
	Color shopButtonColor = WHITE;

	Vector2 shopButtonPos = { GetScreenWidth() - shopButtonWidth, GetScreenHeight() - shopButtonHeight };


	DrawRectangle(shopButtonPos.x, shopButtonPos.y, shopButtonWidth, shopButtonHeight, shopButtonColor);

	DrawText("SHOP", shopButtonPos.x + 50, shopButtonPos.y + 45, 35, BLACK);

	if (CheckCollisionPointRec(GetMousePosition(), { shopButtonPos.x, shopButtonPos.y, shopButtonWidth, shopButtonHeight }))
	{

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			isShopOpen = true;
	}

	shop();

	float closeShopWidth = 50.0f;
	float closeShopHeight = 50.0f;
	Color closeShopColor = RED;

	Vector2 closeShopPos = { GetScreenWidth() - closeShopWidth,0};

	if (isShopOpen == true)
	{
		DrawRectangle(closeShopPos.x, closeShopPos.y, closeShopWidth, closeShopHeight, closeShopColor);

		if (CheckCollisionPointRec(GetMousePosition(), { closeShopPos.x, closeShopPos.y, closeShopWidth, closeShopHeight }))
		{

			mouseOverUI = true;

			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				isShopOpen = false;
			}

		}

	}

	//mouseOverUI = false;

}

void gameState::shop()
{

	shopWidth = baseWidth * 5;
	shopHeight = baseHeight;
	shopPos = { basePosition.x - (baseWidth * 4),  basePosition.y };

	if (isShopOpen == true)
	{

		DrawRectangle(shopPos.x, shopPos.y, shopWidth, shopHeight, GRAY);

		buyWoodMaterial();
		buyBrickMaterial();
		buyMetalMaterial();

	}

}

void gameState::buyWoodMaterial()
{

	float buyWidth = ((baseWidth * 5) - 20.0f);
	float buyHeight = (baseHeight / 6);
	Vector2 buyPos = { (GetScreenWidth() - buyWidth) - 8, 75};

	DrawRectangle(buyPos.x, buyPos.y, buyWidth, buyHeight, WHITE);
	DrawText("WOOD", buyPos.x + 70, buyPos.y + 70, 35, BLACK);

	DrawText("25", buyPos.x + 100, buyPos.y + 140, 35, GOLD);

	if (CheckCollisionPointRec(GetMousePosition(), { buyPos.x, buyPos.y, buyWidth, buyHeight }))
	{

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			currentMaterial = buildingMaterial::WOOD;
	}

}

void gameState::buyBrickMaterial()
{

	float buyWidth = ((baseWidth * 5) - 20.0f);
	float buyHeight = (baseHeight / 6);
	Vector2 buyPos = { (GetScreenWidth() - buyWidth) - 8, 300 };

	DrawRectangle(buyPos.x, buyPos.y, buyWidth, buyHeight, WHITE);
	DrawText("BRICK", buyPos.x + 70, buyPos.y + 70, 35, BLACK);

	DrawText("50", buyPos.x + 100, buyPos.y + 140, 35, GOLD);

	if (CheckCollisionPointRec(GetMousePosition(), { buyPos.x, buyPos.y, buyWidth, buyHeight }))
	{

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			currentMaterial = buildingMaterial::BRICK;
	}

}

void gameState::buyMetalMaterial()
{

	float buyWidth = ((baseWidth * 5) - 20.0f);
	float buyHeight = (baseHeight / 6);
	Vector2 buyPos = { (GetScreenWidth() - buyWidth) - 8, 535 };

	DrawRectangle(buyPos.x, buyPos.y, buyWidth, buyHeight, WHITE);
	DrawText("METAL", buyPos.x + 70, buyPos.y + 70, 35, BLACK);

	DrawText("100", buyPos.x + 100, buyPos.y + 140, 35, GOLD);

	if (CheckCollisionPointRec(GetMousePosition(), { buyPos.x, buyPos.y, buyWidth, buyHeight }))
	{

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			currentMaterial = buildingMaterial::METAL;
	}

}

void gameState::playerDeath()
{

	if (playerHealth <= 0)
	{
		deathScreen();
	}

}

void gameState::deathScreen()
{

	DrawRectangle((GetScreenWidth() / 2) - (250 / 2), (GetScreenHeight() / 2) - (300 / 2), 250, 300, DARKGRAY);
	DrawText("GAME OVER", (GetScreenWidth() / 2) - (250 / 2) + 23, (GetScreenHeight() / 2) - (300 / 2) + 20, 35, RED);

	enemyCountdown = 0;
	countdownTimer = 0;

	playAgainButton();
	quitButton();

}

void gameState::playAgainButton()
{

	float buttonWidth = 200;
	float buttonHeight = 75;

	Vector2 buttonPos = { ((GetScreenWidth() / 2) - (buttonWidth / 2)) , ((GetScreenHeight() / 2) - (buttonHeight / 2) - 25) };

	Color buttonColor = LIME;

	DrawRectangle(buttonPos.x, buttonPos.y, buttonWidth, buttonHeight, buttonColor);
	DrawText("PLAY AGAIN", (GetScreenWidth() / 2) - (buttonWidth / 2) + 23, ((GetScreenHeight() / 2) - (buttonHeight / 2) - 25) + 25, 25, BLACK);

	if (CheckCollisionPointRec(GetMousePosition(), { buttonPos.x, buttonPos.y, buttonWidth, buttonHeight }))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			currentEnemyCount = 0;
			waveSpawnNo = 4;

			waveIncrementAmount = 2;

			currentWave = 1;
			currentGold = 100;

			repairValue = 5;

			waveBonus = 0;

			buildPhase = true;

			countdownTimer = 60.0f;
			enemyCountdown = 30.0f;

			playerHealth = 250;
		}

	}

}

void gameState::quitButton()
{

	float buttonWidth = 200;
	float buttonHeight = 75;

	Vector2 buttonPos = { ((GetScreenWidth() / 2) - (buttonWidth / 2)) , ((GetScreenHeight() / 2) + (buttonHeight / 2) ) };

	Color buttonColor = MAROON;

	DrawRectangle(buttonPos.x, buttonPos.y, buttonWidth, buttonHeight, buttonColor);
	DrawText("QUIT", (GetScreenWidth() / 2) - (buttonWidth / 2) + 23, ((GetScreenHeight() / 2) + (buttonHeight / 2)) + 25, 25, BLACK);

	if (CheckCollisionPointRec(GetMousePosition(), { buttonPos.x, buttonPos.y, buttonWidth, buttonHeight }))
	{

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{

			std::exit(-1);

		}

	}
		
}

void gameState::drawPlayerBase()
{

	DrawRectangle(basePosition.x, basePosition.y, baseWidth, baseHeight, baseColor);

}

void gameState::enemyCollisionWithBase()
{

	enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
		[&](const enemy& enemy)
		{

			if (CheckCollisionRecs({ basePosition.x, basePosition.y, baseWidth, baseHeight }, { enemy.enemyPos.x, enemy.enemyPos.y, enemy.width, enemy.height }))
			{

				playerHealth -= enemy.damage;
				currentEnemyCount -= 1;

				return true;

			}
			else
				return false;

		}),
		enemies.end());

	nextWave();
	playerDeath();

}

void gameState::buildCountdown()
{


	if (countdownTimer > 0)
	{

		countdownTimer -= GetFrameTime();

		if (countdownTimer <= 0)
		{
			countdownTimer = 0.0f;

			buildPhase = false;

		}

		drawCountdown();

	}



}

void gameState::drawCountdown()
{

	int secondsTimer = (int)countdownTimer;
	std::string stringCountdown = std::to_string(secondsTimer);

	DrawRectangle((GetScreenWidth() / 2) - (150 / 2), 5, 150, 75, LIGHTGRAY);

	DrawText(stringCountdown.c_str(), (GetScreenWidth() / 2) - (150 / 2) + 45, 20, 50, BLACK);

}

void gameState::enemyAttackCountdown()
{


	if (enemyCountdown > 0)
	{

		enemyCountdown -= GetFrameTime();

		if (enemyCountdown <= 0)
		{
			enemyCountdown = 0.0f;

			newWave();
		}

		drawEnemyAttackCountdown();

	}



}

void gameState::drawEnemyAttackCountdown()
{

	int enemySecondsTimer = (int)enemyCountdown;
	std::string enemyStringCountdown = std::to_string(enemySecondsTimer);

	DrawRectangle((GetScreenWidth() / 2) - (150 / 2), 5, 150, 75, DARKGRAY);

	DrawText(enemyStringCountdown.c_str(), (GetScreenWidth() / 2) - (150 / 2) + 45, 20, 50, BLACK);

}

void gameState::countdown()
{

	if (buildPhase == true)
	{
		buildCountdown();
		enemyCountdown = 30.0f;

		for (auto& enemy : enemies)
		{

			enemyDestruction();

		}

		currentEnemyCount = 0;
		
	}
	else
	{
		enemyAttackCountdown();
		countdownTimer = 60.0f;
	}

}



void gameState::drawWaveCount()
{

	std::string waveCountString = std::to_string(currentWave);

	DrawText(waveCountString.c_str(), (GetScreenWidth()) - 125, 20, 50, WHITE);

}

void gameState::drawCurrentGold()
{

	std::string goldCountString = std::to_string(currentGold);

	DrawText(goldCountString.c_str(), (GetScreenWidth()) - 160, GetScreenHeight() - 150, 50, GOLD);

}

void gameState::controls()
{

	

}


void gameState::drawBuilding()
{

	if (buildPhase == true)
	{

		if (isShopOpen == false && mouseOverUI == false)
		{

			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{

				building newBuilding;

				if (currentMaterial == buildingMaterial::WOOD)
				{

					newBuilding.color = BROWN;
					newBuilding.price = 25;
					newBuilding.maxHealth = 50;
					newBuilding.health = newBuilding.maxHealth;
					newBuilding.defenseValue = 10;


				}
				else if (currentMaterial == buildingMaterial::BRICK)
				{

					newBuilding.color = MAROON;
					newBuilding.price = 50;
					newBuilding.maxHealth = 100;
					newBuilding.health = newBuilding.maxHealth;
					newBuilding.defenseValue = 20;

				}
				else if (currentMaterial == buildingMaterial::METAL)
				{

					newBuilding.color = GRAY;
					newBuilding.price = 100;
					newBuilding.maxHealth = 150;
					newBuilding.health = newBuilding.maxHealth;
					newBuilding.defenseValue = 30;

				}

				newBuilding.buildingPos.x = (GetMouseX() - (newBuilding.width / 2));
				newBuilding.buildingPos.y = (GetMouseY() - (newBuilding.height / 2));

				if (currentGold >= newBuilding.price)
				{
					buildings.push_back(newBuilding);

					currentGold -= newBuilding.price;

					std::cout << currentMaterial << std::endl;
				}


			}


		}		

		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
		{

			buildings.erase(std::remove_if(buildings.begin(), buildings.end(),
				[&](const building& building)
				{
					
					if (CheckCollisionPointRec(GetMousePosition(), { building.buildingPos.x, building.buildingPos.y, building.width, building.height }))
					{
						currentGold += building.price;
						return true;
					}
					else
						return false;


				}),
				buildings.end());



		}
	}

	for (auto& building : buildings)
	{

		building.placeBuilding(building.buildingPos.x, building.buildingPos.y);
	}

}

void gameState::destroyBuilding()
{

	buildings.erase(std::remove_if(buildings.begin(), buildings.end(),
		[&](const building& building)
		{

			return building.health == 0;

		}),
		buildings.end());

}

void gameState::displayBuildingHealth()
{

	for (auto& building : buildings)
	{

		if (CheckCollisionPointRec(GetMousePosition(), { building.buildingPos.x, building.buildingPos.y, building.width, building.height }))
		{
			DrawRectangle((building.buildingPos.x + building.width + 10), building.buildingPos.y + (building.height - 15), building.health, 10, RED);
		}

	}

}

void gameState::repairBuilding()
{

	for (auto& building : buildings)
	{

		if (CheckCollisionPointRec(GetMousePosition(), { building.buildingPos.x, building.buildingPos.y, building.width, building.height }))
		{

			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{

				if (building.health < building.maxHealth)
					building.health += repairValue;

			}

		}


	}

}


void gameState::spawnEnemy()
{

	if (buildPhase == false)
	{

		while (currentEnemyCount < waveSpawnNo)
		{
			enemy newEnemy;

			bool validPosition = false;

			while (!validPosition)
			{
				newEnemy.enemyPos.x = 0;
				newEnemy.enemyPos.y = rand() % (GetScreenHeight() - 50);

				validPosition = true;

				for (auto& enemy : enemies)
				{
					float distance = abs(newEnemy.enemyPos.y - enemy.enemyPos.y);

					if (distance < 50) 
					{
						validPosition = false;
						break;
					}
				}
			}

			enemies.push_back(newEnemy);

			currentEnemyCount += 1;
		}

		for (auto& enemy : enemies)
		{
			enemy.drawEnemy();
		}
	}

}

void gameState::moveEnemy()
{

	for (auto& enemy : enemies)
	{

		enemy.enemyPos.x += enemy.enemySpeed * GetFrameTime();

	}

}

void gameState::enemyCollision()
{

	for (auto& building : buildings)
	{

		for (auto& enemy : enemies)
		{

			if (CheckCollisionRecs({ building.buildingPos.x, building.buildingPos.y, building.width, building.height }, { enemy.enemyPos.x, enemy.enemyPos.y, enemy.width, enemy.height }))
			{

				building.health -= (enemy.damage * GetFrameTime());
				if (building.health == 0)
				{
					destroyBuilding();
					enemy.enemySpeed = 15.0f;
				}

			}

			if (CheckCollisionRecs({ enemy.enemyPos.x, enemy.enemyPos.y, enemy.width, enemy.height }, { building.buildingPos.x, building.buildingPos.y, building.width, building.height }))
			{

				enemy.enemySpeed = 0.0f;
				enemy.health -= (building.defenseValue * GetFrameTime());

				if (enemy.health == 0)
					enemyDeath();


			}

		}

	}

}

void gameState::enemyDeath()
{

	enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
		[&](const enemy& Enemy)
		{

			nextWave();
			currentEnemyCount -= 1;
			return Enemy.health == 0;

		}),
		enemies.end());

}

void gameState::enemyDestruction()
{

	enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
		[&](const enemy& Enemy)
		{

			return buildPhase == true;

		}),
		enemies.end());

}

void gameState::displayEnemyHealth()
{

	for (auto& enemy : enemies)
	{

		if (CheckCollisionPointRec(GetMousePosition(), { enemy.enemyPos.x, enemy.enemyPos.y, enemy.width, enemy.height }))
		{
			DrawRectangle((enemy.enemyPos.x + enemy.width + 10), enemy.enemyPos.y + (enemy.height - 15), enemy.health / 4, 10, RED);
		}

	}

}

void gameState::newWave()
{

	currentWave += 1;
	waveSpawnNo += waveIncrementAmount;

	waveBonus = (100 + (currentWave * 25));
	currentGold += waveBonus;

}

void gameState::nextWave()
{

	if (currentEnemyCount <= 0)
	{

		buildPhase = true;

		countdown();

	}


}
