cmake_minimum_required(VERSION 3.15)
project(RockPaperScissors)

set(CMAKE_CXX_STANDARD 14)

add_executable(RockPaperScissors main.cpp inputValidation.cpp inputValidation.h game.cpp game.h)