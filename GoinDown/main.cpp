#include <iostream>
#include "raylib.h"


#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define FPS 60


int main() {
    std::cout << "Hello, World!" << std::endl;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Goin' Down");
    SetTargetFPS(FPS);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKBLUE);

        // Hey :)

        EndDrawing();
    }

    return 0;
}
