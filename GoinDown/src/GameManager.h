//
// Created by ninja on 22/05/2026.
//

#pragma once

class GameManager {
private:


public:
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

    static MainMenuOptions mainMenuOption;


    // STATES FUNCTIONS
    // Handle Game States
    static void HandleGameMenu();

    static void HandleGameRun();

    static void HandleGameDead();

    // Handle Menu
    static void HandleMenuInput();


    // COLLISION CHECKS
    static void CheckFloatingEntityCollision();
};
