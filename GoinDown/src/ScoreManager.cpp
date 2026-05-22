//
// Created by ninja on 22/05/2026.
//

#include "ScoreManager.h"

#include <fstream>

#include "raylib.h"


void ScoreManager::DrawScore() const {
    DrawText(std::to_string(score).c_str(), GetScreenWidth() / 2, 50, 42, WHITE);
}


int ScoreManager::GetHighscore() const {
    return highscore;
}

int ScoreManager::GetScore() const {
    return score;
}


void ScoreManager::UpdateScore() {
    scoreFrameCounter++;
    if (scoreFrameCounter >= scoreCounterThreshold) {
        score++;
        scoreFrameCounter = 0;
    }
}

// Load the highscore from the file to the game
void ScoreManager::LoadHighscoreFromFile() {
    std::ifstream iFile("highscore.txt");
    std::string line;

    if (iFile.is_open()) {
        while (std::getline(iFile, line)) {
            highscore = stoi(line);
        }

        iFile.close();
    }
}

// Update the highscore to the file
void ScoreManager::UpdateHighscoreToFile() {
    if (!updatedHighscoreToFile && score > highscore) {
        std::ofstream oFile("highscore.txt");

        highscore = score;

        if (oFile.is_open()) {
            oFile << highscore;

            oFile.close();

            updatedHighscoreToFile = true;
        }
    }
}

void ScoreManager::ResetScore() {
    score = 0;
}
