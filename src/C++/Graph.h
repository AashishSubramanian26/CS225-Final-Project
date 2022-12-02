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

//hello 
using namespace std;

class Graph {
public:
    void buildGraph();
    
    map<string, vector<pair<string, unsigned>>> shortestPath(map<string, vector<pair<string, unsigned>>> adjMatrix1, string start);



private:

    map<string, vector<pair<string, unsigned>>> adjMatrix;
    //pair.second is the distance value
    priority_queue <pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
};

#endif //FINAL_PROJECT_GRAPH_H
