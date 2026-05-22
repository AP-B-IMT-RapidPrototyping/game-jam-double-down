#pragma once

#include "FloatingEntity.h"


class Bubble: public FloatingEntity {
public:
    Bubble(bool up, float vel);
    ~Bubble();

    void Draw() override;
};


