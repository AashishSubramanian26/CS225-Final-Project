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
#include <printf.h>

//hello
using namespace std;

class Graph {
public:
    void buildGraph();

    vector<string> shortestPath(map<string, vector<pair<string, unsigned>>> adjMatrix1, string start, string end);

    vector<string> convertMaptoVector(map<string, vector<pair<string, unsigned> > > adjMatrix1, string start, string end);
    map<string, vector<pair<string, unsigned> > > getMap();

    vector<vector<string>> finalSorter(vector<vector<string> > temp);

    map<string, vector<pair<string, unsigned>>> removeEdge(map<string, vector<pair<string, unsigned> > > temp, string parent, string child);

    vector<vector<string> > yens(map<string, vector<pair<string, unsigned> > > adjList, string start, string end, int K);

    map<string, vector<pair<string, unsigned> > > removeConnections(vector<string> temp, map<string, vector<pair<string, unsigned> > > temp1);


private:


    map<string, vector<pair<string, unsigned> > > adjMatrix;
    //pair.second is the distance value
    priority_queue <pair<int, string>> pq;

};

#endif //FINAL_PROJECT_GRAPH_H