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
    float positionYOffset = -250;

    float hitboxOffset = 10; // Make hitbox smaller than player (higher = easier)

    float moveAcceleration = 0.5;
    float deceleration = 0.2;
    float moveMaxSpeed = 5;
    float velocity = 0;

    int maxHealth = 3;
    int health = maxHealth;

public:
    // Beloved constructors
    Player();

    ~Player();


    // Graphics
    void DrawPlayer();

    void DrawHitbox();

    void DrawHealth();

    int GetHealth();


    // Collision
    Rectangle GetCollision() const;

    // Input & Handlers
    void HandleMoveInput();

    void Run();


    // Takers
    void TakeDamage(int amount);

    void ResetHealth();
};
