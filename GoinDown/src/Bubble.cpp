//
// Created by laniv on 5/22/2026.
//

#include "Bubble.h"


Bubble::Bubble(bool up, float vel) : FloatingEntity(up, vel) {
    Image bubbleImg = LoadImage("../assets/bubble.png");
    bubbleTexture = LoadTextureFromImage(bubbleImg);
    UnloadImage(bubbleImg);
}

Bubble::~Bubble() {
    UnloadTexture(bubbleTexture);
}

void Bubble::Draw() {
    DrawTexture(bubbleTexture, position.x, position.y, WHITE);
}
