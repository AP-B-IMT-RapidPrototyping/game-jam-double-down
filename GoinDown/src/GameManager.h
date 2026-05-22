//
// Created by ninja on 22/05/2026.
//

#pragma once
#include "raylib.h"

class GameManager {
private:

public:
    // Not So Beloved Constructor
    static void Init();


    // STATES
    // Game State
    static bool isGameRunning;

    enum GameState {
        GameMenu,
        GameRun,
        GameDead,
    };

    static GameState currentGameState;

    // Menu State
    enum MainMenuOptions {
        SelectPlay,
        SelectQuit
    };

    static MainMenuOptions currentMainMenuOption;


    // STATES FUNCTIONS
    // Handle Game States
    static void HandleGameMenu();

    static void HandleGameRun();

    static void HandleGameDead();

    // Handle Menu
    static void HandleMenuInput();

    //UPDATES
    static void ManageBubbles();

    static void UpdatePressure();

    // COLLISION CHECKS

    // SPAWNING
    static void SpawnEntity();

    static void CheckBubbleCollision(int i);

    //DESPAWNING
    static bool CheckOffScreen(Vector2 pos, Vector2 size);
};
