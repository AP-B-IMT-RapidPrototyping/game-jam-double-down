#include <catch2/catch_test_macros.hpp>

#include "FloatingEntity.h"
#include "Player.h"
#include "PressureBar.h"

TEST_CASE("sanity check", "[Setup]") {
    Player p = Player();

    REQUIRE_NOTHROW(p.GetHealth());
}

TEST_CASE("Pressurebar", "[PressureBar]") {
    PressureBar pressureBar = PressureBar();
    SECTION("pressure can change") {
        int currentPressure = pressureBar.GetPressure();
        pressureBar.ChangePressure(20);
        int newPressure = pressureBar.GetPressure();
        REQUIRE(newPressure == currentPressure + 20);
    }
    SECTION("pressure can reset") {
        pressureBar.ChangePressure(50);
        pressureBar.ResetPressure();
        REQUIRE(pressureBar.GetPressure() == 0);
    }
}

TEST_CASE("FloatingEntity", "[FloatingEntity]") {
    float velocity = -5;
    FloatingEntity floatingEntity = FloatingEntity(true, velocity);
    SECTION("Can get position") {
        REQUIRE_NOTHROW(floatingEntity.GetPos());
    }
    SECTION("Can get size") {
        REQUIRE_NOTHROW(floatingEntity.GetSize());
    }
    SECTION("Can get collision") {
        REQUIRE_NOTHROW(floatingEntity.GetCollision());
    }
    SECTION("Position gets updated correctly") {
        Vector2 currentPos = floatingEntity.GetPos();
        floatingEntity.Update();
        currentPos.y += velocity;
        REQUIRE(floatingEntity.GetPos().y == currentPos.y);
    }
}