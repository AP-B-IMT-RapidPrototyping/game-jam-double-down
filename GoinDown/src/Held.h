#pragma once
#include "raylib.h"
namespace Game {
    class Held {
    private:
        Vector2 positie;
    public:
        Held();
        Vector2 GetPosition() const;
    };
}