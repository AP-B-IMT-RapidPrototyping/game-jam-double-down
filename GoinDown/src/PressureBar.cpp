//
// Created by laniv on 5/22/2026.
//

#include "PressureBar.h"
#include "raylib.h"

PressureBar::PressureBar() {
    size = {200, 50};
    pos = {(float)GetScreenWidth() - size.x - 40, 50};
}

void PressureBar::Draw() const {
    //Draw background
    DrawRectangle(pos.x, pos.y, size.x, size.y, BLACK);

    DrawRectangle(pos.x, pos.y, pressure, size.y, RED);

    //Draw outline
    Rectangle rec = Rectangle(pos.x, pos.y, size.x, size.y);
    DrawRectangleLinesEx(rec, 5, WHITE);

    DrawText("pressure", pos.x, pos.y + size.y + 5, 36, WHITE);
}

void PressureBar::ChangePressure(int amount) {
    pressure += amount;
}

int PressureBar::GetPressure() const {
    return pressure;
}

void PressureBar::ResetPressure() {
    pressure = 0;
}
