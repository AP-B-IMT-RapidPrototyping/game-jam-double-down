//
// Created by ninja on 22/05/2026.
//

#include "GameManager.h"

#include <iostream>
#include <memory>
#include <vector>

#include "Bubble.h"
#include "Enemy.h"
#include "PressureBar.h"
#include "raylib.h"
#include  "Player.h"

#define FONTHEADER 42
#define FONTDEFAULT 36

//Ptrs
std::vector<std::unique_ptr<Bubble> > bubbles;
std::unique_ptr<Player> player;
std::unique_ptr<PressureBar> pressureBar;


// Init
void GameManager::Init() {
    player = std::make_unique<Player>();
    pressureBar = std::make_unique<PressureBar>();
}
//PTRS



//COUNTER
int spawnCounter = 0;
int pressureCounter = 0;

// Handle Game States
void GameManager::HandleGameMenu() {
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
    //collision

    //draw pressure bar
    pressureBar->Draw();
}

void GameManager::HandleGameDead() {
    //reset
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
    }

    //check if delete
    std::erase_if(bubbles, [](const std::unique_ptr<Bubble> &bubble) {
        return bubble->toDelete;
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

//SPAWING
void GameManager::SpawnEntity() {
    spawnCounter++;
    if (spawnCounter > 200) {
        spawnCounter = 0;
        //spawn bubble
        bubbles.emplace_back(std::make_unique<Bubble>());
    }
}

//DESPAWING
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
    //if (CheckCollisionRecs(bubbles[i]->GetCollision(), player->GetCollision())) {

    //}

    // Enemy Collision
}
