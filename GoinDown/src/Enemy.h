#pragma once

#include "FloatingEntity.h"


class Enemy: public FloatingEntity {
private:
    int dmg = 1;
public:
    void Draw() override;
    int GetDamage();
};


