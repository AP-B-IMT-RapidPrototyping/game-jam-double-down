//
// Created by ninja on 22/05/2026.
//

#include "GameManager.h"

#include <iostream>
#include <memory>
#include <vector>
#include <bits/parse_numbers.h>

#include "Bubble.h"
#include "Enemy.h"
#include "ExplodingEnemy.h"
#include "PressureBar.h"
#include "raylib.h"
#include  "Player.h"
#include "ScoreManager.h"
#include "FloatingEntity.h"

#define FONTHEADER 42
#define FONTDEFAULT 36

//Ptrs
std::vector<std::unique_ptr<Bubble> > bubbles;
std::vector<std::unique_ptr<Enemy> > enemies;
std::vector<std::unique_ptr<ExplodingEnemy> > explodingEnemies;
std::unique_ptr<Player> player;
std::unique_ptr<PressureBar> pressureBar;
std::unique_ptr<ScoreManager> scoreManager;

// Init
void GameManager::Init() {
    player = std::make_unique<Player>();
    pressureBar = std::make_unique<PressureBar>();
    scoreManager = std::make_unique<ScoreManager>();
}

//PTRS


//COUNTER
int spawnCounter = 0;
int bubbleSpawnCounter = 0;
int pressureCounter = 0;
int difficultyCounter = 0;
int enemySpawnTime = 100;
int endCounter = 0;


bool isGoingDown = true;

// Handle Game States
void GameManager::HandleGameMenu() {
    if (!scoreManager->updatedHighscoreFromFile) {
        scoreManager->LoadHighscoreFromFile();
        scoreManager->updatedHighscoreFromFile = true;
        scoreManager->updatedHighscoreToFile = false;
    }

    DrawText("Previous Highscore: ", 50, 50, 42, WHITE);
    DrawText(std::to_string(scoreManager->GetHighscore()).c_str(), 500, 50, 42, WHITE);

    Color playBtnColor = (currentMainMenuOption == SelectPlay) ? GOLD : BLACK;
    Color quitBtnColor = (currentMainMenuOption == SelectQuit) ? GOLD : BLACK;

    const char *playBtnStr = "Play";
    int playBtnWidth = MeasureText(playBtnStr, FONTDEFAULT);
    DrawText(playBtnStr, GetScreenWidth() / 2 - playBtnWidth, GetScreenHeight() / 2 - 100, FONTDEFAULT, playBtnColor);

    const char *quitBtnStr = "Quit";
    int quitBtnWidth = MeasureText(quitBtnStr, FONTDEFAULT);
    DrawText(quitBtnStr, GetScreenWidth() / 2 - quitBtnWidth, GetScreenHeight() / 2 + 100, FONTDEFAULT, quitBtnColor);
}

void GameManager::HandleGameRun() {
    //update
    player->Run();
    //update counters
    SpawnEntity();
    UpdatePressure();

    //manage bubbles
    ManageBubbles();

    //manage enemies
    ManageEnemies();
    ManageExplodingEnemies();

    //draw pressure bar
    pressureBar->Draw();

    // Handle score
    scoreManager->DrawScore();
    scoreManager->UpdateScore();

    if (IsKeyPressed(KEY_SPACE)) {
        isGoingDown = false;
        for (unsigned int i = 0; i < enemies.size(); i++) {
            enemies[i]->velocity = 8;
        }
        for (unsigned int i = 0; i < explodingEnemies.size(); i++) {
            explodingEnemies[i]->velocity = 8;
        }

        for (unsigned int i = 0; i < bubbles.size(); i++) {
            bubbles[i]->velocity = 8;
        }
    }
}

void GameManager::HandleGameDead() {
    scoreManager->UpdateHighscoreToFile();
    scoreManager->ResetScoreAndUpdateHighscore();
    player->ResetHealth();

    DrawText("Score: ", 50, 50, 42, WHITE);
    DrawText(std::to_string(scoreManager->GetHighscore()).c_str(), 300, 50, 42, WHITE);


    DrawText("Space to retry!", GetScreenWidth() / 2 - 200, GetScreenHeight() - 150, 42, WHITE);
    if (IsKeyPressed(KEY_SPACE)) {
        currentGameState = GameRun;
    }
}

// Handle Menu
void GameManager::HandleMenuInput() {
    if (IsKeyPressed(KEY_DOWN)) {
        if (currentMainMenuOption == SelectPlay) {
            currentMainMenuOption = SelectQuit;
        }
    }

    if (IsKeyPressed(KEY_UP)) {
        if (currentMainMenuOption == SelectQuit) {
            currentMainMenuOption = SelectPlay;
        }
    }

    if (IsKeyPressed(KEY_ENTER)) {
        if (currentMainMenuOption == SelectPlay) {
            currentGameState = GameRun;
        }
        if (currentMainMenuOption == SelectQuit) {
            isGameRunning = false;
        }
    }
}

