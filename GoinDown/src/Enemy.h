#pragma once

#include "FloatingEntity.h"


class Enemy: public FloatingEntity {
private:
    int dmg = 1;
public:
    Enemy(bool up, float vel);
    ~Enemy();

    void Draw() override;
    int GetDamage();
};


