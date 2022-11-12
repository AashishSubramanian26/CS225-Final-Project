# cmake_minimum_required(VERSION <specify CMake version here>)
project(CS225_Final_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(CS225_Final_Project
        src/main.cpp
        )
