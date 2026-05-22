//
// Created by ninja on 22/05/2026.
//

#include "GameManager.h"

#include "raylib.h"

#define FONTHEADER 42
#define FONTDEFAULT 36


// Handle Game States
void GameManager::HandleGameMenu() {
    Color playBtnColor = (currentGameState == SelectPlay) ? GOLD : BLACK;
    Color quitBtnColor = (currentGameState == SelectQuit) ? GOLD : BLACK;

    const char *playBtnStr = "Play";
    float playBtnWidth = MeasureText(playBtnStr, FONTDEFAULT);
    DrawText(playBtnStr, GetScreenWidth() / 2 - playBtnWidth, GetScreenHeight() / 2 - 100, FONTDEFAULT, playBtnColor);

    const char *quitBtnStr = "Quit";
    float quitBtnWidth = MeasureText(quitBtnStr, FONTDEFAULT);
    DrawText(quitBtnStr, GetScreenWidth() / 2 - quitBtnWidth, GetScreenHeight() / 2 + 100, FONTDEFAULT, quitBtnColor);
}

void GameManager::HandleGameRun() {
}

void GameManager::HandleGameDead() {
    //reset
}

// Handle Menu
void GameManager::HandleMenuInput() {
    if (IsKeyPressed(KEY_DOWN)) {
        if (mainMenuOption == SelectPlay) {
            mainMenuOption = SelectQuit;
        }
    }

    if (IsKeyPressed(KEY_UP)) {
        if (mainMenuOption == SelectQuit) {
            mainMenuOption = SelectPlay;
        }
    }

    if (IsKeyPressed(KEY_ENTER)) {
        if (mainMenuOption == SelectPlay) {
            currentGameState = GameRun;
        }
        if (mainMenuOption == SelectQuit) {
            isGameRunning = false;
        }
    }
}


// Handle Collision
void GameManager::CheckFloatingEntityCollision() {
    // Check collision with Deadzones


    // Check collision with Player
}
