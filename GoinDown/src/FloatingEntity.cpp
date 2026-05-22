//
// Created by laniv on 5/22/2026.
//

#include "FloatingEntity.h"

FloatingEntity::FloatingEntity(bool up, float vel) {
    //set random start position on x as
    position.x = GetRandomValue(0, GetScreenWidth() - size.x);
    if (!up) {
        position.y = -size.y;
    } else {
        position.y = (float)GetScreenHeight();
    }

    velocity = vel;
    goingUp = up;
}

void FloatingEntity::Draw() {
    // draw temp rectangle
    DrawRectangle(position.x, position.y, 50, 50, WHITE);
}

void FloatingEntity::Update() {
    // basic position
    position.y += velocity;
}

Vector2 FloatingEntity::GetPos() const {
    return position;
}

Vector2 FloatingEntity::GetSize() const {
    return size;
}

Rectangle FloatingEntity::GetCollision() const {
    return Rectangle(position.x, position.y, size.x, size.y);
}


