//
// Created by vedet on 11/28/2022.
//

#include "TestingData.h"
#include <catch2/catch_test_macros.hpp>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <locale>
#include "Graph.h"

TEST_CASE("Shortest Path 1")
{
    Graph temp89 = Graph();
    temp89.parsing1();
    vector<string> temp87 = temp89.shortestPath(temp89.getMap(), "Paris", "France");
    vector<string> temp88 = {"Paris", "Pop", "Kys", "France"};
    REQUIRE(temp87 == temp88);
    REQUIRE(temp87.size() == temp88.size());
}

TEST_CASE("Shortest Path 2")
{
    Graph temp89 = Graph();
    temp89.parsing1();
    vector<string> temp87 = temp89.shortestPath(temp89.getMap(), "Pop", "Egypt");
    vector<string> temp88 = {"Pop", "Kys", "France", "Egypt"};
    REQUIRE(temp87 == temp88);
    REQUIRE(temp87.size() == temp88.size());
}

TEST_CASE("Shortest Path 3")
{
    Graph temp89 = Graph();
    temp89.parsing2();
    vector<string> temp87 = temp89.shortestPath(temp89.getMap(), "Ladder", "Honey");
    vector<string> temp88 = {"Ladder", "Woodchipper", "Wood", "Whipsaw", "Wedge prism", "Washington Winch",  "Two-man saw", "Tsakat", "Tree spade", "Tree shelter", "Tree planting bar", "Tree planting", "Tree measurement", "Tree caliper", "Tool", "Rope", "Pyramid", "Honey"};
    REQUIRE(temp87 == temp88);
    REQUIRE(temp87.size() == temp88.size());
}

TEST_CASE("Yen's Algo 1")
{
    Graph temp89 = Graph();
    temp89.parsing1();
    vector<vector<string>> temp87 = temp89.yens(temp89.getMap(), "Paris", "Candy", 3);
    vector<vector<string>> temp = {{"Paris", "Pop", "Candy"}, {"Paris", "Tower", "Candy"}};
    REQUIRE(temp.size() == 2);
    REQUIRE(temp[1]. size() == 3);
    REQUIRE(temp[0]. size() == 3);
    REQUIRE(temp == temp87);
}

TEST_CASE("Yen's Algo one path")
{
    Graph temp89 = Graph();
    temp89.parsing1();
    vector<vector<string>> temp87 = temp89.yens(temp89.getMap(), "Paris", "France", 6);
    vector<vector<string>> temp = {{"Paris", "Pop", "Kys", "France"}, {"Paris", "Pop", "Kys", "France"}, {"Paris", "Pop", "Kys", "France"}, {"Paris", "Pop", "Kys", "France"}, {"Paris", "Pop", "Kys", "France"}};
    REQUIRE(temp == temp87);
    REQUIRE(temp.size() == temp87.size());
}
