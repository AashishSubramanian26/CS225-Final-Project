//
// Created by vedet on 11/28/2022.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "Graph.h"

using namespace std;

long stoi1(const char *s)
{
    long i;
    i = 0;
    while(*s >= '0' && *s <= '9')
    {
        i = i * 10 + (*s - '0');
        s++;
    }
    return i;
}

void Graph::buildGraph() {


    vector<vector<string>> vec = parsing2();
    /*
    //Parent Link, Parent Title, Child Link, Child Title, Weights
    */

    for (unsigned j = 0; j < vec.size(); j++)
    {
        pair<string, unsigned> temp;
        temp.first = vec[j][3];
        temp.second = (unsigned)stoi(vec[j][4]);
        adjList[vec[j][1]].push_back(temp);
    }

    adjList = acyclicByBFS(adjList, "Paris");

}

vector<vector<string>> Graph::parsing2()
{
    vector<vector<string> > vec;
    //map<string, vector<pair<string, unsigned>>> adjMatrix;

    ifstream fin("../src/Python Webscraping/Dataset.csv");

    string line;
    int fileCounter = 0;
    while(getline(fin, line)){
        vector<string> graphNode;
        string word;
        stringstream lineStream (line);
        int wordCount = 0;
        while(getline(lineStream, word, ',')){
            string finalWord = word;
            graphNode.push_back(finalWord);
            wordCount++;
        }
        if(fileCounter!=0 ) {
            vec.push_back(graphNode);
        }
        fileCounter++;
    }
    
    
    for (int i = 0; i < (int) vec.size(); i++){
        int x = 0;
        string fifth = vec[i][4];
        int boolCheckCharacter = 0;
        vector<char> alphabet;
        alphabet.push_back('a');
        alphabet.push_back('b');
        alphabet.push_back('c');
        alphabet.push_back('d');
        alphabet.push_back('e');
        alphabet.push_back('f');
        alphabet.push_back('g');
        alphabet.push_back('h');
        alphabet.push_back('i');
        alphabet.push_back('j');
        alphabet.push_back('k');
        alphabet.push_back('l');
        alphabet.push_back('m');
        alphabet.push_back('n');
        alphabet.push_back('o');
        alphabet.push_back('p');
        alphabet.push_back('q');
        alphabet.push_back('r');
        alphabet.push_back('s');
        alphabet.push_back('t');
        alphabet.push_back('u');
        alphabet.push_back('v');
        alphabet.push_back('w');
        alphabet.push_back('x');
        alphabet.push_back('y');
        alphabet.push_back('z');
        alphabet.push_back('.');
        alphabet.push_back('-');
        alphabet.push_back('+');
        alphabet.push_back(',');
        alphabet.push_back(';');
        alphabet.push_back('/');
        alphabet.push_back('\'');
        alphabet.push_back('#');

        for(int j =0 ; j< (int) alphabet.size(); j++){
            if(fifth.find(alphabet[j])<fifth.length()){
                boolCheckCharacter = 1;
            }
        }
        //,'b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
        if(vec.at(i).size()!=5 ){
            vec.erase(vec.begin()+i);
        }
        else if(boolCheckCharacter==1){
            vec.erase(vec.begin()+i);
        }
    }

    for(unsigned i=0; i<vec.size(); i++){
        for(unsigned j =0; j<vec[i].size(); j++){
            std::cout<< vec[i][j]<< " | ";
        }
        cout<<endl;
    }

    return vec;
}

