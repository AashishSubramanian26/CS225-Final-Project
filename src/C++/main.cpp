#include "Graph.h"
#include "Graph.cpp"
using namespace std;
#include <cstdio>
#include <vector>
#include "Graph.h"



int main()
{
    Graph temp = Graph();
    temp.buildGraph();
    //vector<string> temp89 = temp.shortestPath(temp.getMap(), "Paris", "France");
    map<string, vector<pair<string, unsigned>>> temp88 = temp.getMap();

    for(auto itr = temp88.begin(); itr!=temp88.end(); ++itr){
        std::cout << "Adj "<< itr->first << endl;
        cout<<itr->second[0].first;
    }
    
    //vector<vector<string>> temp2 = temp.yens(temp.getMap(), "Paris", "France", 500);
    return 1;
}
