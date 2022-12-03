//
// Created by vedet on 11/28/2022.
//

#include "Graph.h"

using namespace std; 

void Graph::buildGraph() {
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

vector<string> Graph::shortestPath(map<string, vector<pair<string, unsigned>>> adjMatrix1, string start, string end) {
    map<string, int> dist; 
    map<string, string> prev; 
    map<string, vector<pair<string, unsigned>>> shrt; 

    for(auto it = adjMatrix1.begin(); it != adjMatrix1.end(); it++) {
        pair<string, int> temp(it->first, -10000000); 
        dist.insert(temp); 
        prev.insert(make_pair(it->first, ""));
    }
    dist[start] = 0; 

    //for(auto it = adjMatrix1.begin(); it != adjMatrix1.end(); it++) {
        pair<int, string> temp(0, start);;
        pq.push(temp); 
    //}

    bool valid; 
    while(!pq.empty()) {
        string vertex = pq.top().second; 
        int disty = pq.top().first; 
        pq.pop();

        string adj = ""; 
        int weight = 0;
        for(auto it = adjMatrix1[vertex].begin(); it != adjMatrix1[vertex].end(); it++) {
            string adj1 = it->first; 
            int weight1 = it->second; 

            if(weight1 > weight) {
                weight = weight1; 
                adj = adj1; 
            }

            if(dist[adj1] > dist[vertex] + weight1) {
                dist[adj1] = dist[vertex] + weight1;
                pq.push(make_pair(dist.at(adj), adj)); 
            }
        }
        vector<pair<string, unsigned>> tmp; 
        tmp.push_back(make_pair(adj, weight));
        shrt.insert(make_pair(vertex, tmp)); 

        if(vertex == end) {
            valid = true; 
        }

    }

    //what if path is not valid? What do we return?
    return convertMaptoVector(shrt, start, end); 
    
}

vector<string> Graph::convertMaptoVector(map<string, vector<pair<string, unsigned>>> adjMatrix1, string start, string end) {
    string vertex = start; 
    vector<string> result; 
    result.push_back(start); 
    while(vertex != end) {
        vertex = adjMatrix1[vertex].at(0).first; 
        result.push_back(vertex); 
    }
    return result; 
}