vector<vector<string>> Graph::parsing1()
{
    vector<vector<string>> vec;
    vector<string> temp = {"0", "Paris", "0", "Pop", "5"};
    vector<string> temp3 = {"0", "Pop", "0", "Kys", "5"};
    vector<string> temp1 = {"0", "Kys", "0", "France", "4"};
    vector<string> temp9 = {"0", "France", "0", "Egypt", "6"};
    vector<string> temp2 = {"0", "Egypt", "0", "Pop", "7"};
    vector<string> temp20 = {"0", "Chimney", "0", "Kys", "2"};
    vector<string> temp21 = {"0", "Kys", "0", "Sydney", "4"};
    vector<string> temp22 = {"0", "Paris", "0", "Tower", "1"};
    vector<string> temp23 = {"0", "Pop", "0", "Candy", "3"};
    vector<string> temp24 = {"0", "Cigar", "0", "France", "53"};
    vector<string> temp25 = {"0", "Chimney", "0", "Pop", "12"};
    vector<string> temp26 = {"0", "Sydney", "0", "Candy", "4"};
    vector<string> temp27 = {"0", "Candy", "0", "Sydney", "24"};
    vector<string> temp28 = {"0", "Tower", "0", "Candy", "3"};
    vec.push_back(temp);
    vec.push_back(temp1);
    vec.push_back(temp2);
    vec.push_back(temp3);
    vec.push_back(temp9);
    vec.push_back(temp21);
    vec.push_back(temp22);
    vec.push_back(temp23);
    vec.push_back(temp24);
    vec.push_back(temp25);
    vec.push_back(temp26);
    vec.push_back(temp27);
    vec.push_back(temp28);

    return vec;
}

map<string, vector<pair<string, unsigned>>> Graph::acyclicByBFS(map<string, vector<pair<string, unsigned>>> adjList2, string root) {
    map<string, vector<pair<string, bool >>> visited;
    for(auto it = adjList2.begin(); it != adjList2.end(); it++) {
        for(auto it2 = adjList2[it->first].begin(); it2 != adjList2[it->first].end(); it2++) {
            visited[it->first].push_back(make_pair(it2->first, false));
        }
    }
    queue<pair<string, string>> qu;
    for(unsigned i = 0; i <  adjList2[root].size(); i++) {
        qu.push(make_pair(root, adjList2.at(root).at(i).first));
    }
    for(auto it2 = adjList2[root].begin(); it2 != adjList2[root].end(); it2++) {
        it2->second = true;
    }
    while(!qu.empty()) {
        pair<string, string> edge = qu.back();

        qu.pop();
        if(!qu.empty()) {
        }
        if(getIdx(visited, edge.first, edge.second) != -1 && getIdx(visited, edge.second, edge.first) != -1) {
            adjList2 = removeEdge(adjList2, edge.second, edge.first);
        }

        for(auto it = adjList2[edge.second].begin(); it != adjList2[edge.second].end(); it++) {
            if(it->second != 0) {
                qu.push(make_pair(edge.second, it->first));
            }
        }
        visited[edge.first][getIdx(visited, edge.first, edge.second)].second = true;
    }

    return adjList2;

}

int Graph::getIdx(map<string, vector<pair<string, bool >>> mP, string parent, string child) {
    for(unsigned int i = 0; i < mP[parent].size(); i++) {
        if(mP[parent][i].first == child) {
            return i;
        }
    }
    return -1;
}

int Graph::getIdx2(map<string, vector<pair<string, unsigned >>> mP, string parent, string child) {
    for(unsigned int i = 0; i < mP[parent].size(); i++) {
        if(mP[parent][i].first == child) {
            return i;
        }
    }
    return 0;
}

map<string, vector<pair<string, unsigned> > > Graph::getMap()
{
    return adjList;
}

