#include "Graph.h"
#include "Graph.cpp"
using namespace std;
#include <cstdio>
#include <vector>

int main() {
    Graph temp = Graph();
    temp.parsing1();
    vector<string> temp89 = temp.shortestPath(temp.getMap(), "Paris", "Candy");
    map<string, vector<pair<string, unsigned>>> temp88 = temp.getMap();
    cout<<"Djikstra's out ->"<<endl;
    for (unsigned i = 0; i < temp89.size(); i++) {
        cout << temp89[i];
    }
    cout << "\n" << "Yen's output ->" << endl;
    vector<vector<string>> temp2 = temp.yens(temp.getMap(), "Paris", "Candy", 5);
    for (unsigned i = 0; i < temp2.size(); i++) {
        for (unsigned j = 0; j < temp2[i].size(); j++) {
            cout << temp2.at(i).at(j);
        }
        cout << "\n";
    }
    return 1;
}
