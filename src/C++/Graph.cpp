//
// Created by vedet on 11/28/2022.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include "Graph.h"

using namespace std;

void Graph::buildGraph() {
    map<string, vector<string>> nameInfo;
    map<string, vector<string>> linkInfo;

//CSV Input
    vector<vector<string> > vec;
    //map<string, vector<pair<string, unsigned>>> adjMatrix;

    ifstream fin("../src/Python Webscraping/Dataset.csv");

    string line;
    int fileCounter = 0;
    while(getline(fin, line)){
        vector<string> graphNode;
        string word;
        stringstream lineStream (line);
        while(getline(lineStream, word, ',')){
            string finalWord;
            if(wordCount==4){
                finalWord = word;
            }
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
    /*
    for(int i=0; i<vec.size(); i++){
        for(int j =0; j<vec[i].size(); j++){
            cout<< vec[i][j]<< " | ";
        }
        cout<<endl;
    }
*/
    /*
    string temp = file_to_string("(C:\\Users\\vedet\\OneDrive\\Desktop\\CS225\\final-project\\CS225-Final-Project\\src\\CSV\\smallTest.csv)");
    vector<string> temp1;
    vector<vector<string>> temp3;
    int h1 = SplitString(temp, '\n', temp1);

    for (unsigned i = 0; i<temp1.size(); i++)
    {
        vector<string> temp2;
        int j = SplitString(temp1[i], ',', temp2);
        temp3.push_back(temp2);
    }

    for (unsigned i = 0; i<temp3.size(); i++)
    {
        for (unsigned o = 0; o<temp3[i].size(); o++)
        {

            temp3[i][o] = Trim(temp3[i][o]);
        }
    }
    for(int i=0; i< temp3.size(); i++){
        for(int j=0; j< temp3[i].size(); j++){
            std::cout<< temp3[i][j]<< " ";
        }
        std::cout<< endl;
    }

    cout<<"hi";
     */
    /*
    vector<string> temp = {"0", "Paris", "0", "France", "9"};
    vector<string> temp1 = {"0", "France", "0", "Paris", "8"};
    vector<string> temp2 = {"0", "Madrid", "0", "France", "5"};
    vector<string> temp3 = {"0", "Paris", "0", "Madrid", "5"};
    */

    //vec.push_back(temp);
    //vec.push_back(temp1);
    //vec.push_back(temp2);
    //vec.push_back(temp3);

    /*
    for (unsigned j = 0; j < vec.size(); j++)
    {
        pair<string, unsigned> temp;
        temp.first = vec[j][3];
        cout<<"hi";
        temp.second = (unsigned)stoi(vec[j][4]);
        adjMatrix[vec[j][1]].push_back(temp);
    }
    */
}

map<string, vector<pair<string, unsigned>>> Graph::getMap()
{
    return adjMatrix;
}

vector<string> Graph::shortestPath(map<string, vector<pair<string, unsigned>>> adjMatrix1, string start, string end) {

    //make sure weight is right. Djikstra's uses a min-heap priority queue
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



vector<vector<string>> Graph::yens(map<string, vector<pair<string, unsigned>>> adjList, string start, string end, int K)
{
    map<string, vector<pair<string, unsigned>>> temp1 = adjList;
    vector<vector<string> > final;
    vector<vector<string> > temp;

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
                    temp1 = removeEdge(temp1, temp[j][i], temp[j][i+1]);
                }
            }

            for (int p = 0; p < rootPath.size(); p++)
            {
                if (rootPath[p] != spurNode)
                {

                }
            }

            vector<string> spurPath = shortestPath(temp1, spurNode, end);
            vector<string> totalPath;
            totalPath.insert(totalPath.end(), rootPath.begin(), rootPath.end());
            totalPath.insert(totalPath.end(), spurPath.begin(), spurPath.end());

            int checker = 0;
            for (unsigned i = 0; i < final.size(); i++)
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

    return final;
}

map<string, vector<pair<string, unsigned>>> Graph::removeEdge(map<string, vector<pair<string, unsigned>>> temp, string parent, string child)
{
    for (auto i = temp.begin(); i != temp.end(); ++i)
    {
        if ((i->first) == parent)
        {
            for (int j = 0; j < (i->second).size(); j++)
            {
                if (i->second[j].first == child)
                {
                    i->second[j].second = 2764472318;
                }
            }
        }
    }

    return temp;
}

vector<vector<string>> Graph::finalSorter(vector<vector<string>> temp)
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
    return temp89;
}

std::string Graph::file_to_string(const string &filename) {
    std::ifstream text(filename);

    std::stringstream strStream;
    if (text.is_open()) {
        strStream << text.rdbuf();
    }
    return strStream.str();
}

int Graph::SplitString(const string &str1, char sep, vector<std::string> &fields) {
    std::string str = str1;
    std::string::size_type pos;
    while((pos=str.find(sep)) != std::string::npos) {
        fields.push_back(str.substr(0,pos));
        str.erase(0,pos+1);
    }
    fields.push_back(str);
    return fields.size();
}

std::string Graph::TrimRight(const string &str) {
    std::string tmp = str;
    return tmp.erase(tmp.find_last_not_of(" ") + 1);
}

std::string Graph::TrimLeft(const string &str) {
    std::string tmp = str;
    return tmp.erase(0, tmp.find_first_not_of(" "));
}

std::string Graph::Trim(const string &str) {
    std::string tmp = str;
    return TrimLeft(TrimRight(str));
}
