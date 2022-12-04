#include "Graph.h"
#include "Graph.cpp"
using namespace std;
#include <cstdio>
#include <vector>
#include "Graph.h"



int main()
{
    Graph *temp = new Graph();
    temp->buildGraph();
    vector<string> temp89 = temp->shortestPath(temp->getMap(), "Paris", "France");
    for (int i = 0; i < temp89.size(); i++)
    {
        cout<<temp89[i];
    }
    return 1;
}
