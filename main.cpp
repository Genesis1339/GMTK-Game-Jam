#include <iostream>
#include "raylib.h"

#include "gameState.h"


int main(void)
{


    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "game");

    SetTargetFPS(60);               

    gameState mainState;

    while (!WindowShouldClose())    
    {
        // Update
        //----------------------------------------------------------------------------------
      
      
        mainState.moveEnemy();
        mainState.enemyCollision();
        mainState.enemyCollisionWithBase();
        mainState.repairBuilding();

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(DARKGREEN);

        mainState.drawPlayerBase();

        mainState.countdown();
        mainState.drawWaveCount();
        mainState.drawCurrentGold();
        mainState.displayBuildingHealth();
        mainState.displayEnemyHealth();

        mainState.shopButton();

        mainState.drawBuilding();

        mainState.spawnEnemy();
        
        EndDrawing();
        //----------------------------------------------------------------------------------
    }


    CloseWindow();        


    return 0;
}