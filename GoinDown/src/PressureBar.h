#pragma once
#include "raylib.h"


class PressureBar {
private:
    Vector2 size;
    Vector2 pos;
    int pressure = 0;
public:
    PressureBar();
    ~PressureBar();

    void Draw();
    void ChangePressure(int amount);
    int GetPressure();
    void ResetPressure();
};


