#include <iostream>
#include <memory>

#include "GameManager.h"
#include "raylib.h"


#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define FPS 60


bool GameManager::isGameRunning = true;
GameManager::GameState GameManager::currentGameState = GameManager::GameMenu;
GameManager::MainMenuOptions GameManager::currentMainMenuOption = GameManager::SelectPlay;

int main() {
    std::cout << "Hello, World!" << std::endl;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Goin' Down");
    SetTargetFPS(FPS);


    GameManager::Init();


    while (!WindowShouldClose() && GameManager::isGameRunning) {
        BeginDrawing();
        ClearBackground(DARKBLUE); //later donkerder en donkerder??

        // GAME STATE MACHINE
        switch (GameManager::currentGameState) {
            case GameManager::GameMenu:
                GameManager::HandleGameMenu();
                GameManager::HandleMenuInput();
                break;

            case GameManager::GameRun:
                GameManager::HandleGameRun();
                break;

            case GameManager::GameDead:
                GameManager::HandleGameDead();
                break;
        }

        EndDrawing();
    }

    return 0;
}