vector<string> Graph::shortestPath(map<string, vector<pair<string, unsigned>>> adjList1, string start, string end) {

    //Print input adjacency list
    /*
    cout << start << endl;
    cout << end << endl;
    cout<<'\n';
    for(auto it = adjList1.begin(); it != adjList1.end(); it++) {
        cout << it->first<<" ";
        for(unsigned int i = 0; i < (it->second).size(); i++) {
            cout << (it->second)[i].first <<" ";
        }
        cout<<'\n';
    }
    */

    //make sure weight is right. Djikstra's uses a min-heap priority queue
    //string is adj vertex, int is edge weight. Higher weight is shorter path for us
    map<string, int> dist;
    map<string, string> prev;
    //map<string, vector<pair<string, unsigned>>> shrt;

    vector<pair<string, int>> pqf;
    map<string, bool> visited;


    for(auto it = adjList1.begin(); it != adjList1.end(); it++) {
        dist.insert(make_pair(it->first, -10000000));
        prev.insert(make_pair(it->first, ""));
        if(it->first == start) {
            pqf.push_back(make_pair(it->first, 0));
        }
        else {
            pqf.push_back(make_pair(it->first, -10000000));
        }
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

        for(auto it = adjList1[vertex.first].begin(); it != adjList1[vertex.first].end(); it++) {
            if(visited[it->first] == false) {
                if(dist[it->first] < dist[vertex.first] + (int) it->second) {
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
    /*
    for(auto it = prev.begin(); it != prev.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
     */
    vector<string> answer;

    //didn't have to do this line
    string tmpEnd = end;

    while(tmpEnd != start) {
        answer.push_back(tmpEnd);
        tmpEnd = prev[tmpEnd];
    }
    answer.push_back(start);

    reverse(answer.begin(), answer.end());

    return answer;

}

    //No longer needed - Taken care of in the new shortest path method
/*
    vector<string> Graph::convertMaptoVector(map<string, vector<pair<string, unsigned>>> adjMatrix1, string start, string end)
    {
        cout << "Got Here 7" << endl;
        vector<string> result;
        for(auto it = adjMatrix1.begin(); it != adjMatrix1.end(); it++) {
            result.push_back(it->first);
        }
        return result;
    }
*/



    vector<vector<string> > Graph::yens(map<string, vector<pair<string, unsigned> > > adjList, string start, string end, unsigned K)
    {
        map<string, vector<pair<string, unsigned> > > temp1 = adjList;
        vector<vector<string>> final1;
        vector<vector<string>> temp;
        temp.push_back(shortestPath(temp1, start, end));

        for (unsigned k = 1; k < K-1; k++)
        {
            for (unsigned i = 0; i < (temp.at(k-1).size())-2; i++)
            {
                string spurNode = temp.at(k-1).at(i);
                vector<string> rootPath;
                for (unsigned l = 0; l < i; l++)
                {
                    rootPath.push_back((temp[k-1]).at(l));
                }

                for (unsigned j = 0; j < temp.size(); j++)
                {
                    vector<string> rootPath1;
                    for (unsigned l = 0; l < i; l++)
                    {
                        rootPath1.push_back(temp.at(j).at(l));
                    }

                    if (equal(rootPath.begin(), rootPath.end(), rootPath1.begin()))
                    {
                        temp1 = Graph::removeEdge(temp1, temp[j][i], temp[j][i+1]);
                    }
                }


                for (unsigned p = 0; p < rootPath.size(); p++)
                {
                    if (rootPath[p].compare(spurNode) != 0)
                        temp1.erase(rootPath.at(p));
                }

                temp1 = removeConnections(rootPath, temp1);

                vector<string> spurPath = Graph::shortestPath(temp1, spurNode, end);
                /*
                for (unsigned u = 0; u < spurPath.size(); u++)
                {
                    cout<<spurPath[u];
                }
                 */
                vector<string> totalPath;
                totalPath.insert(totalPath.end(), rootPath.begin(), rootPath.end());
                totalPath.insert(totalPath.end(), spurPath.begin(), spurPath.end());
                /*
                for (unsigned u = 0; u < totalPath.size(); u++)
                {
                    cout<<totalPath[u];
                }
*/

                if (find(final1.begin(), final1.end(), totalPath) == final1.end())
                {
                    final1.push_back(totalPath);
                }

                temp1 = adjList;
            }

            if (final1.empty())
            {
                cout<<"here";
                break;
            }

            Graph::finalSorter(final1);
            temp.push_back(final1[0]);
            final1.erase(final1.begin());
        }
        return temp;
    }

    map<string, vector<pair<string, unsigned> > > Graph::removeConnections(vector<string> temp, map<string, vector<pair<string, unsigned> > > temp1)
    {
        for (auto i = temp1.begin(); i != temp1.end(); ++i)
        {
            for (unsigned j = 0; j < i->second.size(); j++)
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
                for (unsigned j = 0; j < (i->second).size(); j++)
                {
                    if (i->second[j].first == child)
                    {
                        i->second[j].second = 0;
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
        unsigned least = temp[0].size();
        for (unsigned i = 0; i < temp.size(); i++)
        {
            if (temp[i].size() < least)
            {
                least = temp[i].size();
                temp1 = temp[i];
                ind = i;
            }
        }

        temp.erase(temp.begin()+ind);
        temp.insert(temp.begin(), temp1);
        return temp;
    }