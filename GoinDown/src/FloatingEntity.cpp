//
// Created by laniv on 5/22/2026.
//

#include "FloatingEntity.h"

FloatingEntity::FloatingEntity() {
    //set random start position on x as
    position.x = GetRandomValue(0, GetScreenWidth() - size.x);
    position.y = GetScreenHeight() + 50;
}

void FloatingEntity::Draw() {
    //draw temp rectangle
    DrawRectangle(position.x, position.y, 50, 50, WHITE);
}

void FloatingEntity::Update() {
    //basic position
    position.y += velocity;
}

Vector2 FloatingEntity::GetPos() {
    return position;
}

Rectangle FloatingEntity::GetCollision() {
    return Rectangle(position.x, position.y, size.x, size.y);
}

FloatingEntity::~FloatingEntity() {

}
