#pragma once
#include "raylib.h"


class FloatingEntity {
protected:
    Vector2 position = {200, (float)GetScreenHeight()};
private:
    Vector2 size = {50, 50};
    float velocity = -5;
    bool toDelete = false;
public:
    FloatingEntity();
    ~FloatingEntity();

    void Update();
    virtual void Draw();
    Vector2 GetPos();
    Rectangle GetCollision();
};


