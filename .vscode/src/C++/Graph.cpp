//
// Created by vedet on 11/28/2022.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "Graph.h"

using namespace std;

void Graph::buildGraph() {
    vector<vector<string> > vec;
    //map<string, vector<pair<string, unsigned>>> adjMatrix;
    /*
    ifstream fin("../src/Python Webscraping/Dataset.csv");

    string line;
    int fileCounter = 0;
    while(getline(fin, line)){
        vector<string> graphNode;
        string word;
        stringstream lineStream (line);

        cout << line ;
        int wordCount = 0;
        /*
        while(getline(lineStream, word, ',')){
            string finalWord;
            if(wordCount==4){
                finalWord = word;
            }My pc passwordm is 1253
            else if(wordCount==0){
                finalWord = word.substr(1, word.size() -2);
                //finalWord = "ht".append(finalWord);
            }
            else {
                finalWord = word.substr(2, word.size()-3);
            }
            graphNode.push_back(finalWord);

            wordCount++;
        }

        if(fileCounter!=0) {
            vec.push_back(graphNode);
        }
        fileCounter++;
    }
    vector<vector<string>>::iterator it1;
    for (it1 = vec.begin(); it1 != vec.end(); ++it1){
        if(it1->size()!=4){
            vec.erase(it1, it1);
        }
    }

    for(int i=0; i<vec.size(); i++){
        for(int j =0; j<vec[i].size(); j++){
            cout<< vec[i][j]<< " | ";
        }
        //cout<< vec[i][4]<< " |||||||||||||||";
        cout<<endl;
    }
    */



    //Parent Link, Parent Title, Child Link, Child Title, Weights
    vector<string> temp = {"0", "Paris", "0", "pop", "5"};
    vector<string> temp3 = {"0", "pop", "0", "Kys", "5"};
    vector<string> temp1 = {"0", "Kys", "0", "France", "4"};
    //vector<string> temp2 = {"0", "Kyr", "0", "France", "7"};
    vec.push_back(temp);
    vec.push_back(temp1);
    //vec.push_back(temp2);
    vec.push_back(temp3);


    for (unsigned j = 0; j < vec.size(); j++)
    {
        pair<string, unsigned> temp;
        temp.first = vec[j][3];
        temp.second = (unsigned)stoi(vec[j][4]);
        adjMatrix[vec[j][1]].push_back(temp);
    }
}

map<string, vector<pair<string, unsigned> > > Graph::getMap()
{
    return adjMatrix;
}

