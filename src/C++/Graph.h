//
// Created by vedet on 11/28/2022.
//

#ifndef FINAL_PROJECT_GRAPH_H
#define FINAL_PROJECT_GRAPH_H

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    void buildGraph();

private:
    priority_queue <int, vector<int>, greater<int>> pq;
    map<string, pair<string, unsigned>> adjMatrix;
};

#endif //FINAL_PROJECT_GRAPH_H
