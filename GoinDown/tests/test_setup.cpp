#include <catch2/catch_test_macros.hpp>
#include <catch2/reporters/catch_reporter_event_listener.hpp>
#include <catch2/reporters/catch_reporter_registrars.hpp>
#include "raylib.h"

class RaylibContextListener : public Catch::EventListenerBase {
public:
    using EventListenerBase::EventListenerBase;

    // Wordt één keer aangeroepen voordat de eerste test start
    void testRunStarting(Catch::TestRunInfo const&) override {
        SetTraceLogLevel(LOG_NONE); // Geen spam in de console tijdens tests
        InitWindow(10, 10, "Unit Test Context");
    }

    // Wordt één keer aangeroepen nadat de laatste test klaar is
    void testRunEnded(Catch::TestRunStats const&) override {
        CloseWindow();
    }
};

// Registreer de listener
CATCH_REGISTER_LISTENER(RaylibContextListener)