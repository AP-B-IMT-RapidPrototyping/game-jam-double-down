#pragma once
#include "raylib.h"


class FloatingEntity {
protected:
    Vector2 position = {200, (float)GetScreenHeight()};
    Vector2 size = {50, 50};

    bool goingUp;
public:
    bool toDelete = false;
    float velocity = -5;

    FloatingEntity(bool up, float vel);
    ~FloatingEntity();

    virtual void Update();
    virtual void Draw();
    Vector2 GetPos();
    Vector2 GetSize();
    Rectangle GetCollision();
};


