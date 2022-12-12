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


/*
TEST_CASE("Parsing")
{

}
 */

TEST_CASE("Shortest Path")
{
    Graph temp89 = Graph();
    temp89.buildGraph();
    vector<string> temp87 = temp89.shortestPath(temp89.getMap(), "Paris", "France");
    vector<string> temp88 = {"Paris", "Pop", "Kys", "France"};
    REQUIRE(temp87 == temp88);
    REQUIRE(temp87.size() == temp88.size());
}

/*
TEST_CASE("No Path")
{
    Graph temp89 = Graph();
    temp89.buildGraph();
    vector<string> temp88 = temp89.shortestPath(temp89.getMap(), "Chimney", "France");
    REQUIRE(temp88.size() == 2);
}
 */

TEST_CASE("Yen's Algo 1")
{
    Graph temp89 = Graph();
    temp89.buildGraph();
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
    temp89.buildGraph();
    vector<vector<string>> temp87 = temp89.yens(temp89.getMap(), "Paris", "France", 6);
    vector<vector<string>> temp = {{"Paris", "Pop", "Kys", "France"}, {"Paris", "Pop", "Kys", "France"}, {"Paris", "Pop", "Kys", "France"}, {"Paris", "Pop", "Kys", "France"}, {"Paris", "Pop", "Kys", "France"}};
    REQUIRE(temp == temp87);
    REQUIRE(temp.size() == temp87.size());
}

