//
// Created by vedet on 11/28/2022.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.h"

using namespace std;

void Graph::buildGraph() {
    map<string, vector<string>> nameInfo;
    map<string, vector<string>> linkInfo;

//CSV Input
    vector<vector<string> > vec;
    //map<string, vector<pair<string, unsigned>>> adjMatrix;

    /*
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
    */
    //Parent Link, Parent Title, Child Link, Child Title, Weights
    vector<string> temp = {"0", "Paris", "0", "pop", "5"}; /// Hi mr Aditya
    vector<string> temp3 = {"0", "pop", "0", "Kys", "5"};/// Hi mr Aditya
    vector<string> temp1 = {"0", "Kys", "0", "France", "4"};
    //vector<string> temp2 = {"0", "Kyr", "0", "France", "7"};/// Hi mr Aditya
    vec.push_back(temp); /// Hi mr Aditya
    vec.push_back(temp1);/// Hi mr Aditya
    //vec.push_back(temp2);/// Hi mr Aditya
    vec.push_back(temp3);/// Hi mr Aditya

/// Hi mr Aditya
    for (unsigned j = 0; j < vec.size(); j++)
    {
        pair<string, unsigned> temp;/// Hi mr Aditya
        temp.first = vec[j][3];/// Hi mr Aditya/// Hi mr Aditya
        temp.second = (unsigned)stoi(vec[j][4]);/// Hi mr Aditya
        adjMatrix[vec[j][1]].push_back(temp);
    }
}

map<string, vector<pair<string, unsigned> > > Graph::getMap()
{
    return adjMatrix;
}

vector<string> Graph::shortestPath(map<string, vector<pair<string, unsigned> > > adjMatrix1, string start, string end) {
    map<string, int> dist;
    map<string, string> prev;
    map<string, vector<pair<string, unsigned> > > shrt;

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
        vector<pair<string, unsigned> > tmp;
        tmp.push_back(make_pair(adj, weight));
        shrt.insert(make_pair(vertex, tmp));

        if(vertex == end) {
            valid = true;/// Hi mr Aditya
        }

/// Hi mr Aditya/// Hi mr Aditya
    }

    //what if path is not valid? What do we return?

vector<string> Graph::convertMaptoVector(map<string, vector<pair<string, unsigned>>> adjMatrix1, string start, string end)
{
    string vertex = start;
    vector<string> result;
    //result.push_back(start);
    //result.push_back(((adjMatrix1.at(vertex)).at(0)).first);
    //vertex = ((adjMatrix1.at(vertex)).at(0)).first;
    //result.push_back(((adjMatrix1.at(vertex)).at(0)).first);
    //result.push_back(end);

    std::cout<< "Length of Map " << adjMatrix1.size() << endl;

    for(auto itr = adjMatrix1.begin(); itr!=adjMatrix1.end(); ++itr){
        std::cout << "Adj "<< itr->first << endl;
    }

    /*
    while(vertex!= end) {
        //vector<string> child = adjMatrix1[vertex];
        vertex = (adjMatrix1[vertex].at(0)).first;
        result.push_back(vertex);
    }
     */
    return result;
}



vector<vector<string> > Graph::yens(map<string, vector<pair<string, unsigned> > > adjList, string start, string end, int K)
{
    map<string, vector<pair<string, unsigned> > > temp1 = adjList;
    vector<vector<string> > final;
    vector<vector<string> > temp;
    
    temp.push_back(shortestPath(adjList, start, end));
    for (unsigned k = 1; k < K; k++)
    {
        cout<<"hi";
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

                if (equal(rootPath.begin(), rootPath.end(), rootPath1.begin()))
                {
                    temp1 = Graph::removeEdge(temp1, temp[j][i], temp[j][i+1]);
                }
            }

            for (int p = 0; p < rootPath.size()-1; p++)
            {
                temp1.erase(rootPath[i]);
            }

            vector<string> spurPath = Graph::shortestPath(temp1, spurNode, end);
            vector<string> totalPath;
            totalPath.insert(totalPath.end(), rootPath.begin(), rootPath.end());
            totalPath.insert(totalPath.end(), spurPath.begin(), spurPath.end());

            int checker = 0;
            for (unsigned i = 0; i < final.size(); i++)
            {
                if (equal(final[i].begin(), final[i].end(), totalPath.begin()))
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

        Graph::finalSorter(final);
        final[k] = temp[0];
        temp.erase(temp.begin());
    }

    return final;
}

map<string, vector<pair<string, unsigned> > > Graph::removeEdge(map<string, vector<pair<string, unsigned> > > temp, string parent, string child)
{
    for (auto i = temp.begin(); i != temp.end(); ++i)
    {
        if ((i->first) == parent)
        {   
            for (int j = 0; j < (i->second).size(); j++)
            {
                if (i->second[j].first == child)
                {
                    i->second[j].second = 99;
                }
            }
        }
    }

    return temp;
}

vector<vector<string> > Graph::finalSorter(vector<vector<string> > temp)
{
    vector<vector<string> > temp89;
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

    return temp89;
  }
