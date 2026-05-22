#pragma once

#include "Enemy.h"


class ExplodingEnemy : public Enemy {
private :
    int explosionCounter = 0;

    const int innerMargin = 30;
    const int outerMargin = 40;

    Vector2 innerCollisionSize = { size.x + innerMargin*2, size.y + innerMargin*2};
    Vector2 outerCollisionSize = { size.x + outerMargin*2, size.y + outerMargin*2};
public:
    bool isExploding = false;
    bool exploded = false;

    ExplodingEnemy(bool up, float vel);

    void Update() override;

    int GetExplosionState() const;
    Rectangle GetInnerCollision() const;
    Rectangle GetOuterCollision() const;
};


