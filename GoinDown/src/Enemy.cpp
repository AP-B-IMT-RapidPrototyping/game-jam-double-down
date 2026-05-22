//
// Created by laniv on 5/22/2026.
//

#include "Enemy.h"

Enemy::Enemy(bool up, float vel): FloatingEntity(up, vel) {}

void Enemy::Draw() {
    DrawRectangle(position.x, position.y, 50, 50, RED);
}

int Enemy::GetDamage() const {
    return dmg;
}

