//
// Created by ninja on 22/05/2026.
//

#include "ScoreManager.h"

#include <fstream>

#include "raylib.h"


void ScoreManager::DrawScore() {
    DrawText(std::to_string(score).c_str(), 50, 50, 42, WHITE);
}


int ScoreManager::GetHighscore() {
    return highscore;
}


void ScoreManager::UpdateScore() {
    scoreFrameCounter++;
    if (scoreFrameCounter >= scoreCounterThreshold) {
        score++;
        scoreFrameCounter = 0;
    }
}

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

void ScoreManager::ResetScoreAndUpdateHighscore() {
    score = 0;
}
