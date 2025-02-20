#include <iostream>
#include <vector>
using namespace std;

int main(){
    // n -> number of nodes
    // m -> number of edges
    // Undirected Graph
    int n, m;
    cin >> n >> m;
    vector<int> adjList[n+1]; // 0 - based indexing
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        // Undirected graph : u <--> v
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Don't do it for directed

    }
    for(int i = 1; i<= n; i++){
        cout << "Node: " << i << " -> List of neighbours: ";
        for(int v : adjList[i]){
            cout << v << ", ";
        }cout << endl;
    }
    return 0;
}