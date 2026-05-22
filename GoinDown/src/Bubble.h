#pragma once

#include "FloatingEntity.h"


class Bubble : public FloatingEntity {
private:
    Texture bubbleTexture;

    public:
    Bubble(bool up, float vel);

    ~Bubble();

    void Draw() override;
};
