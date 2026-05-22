cmake_minimum_required(VERSION 4.1)
project(unit_tests)

set(CMAKE_CXX_STANDARD 20)
enable_testing()

include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.4.0 # Of een recentere versie
)

FetchContent_MakeAvailable(Catch2)
# Maak een executable voor de testen
add_executable(unit_tests test_main.cpp
        test_setup.cpp)

# Link Catch2 (Main zorgt voor de int main()) en je eigen code
target_link_libraries(unit_tests PRIVATE Catch2::Catch2WithMain srclib)

# Zorg dat CTest de testen herkent
include(CTest)
include(Catch)
catch_discover_tests(unit_tests)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/../assets"
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets")
