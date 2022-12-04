# cmake_minimum_required(VERSION <specify CMake version here>)

#project(CS225_Final_Project)

#set(CMAKE_CXX_STANDARD 14)

#include_directories(src)

#add_executable(CS225_Final_Project
 #       src/main.cpp
  #      )


CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++2a -g -Wall -Wextra -pedantic $(INCLUDES)

exec: bin/exec
tests: bin/tests

bin/exec: ./src/wikipedia.cpp ./src/main.cpp
$(CXX) $(CXXFLAGS) $^ -o $@

bin/tests: ./tests/tests.cpp ./src/wikipedia.cpp
$(CXX) $(CXXFLAGS) $^ -o $@

.DEFAULT_GOAL := tests
.PHONY: clean exec tests

clean:
rm -fr bin/* obj/*