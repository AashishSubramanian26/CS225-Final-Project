#include "Graph.h"
#include "Graph.cpp"
using namespace std;
#include <cstdio>
#include <vector>

int main()
{
    Graph temp = Graph();
    temp.buildGraph();
    vector<string> temp89 = temp.shortestPath(temp.getMap(), "Paris", "Candy");
    map<string, vector<pair<string, unsigned>>> temp88 = temp.getMap();
    /*
    for(auto itr = temp88.begin(); itr!=temp88.end(); ++itr){
        std::cout << "Adj "<< itr->first << endl;
        cout<<itr->second[0].first;
    }
*/
    for (unsigned i = 0; i < temp89.size(); i++)
    {
        cout<<temp89[i] << temp89.size();
    }
    cout<<"\n";
    vector<vector<string>> temp2 = temp.yens(temp.getMap(), "Chimney", "Egypt", 10);
    for (unsigned i = 0; i < temp2.size(); i++)
    {
        for (unsigned j = 0; j < temp2[i].size(); j++)
        {
            cout << temp2.at(i).at(j);
        }
        cout<<"\n";
    }
    return 1;
}
