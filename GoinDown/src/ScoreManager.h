//
// Created by ninja on 22/05/2026.
//

#pragma once
#include <fstream>
#include <string>


class ScoreManager {
private:
    int scoreFrameCounter = 0;
    int scoreCounterThreshold = 30;

    int score = 0;
    int highscore = score;

public:
    bool updatedHighscoreFromFile = false;
    bool updatedHighscoreToFile = false;

    void DrawScore() const;


    int GetHighscore() const;

    int GetScore() const;

    void UpdateScore();

    void UpdateHighscoreToFile();

    void LoadHighscoreFromFile();

    void ResetScore();
};
