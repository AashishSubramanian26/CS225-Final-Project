#include "Graph.h"
#include "Graph.cpp"
using namespace std;
#include <cstdio>
#include <vector>

int main() {
    Graph temp = Graph();

    // Choose between parsing 1 and parsing two by commenting and uncommenting the following code
    // Parsing two will go through a mush bigger dataset and will take longer to run, while parsing 2 is shorter and takes less time
    temp.parsing1();
    //temp.parsing2();

    vector<string> temp89 = temp.shortestPath(temp.getMap(), "Paris", "Candy");
    map<string, vector<pair<string, unsigned>>> temp88 = temp.getMap();
    cout<<"Djikstra's out -> ";
    for (unsigned i = 0; i < temp89.size(); i++) {
        cout << temp89[i]<< ", ";
    }
    cout << "\n\n" << "Yen's output -> " << endl;
    vector<vector<string>> temp2 = temp.yens(temp.getMap(), "Paris", "Candy", 5);
    for (unsigned i = 0; i < temp2.size(); i++) {
        for (unsigned j = 0; j < temp2[i].size(); j++) {
            cout << temp2.at(i).at(j) << ", ";
        }
        cout << "\n____________________________________________\n";
    }
    return 1;
}