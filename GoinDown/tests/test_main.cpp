#include <catch2/catch_test_macros.hpp>
#include "Held.h"

TEST_CASE("sanity check", "[Setup]") {
    Game::Held m = Game::Held();

    REQUIRE_NOTHROW(m.GetPosition());
}

TEST_CASE("Held", "[Held][spawnposition][x]") {
    Game::Held _hero = Game::Held();
    SECTION("positie") {
        SECTION("X") {
            SECTION("Groterdan 0") {
                REQUIRE(_hero.GetPosition().x>0);
            }
            SECTION("kleinerdan 800") {
                REQUIRE(_hero.GetPosition().x<800);
            }
        }
    }
}