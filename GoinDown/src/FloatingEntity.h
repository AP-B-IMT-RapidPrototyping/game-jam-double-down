#pragma once
#include "raylib.h"


class FloatingEntity {
protected:
    Vector2 position = {200, (float)GetScreenHeight()};
    Vector2 size = {50, 50};
    float velocity = -2;
public:
    bool toDelete = false;

    FloatingEntity();
    ~FloatingEntity();

    virtual void Update();
    virtual void Draw();
    Vector2 GetPos();
    Vector2 GetSize();
    Rectangle GetCollision();
};


