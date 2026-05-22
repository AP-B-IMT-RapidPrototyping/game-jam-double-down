#pragma once
#include "raylib.h"


class FloatingEntity {
protected:
    Vector2 position = {200, (float)GetScreenHeight()};
    Vector2 size = {50, 50};
private:
    float velocity = -5;
public:
    bool toDelete = false;

    FloatingEntity();
    ~FloatingEntity();

    void Update();
    virtual void Draw();
    Vector2 GetPos();
    Vector2 GetSize();
    Rectangle GetCollision();
};


