//
// Created by ninja on 22/05/2026.
//

#include "Player.h"


// Constructors
Player::Player() {
    //Image playerImg = LoadImage("../assets/Player.png");
    //playerTexture = LoadTextureFromImage(playerImg);
    //UnloadImage(playerImg);
}

Player::~Player() {
    //UnloadTexture(playerTexture);
}


// Graphics
void Player::DrawPlayer() {
    //DrawTexture(playerTexture, position.x, position.y + positionYOffset, WHITE);
}

void Player::DrawHitbox() {
    // plz use texture.width and height instead of size.x and .y
    DrawRectangle(position.x, position.y + positionYOffset, size.x, size.y, GOLD);
}


// Collision
Rectangle Player::GetCollision() const {
    // plz use texture.width and height instead of size.x and .y
    return Rectangle(position.x, position.y, size.x, size.y);
}


// Input
void Player::HandleMoveInput() {
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_Q)) {
        velocity += -moveAcceleration;
    }

    // plz use texture.width instead of size.x
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        velocity += moveAcceleration;
    }

    if (position.x < 0) {
        position.x = 0;
        velocity = 0;
    }
    if (position.x + size.x > (float) GetScreenWidth()) {
        position.x = (float) GetScreenWidth() - size.x;
        velocity = 0;
    }

    if (velocity > 0) {
        velocity -= deceleration;
    }
    if (velocity < 0) {
        velocity += deceleration;
    }

    position.x += velocity;
}

void Player::Run() {
    // Collision
    DrawHitbox();


    // Update
    HandleMoveInput();
}


// Takers?
void Player::TakeDamage(int amount) {
    health -= amount;
}
