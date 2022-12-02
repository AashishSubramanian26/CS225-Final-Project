//
// Created by vedet on 11/28/2022.
//

#include "Graph.h"


void Graph::buildGraph() {
    map<string, vector<string>> nameInfo;
    map<string, vector<string>> linkInfo;

//CSV Input
    vector<vector<string>> vec;
    //map<string, vector<pair<string, unsigned>>> adjMatrix;

    fstream fin;
    fin.open("C:\\Users\\vedet\\OneDrive\\Desktop\\CS225\\final-project\\CS225-Final-Project\\src\\Python Webscraping\\Dataset.csv", ios::in);

    while(!fin.eof()){
        vector<string> graphNode;
        string line, word;
        getline(fin, line);
        stringstream lineStream (line);
        while(getline(lineStream, word, ',')){
            string finalWord = word;
            std::cout << word<< endl;

            //graphNode.push_back(Trim(word));
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

    for(auto i = adjMatrix.begin(); i != adjMatrix.end(); ++i)
    {
        for (int j = 0; j < (i -> second).size(); j++)
        {

        }
    }
}


map<string, pair<string, unsigned>> shortestPath(map<string, pair<string, unsigned>> adjMatrix, string start) {
    map<string, int> cost; 
    map<string, string> prev; 

    map<string, pair<string, unsigned>> short; 

    for(auto it = adjMatrix.begin(); it != adjMatrix.end(); it++) {
        cost.pair_insert(it->first, -1000000);
        cost.pair_insert(it->first, NULL);
    }
    cost[start] = 0; 

    

}

