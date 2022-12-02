//
// Created by vedet on 11/28/2022.
//

#include "Graph.h"

using namespace std; 

void buildGraph() {
    map<string, vector<string>> nameInfo;
    map<string, vector<string>> linkInfo;
    //map<string, pair<string, unsigned>> adjMatrix;

//CSV Input
    vector<vector<string>> csvInput;

    fstream fin;
    fin.open(filename, ios::in);

    while(!fin.eof()){
        vector<string> graphNode;
        string line, word;
        getline(fin, line);
        stringstream lineStream (line);
        while(getline(lineStream, word, ',')){
            graphNode.push_back(Trim(word));
        }
        csvInput.push_back(graphNode);
    }


    for (int i = 0; i < vec.size(); i++)
    {
        nameInfo[vec[i][1]].push_back(vec[i][3]);
        linkInfo[vec[i][0]].push_back(vec[i][2]);
    }

    for (auto i = nameInfo.begin(); i != nameInfo.end(); ++i)
    {
        for (unsigned j = 0; j < vec.size(); j++)
        {
            if ((i -> first) == vec[j][1])
            {
                if (find((i->second).begin(), (i->second).end(), vec[j][3]) != (i->second).end())
                {
                    pair<string, unsigned> temp;
                    temp.first = vec[j][3];
                    temp.second = (unsigned)vec[j][4];
                    adjMatrix[vec[j][1]] = temp;
                }
            }
        }
    }
}

map<string, pair<string, unsigned>> Graph::shortestPath(map<string, vector<pair<string, unsigned>>> adjMatrix, string start) {
    map<string, int> cost; 
    map<string, string> prev; 

    map<string, vector<pair<string, unsigned>>> short;

    for(auto it = adjMatrix.begin(); it != adjMatrix.end(); it++) {
        pair<string, int> temp(it->first, -10000000); 
        cost.insert(temp); 
        pair<string, int> tmp(it->first, "");
        prev.insert(tmp);
    }
    cost[start] = 0; 

    for(auto it = adjMatrix.begin(); it != adjMatrix.end(); it++) {
        pair<string, int> temp(it->first, );
        pq.push(); 
    }

    while(!pq.empty()) {

    }



}
