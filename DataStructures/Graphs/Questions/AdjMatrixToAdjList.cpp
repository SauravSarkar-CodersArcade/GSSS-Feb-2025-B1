#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> convertToAdjList(int adjMatrix[5][5], int V){
    vector<vector<int>> adjList(V);
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(adjMatrix[i][j] == 1){
                adjList[i].push_back(j);
            }
        }
    }
    return adjList;
}
void printAdjList(vector<vector<int>>& adjList){
    for(int i=0; i< adjList.size(); i++){
        cout << i << ": ";
        for(int j=0; j<adjList[i].size(); j++){ // It may be unequal rows 
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
	int V = 5;
    int adjMatrix[5][5] = {
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };
    vector<vector<int>> adjList = convertToAdjList(adjMatrix, V);
    cout << "Adjacency List Representation: " << endl;
    printAdjList(adjList);
}
