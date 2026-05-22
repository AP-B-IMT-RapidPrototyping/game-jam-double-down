cmake_minimum_required(VERSION 4.1)


set(CMAKE_CXX_STANDARD 20)


# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_library(srclib
        Held.cpp)


target_include_directories(srclib PUBLIC .)

# Als je klassen Raylib gebruiken (zoals Vector2), link het hier PUBLIC
target_link_libraries(srclib PUBLIC raylib)