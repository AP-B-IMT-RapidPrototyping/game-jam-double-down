//
// Created by laniv on 5/22/2026.
//

#include "Bubble.h"

Bubble::Bubble(bool up, float vel): FloatingEntity(up, vel) {

}

void Bubble::Draw() {
    DrawRectangle(position.x, position.y, size.x, size.y, BLUE);
}

Bubble::~Bubble() {

}
