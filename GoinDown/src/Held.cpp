//
// Created by StevenCharpentier(ad on 29/04/2026.
//

#include "Held.h"
namespace Game {
    Held::Held():positie({10,10}) {

    }

    Vector2 Held::GetPosition() const{
        return positie;
    }
}