//UPDATES
void GameManager::ManageBubbles() {
    for (unsigned int i = 0; i < bubbles.size(); i++) {
        bubbles[i]->Update();
        bubbles[i]->Draw();
        bubbles[i]->toDelete = CheckOffScreen(bubbles[i]->GetPos(), bubbles[i]->GetSize());
        CheckBubbleCollision(i);
    }

    //check if delete
    std::erase_if(bubbles, [](const std::unique_ptr<Bubble> &bubble) {
        return bubble->toDelete;
    });
}

void GameManager::ManageEnemies() {
    for (unsigned int i = 0; i < enemies.size(); i++) {
        enemies[i]->Update();
        enemies[i]->Draw();
        enemies[i]->toDelete = CheckOffScreen(enemies[i]->GetPos(), enemies[i]->GetSize());
        CheckEnemyCollision(i);
    }

    //check if delete
    std::erase_if(enemies, [](const std::unique_ptr<Enemy> &enemy) {
        return enemy->toDelete;
    });
}

void GameManager::ManageExplodingEnemies() {
    for (unsigned int i = 0; i < explodingEnemies.size(); i++) {
        explodingEnemies[i]->Update();
        explodingEnemies[i]->Draw();
        explodingEnemies[i]->toDelete = CheckOffScreen(explodingEnemies[i]->GetPos(), explodingEnemies[i]->GetSize());
        CheckExplodingEnemyCollision(i);
    }

    //check if delete
    std::erase_if(explodingEnemies, [](const std::unique_ptr<ExplodingEnemy> &enemy) {
        return enemy->toDelete;
    });
}

void GameManager::UpdatePressure() {
    pressureCounter++;
    if (pressureCounter > 100) {
        pressureBar->ChangePressure(10);
        pressureCounter = 0;

        if (pressureBar->GetPressure() > 190) {
            currentGameState = GameDead;
        }
    }
}

//SPAWNING
void GameManager::SpawnEntity() {
    spawnCounter++;
    if (spawnCounter > enemySpawnTime) {
        spawnCounter = 0;

        int entityToSpawn = GetRandomValue(1, 3);
        if (entityToSpawn == 1 || entityToSpawn == 2) {
            if (isGoingDown) {
                enemies.emplace_back(std::make_unique<Enemy>(true, -5));
            } else {
                enemies.emplace_back(std::make_unique<Enemy>(false, 8));
            }
        } else {
            if (isGoingDown) {
                explodingEnemies.emplace_back(std::make_unique<ExplodingEnemy>(true, -5));
            } else {
                explodingEnemies.emplace_back(std::make_unique<ExplodingEnemy>(false, 8));
            }
        }
    }

    if (isGoingDown) {
        bubbleSpawnCounter++;
        if (bubbleSpawnCounter > 200) {
            bubbleSpawnCounter = 0;
            bubbles.emplace_back(std::make_unique<Bubble>(true, -5));
        }
    }


    difficultyCounter++;
    if (difficultyCounter > 500) {
        difficultyCounter = 0;
        enemySpawnTime -= 10;
    }
}

//DESPAWNING
bool GameManager::CheckOffScreen(Vector2 pos, Vector2 size) {
    int despawnMargin = 50;
    if (pos.y + despawnMargin < 0 || pos.y - despawnMargin > GetScreenHeight()) {
        return true;
    } else {
        return false;
    }
}


// HANDLE COLLISIONS

// Bubble Collision
void GameManager::CheckBubbleCollision(int i) {
    // Check collision with Player
    if (CheckCollisionRecs(bubbles[i]->GetCollision(), player->GetCollision())) {
        bubbles[i]->toDelete = true;
        pressureBar->ChangePressure(-20);
    }
}

// Enemy Collision
void GameManager::CheckEnemyCollision(int i) {
    // Check collision with Player
    if (CheckCollisionRecs(enemies[i]->GetCollision(), player->GetCollision())) {
        enemies[i]->toDelete = true;
        player->TakeDamage(enemies[i]->GetDamage());


        if (player->GetHealth() <= 0) {
            currentGameState = GameDead;
        }
    }
}

// Exploding enemy Collision
void GameManager::CheckExplodingEnemyCollision(int i) {
    // Check collision with Player

    //check explosion state
    if (explodingEnemies[i]->GetExplosionState() == -1) {
        //enemy not exploding
        //check if the player collides with inner collision shape
        if (CheckCollisionRecs(explodingEnemies[i]->GetInnerCollision(), player->GetCollision())) {
            //if player collides, start exploding
            explodingEnemies[i]->isExploding = true;
        }
    } else if (explodingEnemies[i]->GetExplosionState() == 1) {
        //enemy exploded
        //check if the player collides with outer collision shape
        if (CheckCollisionRecs(explodingEnemies[i]->GetOuterCollision(), player->GetCollision())) {
            //if player collides, player takes damage
            player->TakeDamage(2);
        }

        explodingEnemies[i]->toDelete = true;
    }
}
