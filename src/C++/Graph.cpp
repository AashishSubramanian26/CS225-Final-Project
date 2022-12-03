//
// Created by vedet on 11/28/2022.
//
#include <iostream>
#include <fstream>
#include <sstream>
//#include <>
#include "Graph.h"

using namespace std;

void Graph::buildGraph() {
    map<string, vector<string>> nameInfo;
    map<string, vector<string>> linkInfo;

//CSV Input
    vector<vector<string>> vec;
    //map<string, vector<pair<string, unsigned>>> adjMatrix;

    fstream fin;
    fin.open(R"(C:\Users\vedet\OneDrive\Desktop\CS225\final-project\CS225-Final-Project\src\Python Webscraping\Dataset.csv)", ios::in);

    while(!fin.eof()){
        vector<string> graphNode;
        string line, word;
        getline(fin, line);
        stringstream lineStream (line);
        while(getline(lineStream, word, ',')){
            string finalWord = word;
            std::cout << word<< endl;
            graphNode.push_back(word);
        }
        vec.push_back(graphNode);
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
                    temp.second = (unsigned)stoi(vec[j][4]);
                    adjMatrix[vec[j][1]].push_back(temp);
                }
            }
        }
    }
}

map<string, vector<pair<string, unsigned>>> Graph::getMap()
{
    return adjMatrix;
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
/*
vector<vector<string>> Graph::yens(map<string, vector<pair<string, unsigned>>> adjList, string start, string end, int K)
{
    map<string, vector<pair<string, unsigned>>> temp1 = adjList;
    vector<vector<string>> final;
    vector<vector<string>> temp;

    temp.push_back(shortestPath(adjList, start, end));
    for (unsigned k = 1; k < K; k++)
    {
        for (unsigned i = 0; i < temp[k-1].size()-2; i++)
        {
            string spurNode = temp[k-1][i];
            vector<string> rootPath;
            for (unsigned l = 0; l < i; l++)
            {
                rootPath.push_back(temp[k-1][l]);
            }

            for (unsigned j = 0; j < temp.size(); j++)
            {
                vector<string> rootPath1;
                for (unsigned l = 0; l < i; l++)
                {
                    rootPath1.push_back(temp[j][l]);
                }

                if (rootPath == rootPath1)
                {
                    temp1 = removeEdge(temp1, temp.at(i), temp.at(i+1));
                }
            }

            for (int p = 0; p < rootPath.size(); p++)
            {
                if (rootPath[p] != spurNode)
                {

                }
            }

            vector<string> spurPath = shortestPath(temp, spurNode, end);
            vector<string> totalPath;
            totalPath.insert(totalPath.end(), rootPath.begin(), rootPath.end());
            totalPath.insert(totalPath.end(), spurPath.begin(), spurPath.end());

            int checker = 0;
            for (int i = 0; i < final.size(); i++)
            {
                if (final[i] == totalPath)
                {
                    checker = 1;
                }
            }

            if (checker == 0)
            {
                final.push_back(totalPath);
            }

            temp1 = adjList;
        }

        if (final.empty())
        {
            break;
        }

        finalSorter(final);
        final[k] = temp[0];
        temp.erase(temp.begin());
    }
}

map<string, vector<pair<string, unsigned>>> removeEdge(map<string, vector<pair<string, unsigned>>> temp, string parent, string child)
{
    for (auto i = temp.begin(); i < temp.end(); ++i)
    {
        if ((temp.at(i))->first == (temp.at(parent))->first)
        {
            (temp.at(i))->second = std::numeric_limits<unsigned>::max();
        }
    }
}

vector<vector<string>> finalSorter(vector<vector<string>> temp)
{
    vector<vector<string>> temp89;
    while(!temp.empty())
    {
        unsigned len = temp[0].size();
        unsigned index = 0;
        for (int i = 1; i < temp.size(); i++)
        {
            if (temp[i].size() < len)
            {
                len = temp[i].size();
                index = i;
            }
        }
        temp89.push_back(temp[index]);
        temp.erase(temp.begin()+index);
    }
}
*/