//
// Created by laniv on 5/22/2026.
//

#include "PressureBar.h"
#include "raylib.h"

PressureBar::PressureBar() {
    size = {200, 50};
    pos = {1680, 40};
}

PressureBar::~PressureBar() {

}

void PressureBar::Draw() {
    //Draw background
    DrawRectangle(pos.x, pos.y, size.x, size.y, BLACK);

    DrawRectangle(pos.x, pos.y, pressure, size.y, RED);

    //Draw outline
    Rectangle rec = Rectangle(pos.x, pos.y, size.x, size.y);
    DrawRectangleLinesEx(rec, 5, WHITE);
}

void PressureBar::ChangePressure(int amount) {
    pressure += amount;
}

int PressureBar::GetPressure() {
    return pressure;
}
