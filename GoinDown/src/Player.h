//
// Created by ninja on 22/05/2026.
//

#pragma once

#include "raylib.h"


class Player {
private:
    // Graphics
    Texture playerTexture;

    // Player Properties
    Vector2 size = {50, 100}; // THIS SHOULD BE REMOVED WHEN TEXTURE IS AVAILABLE

    Vector2 position = {(float) GetScreenWidth() / 2, (float) GetScreenHeight() / 2};
    float positionYOffset = 150;

    float hitboxOffset = 10; // Make hitbox smaller than player (higher = easier)

    float moveVelocity = 10;

    int maxHealth = 3;
    int health = maxHealth;

public:
    // Beloved constructors
    Player();

    ~Player();


    // Graphics
    void DrawPlayer();

    void DrawHitbox();


    // Collision
    Rectangle GetCollision() const;

    // Input & Handlers
    void HandleMoveInput();

    void Run();


    // Takers
    void TakeDamage(int amount);
};
