cmake_minimum_required(VERSION 3.13)
project(rock-paper-scissors-cpp-version)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_PATH /game_logic.h)

#include_directories(rock-paper-scissors-cpp-version game_logic.h)
add_executable(rock-paper-scissors-cpp-version game.cpp)
