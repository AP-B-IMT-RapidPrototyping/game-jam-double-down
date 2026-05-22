//
// Created by ninja on 22/05/2026.
//

#include "GameManager.h"

#include <memory>
#include <vector>

#include "Bubble.h"
#include "Enemy.h"
#include "raylib.h"

#define FONTHEADER 42
#define FONTDEFAULT 36

//Ptrs
std::vector<std::unique_ptr<Bubble> > bubbles;


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

    //collision

    //draw;
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


// HANDLE COLLISIONS

// Bubble Collision
void GameManager::CheckBubbleCollision(int i) {
    // Check collision with Player
    //if (CheckCollisionRecs(bubbles[i]->GetCollision(), player->GetCollision())) {

    //}

    // Enemy Collision
}
