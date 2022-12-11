cmake_minimum_required(VERSION 3.22)
project(CS225_Final_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(CS225_Final_Project
        src/C++/main.cpp
        src/Tests/TestingData.cpp)
