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

#include <bits/stdc++.h>

//hello 
using namespace std;

class Graph {
public:
    void buildGraph();
<<<<<<< Updated upstream

    map<string, pair<string, unsigned>> shortestPath(map<string, vector<pair<string, unsigned>>> adjMatrix, string start); 
    map<string, vector<pair<string, unsigned>>> adjMatrix;
    map<string, pair<string, unsigned>> shortestPath(map<string, pair<string, unsigned>> adjMatrix, string start); 
    vector<vector<string>> finalSorter(vector<vector<string>> temp);\
    map<string, vector<pair<string, unsigned>>> removeEdge(map<string, vector<pair<string, unsigned>>> temp, string parent, string child);
    vector<vector<string> yens(map<string, vector<pair<string, unsigned>>> adjList, string start, string end, int K);
=======
    
    vector<string> convertMaptoVector(map<string, vector<pair<string, unsigned> > > adjMatrix1, string start, string end);

    vector<string> shortestPath(map<string, vector< pair<string, unsigned> > > adjMatrix1, string start, string end);
    map<string, vector<pair<string, unsigned> > > getMap();

    vector<vector<string> > finalSorter(vector<vector<string> > temp);

    map<string, vector<pair<string, unsigned> > > removeEdge(map<string, vector<pair<string, unsigned> > > temp, string parent, string child);

    vector<vector<string> > yens(map<string, vector<pair<string, unsigned> > > adjList, string start, string end, int K);
>>>>>>> Stashed changes


private:

<<<<<<< Updated upstream
    priority_queue <pair<string, int>, vector<pair<string, int>>, greater<int>> pq;
    map<string, vector<pair<string, unsigned>>> adjMatrix;
    priority_queue <int, vector<int>, greater<int>> pq;
=======
    map<string, vector<pair<string, unsigned> > > adjMatrix;
    //pair.second is the distance value
    priority_queue <pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
>>>>>>> Stashed changes
};

#endif //FINAL_PROJECT_GRAPH_H
