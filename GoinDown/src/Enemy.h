//
// Created by laniv on 5/22/2026.
//

#ifndef GOINDOWN_ENEMY_H
#define GOINDOWN_ENEMY_H
#include "FloatingEntity.h"


class Enemy: public FloatingEntity {
private:
    int dmg = 1;
public:
    void Draw() override;
    int GetDamage();
};


#endif //GOINDOWN_ENEMY_H