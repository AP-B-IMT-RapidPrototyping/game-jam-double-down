//
// Created by laniv on 5/22/2026.
//

#include "ExplodingEnemy.h"

void ExplodingEnemy::Update() {
    position.y += velocity;

    if (isExploding) {
        explosionCounter++;
        if (explosionCounter > 20) {
            exploded = true;
        }
    }
}

int ExplodingEnemy::GetExplosionState() {
    if (!isExploding) {
        return -1;
    } else if (isExploding) {
        if (!exploded) {
            return 0;
        } else {
            return 1;
        }
    }
}

Rectangle ExplodingEnemy::GetInnerCollision() {
    Rectangle rec = Rectangle(position.x - innerMargin, position.y - innerMargin, innerCollisionSize.x, innerCollisionSize.y);
    DrawRectangleLinesEx(rec, 5, RED);
    return rec;
}

Rectangle ExplodingEnemy::GetOuterCollision() {
    Rectangle rec = Rectangle(position.x - outerMargin, position.y - outerMargin, outerCollisionSize.x, outerCollisionSize.y);
    DrawRectangleLinesEx(rec, 5, RED);
    return rec;
}