vector<string> Graph::shortestPath(map<string, vector<pair<string, unsigned>>> adjMatrix1, string start, string end) {

    //Print input adjacency list
    cout << start << endl;
    cout << end << endl;
    cout<<'\n';
    for(auto it = adjMatrix1.begin(); it != adjMatrix1.end(); it++) {
        cout << it->first<<" ";
        for(unsigned int i = 0; i < (it->second).size(); i++) {
            cout << (it->second)[i].first <<" ";
        }
        cout<<'\n';
    }

    //make sure weight is right. Djikstra's uses a min-heap priority queue
    //string is adj vertex, int is edge weight. Higher weight is shorter path for us
    map<string, int> dist;
    map<string, string> prev;
    //map<string, vector<pair<string, unsigned>>> shrt;

    vector<pair<string, int>> pqf;
    map<string, bool> visited;


    for(auto it = adjMatrix1.begin(); it != adjMatrix1.end(); it++) {
        dist.insert(make_pair(it->first, -10000000));
        prev.insert(make_pair(it->first, ""));
        pqf.push_back(make_pair(it->first, -10000000));
        visited[it->first] = false;
    }
    dist[start] = 0;

    for(unsigned int i = 0; i < pqf.size(); i++) {
        if(pqf[i].second > pqf[pqf.size() - 1].second) {
            pair<string, int> temp = pqf[i];
            pqf[i] = pqf[pqf.size() - 1];
            pqf[pqf.size() - 1] = temp;
        }
    }

    while(!pqf.empty()) {
        pair<string, int> vertex = pqf.back();
        pqf.pop_back();
        visited[vertex.first] = true;

        for(auto it = adjMatrix1[vertex.first].begin(); it != adjMatrix1[vertex.first].begin(); it++) {
            if(visited[it->first] == false) {
                if(dist[it->first] < dist[vertex.first] + it->second) {
                    dist[it->first] = dist[vertex.first] + it->second;
                    prev[it->first] = vertex.first;
                }
            }
        }

        for(unsigned int i = 0; i < pqf.size(); i++) {
            if(pqf[i].second > pqf[pqf.size() - 1].second) {
                pair<string, int> temp = pqf[i];
                pqf[i] = pqf[pqf.size() - 1];
                pqf[pqf.size() - 1] = temp;
            }
        }
    }

    vector<string> answer;

    //didn't have to do this line
    string tmpEnd = end;

    while(tmpEnd != start) {
        answer.push_back(tmpEnd);
        tmpEnd = prev[tmpEnd];
    }

    reverse(answer.begin(), answer.end());

    cout << "Answer: " << endl;
    for(auto it = answer.begin(); it != answer.end(); it++) {
        cout << *it << endl;
    }

    return answer;

}

    //what if path is not valid? What do we return?

    vector<string> Graph::convertMaptoVector(map<string, vector<pair<string, unsigned>>> adjMatrix1, string start, string end)
    {
        cout << "Got Here 7" << endl;
        vector<string> result;
        for(auto it = adjMatrix1.begin(); it != adjMatrix1.end(); it++) {
            result.push_back(it->first);
        }
        return result;
    }



    vector<vector<string> > Graph::yens(map<string, vector<pair<string, unsigned> > > adjList, string start, string end, int K)
    {
        map<string, vector<pair<string, unsigned> > > temp1 = adjList;
        vector<vector<string> > final;
        vector<vector<string> > temp;

        temp.push_back(shortestPath(temp1, start, end));
        for (unsigned k = 1; k < K; k++)
        {
            for (unsigned i = 0; i < (temp[k-1].size())-2; i++)
            {
                string spurNode = temp[k-1][i];
                vector<string> rootPath;
                for (unsigned l = 0; l <= i; l++)
                {
                    rootPath.push_back((temp.at(k-1)).at(l));
                }

                for (unsigned j = 0; j < temp.size(); j++)
                {
                    vector<string> rootPath1;
                    for (unsigned l = 0; l <= i; l++)
                    {
                        rootPath1.push_back(temp[j][l]);
                    }

                    if (equal(rootPath.begin(), rootPath.end(), rootPath1.begin()))
                    {
                        temp1 = Graph::removeEdge(temp1, temp[j][i], temp[j][i+1]);
                    }
                }

                for (unsigned p = 0; p < rootPath.size(); p++)
                {
                    if (rootPath.at(p).compare(spurNode) != 0)
                        temp1.erase(rootPath.at(p));
                }

                temp1 = removeConnections(rootPath, temp1);

                vector<string> spurPath = Graph::shortestPath(temp1, spurNode, end);
                vector<string> totalPath;
                totalPath.insert(totalPath.end(), rootPath.begin(), rootPath.end());
                totalPath.insert(totalPath.end(), spurPath.begin(), spurPath.end());

                int checker = 0;
                for (unsigned b = 0; b < final.size(); b++)
                {
                    if (equal(final.at(b).begin(), final.at(b).end(), totalPath.begin()))
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
            temp[k] = final[0];
            final.erase(final.begin());
        }

        return temp;
    }

    map<string, vector<pair<string, unsigned> > > Graph::removeConnections(vector<string> temp, map<string, vector<pair<string, unsigned> > > temp1)
    {
        temp.pop_back();
        for (auto i = temp1.begin(); i != temp1.end(); ++i)
        {
            for (int j = 0; j < i->second.size(); j++)
            if (find(temp.begin(), temp.end(), i->second[j].first) != temp.end())
            {
                i->second.erase(i->second.begin()+j);
            }
        }
        return temp1;
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
                        i->second.erase(i->second.begin()+j);
                    }
                }
            }
        }

        return temp;
    }

    vector<vector<string> > Graph::finalSorter(vector<vector<string> > temp)
    {
        vector<string> temp1;
        int ind = 0;
        unsigned max = temp[0].size();
        for (unsigned i = 0; i < temp.size(); i++)
        {
            if (temp[i].size() < max)
            {
                max = temp[i].size();
                temp1 = temp[i];
                ind = i;
            }
        }

        temp.erase(temp.begin()+ind);
        temp.insert(temp.begin(), temp1);
        return temp;
    /*
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
        */
    }