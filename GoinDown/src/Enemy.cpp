//
// Created by laniv on 5/22/2026.
//

#include "Enemy.h"

void Enemy::Draw() {
    DrawRectangle(position.x, position.y, 50, 50, RED);
}

int Enemy::GetDamage() {
    return dmg;
}
