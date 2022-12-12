#include "Graph.h"
#include "Graph.cpp"
using namespace std;
#include <cstdio>
#include <vector>

int main()
{
    Graph temp = Graph();
    temp.parsing2();

    vector<string> temp89 = temp.shortestPath(temp.getMap(), "Ladder", "Honey");
    map<string, vector<pair<string, unsigned>>> temp88 = temp.getMap();
    vector<vector<string>> temp2 = temp.yens(temp.getMap(), "Ladder", "Honey", 10);

    return 1;
}
