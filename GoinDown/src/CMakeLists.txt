cmake_minimum_required(VERSION 4.1)


set(CMAKE_CXX_STANDARD 20)


# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_library(srclib
        Held.cpp
        GameManager.cpp
        GameManager.h
        Held.cpp
        FloatingEntity.cpp
        FloatingEntity.h
        Bubble.cpp
        Bubble.h
        Enemy.cpp
        Enemy.h
        Player.cpp
        Player.h
        Enemy.h
        PressureBar.cpp
        PressureBar.h)


target_include_directories(srclib PUBLIC .)

# Als je klassen Raylib gebruiken (zoals Vector2), link het hier PUBLIC
target_link_libraries(srclib PUBLIC raylib)