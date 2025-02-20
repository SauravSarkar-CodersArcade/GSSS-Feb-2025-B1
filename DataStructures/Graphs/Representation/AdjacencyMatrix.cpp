#include <iostream>
using namespace std;

int main(){
    // n -> nodes
    // m -> edges
    int n, m;
    cin >> n >> m;
    // We are considering undirected graph
    // It is mandatory to traverse all the nodes
    // Time Complexity O(n)
    int ** adjMatrix = new int * [n+1]; // Also taking 0 - based indexing
    for(int i=0; i<=n; i++){
        // each row i = 0,1,2,3,4 and so on
        // For each row we have to assign memory
        adjMatrix[i] = new int[n+1];
        for(int j=0; j<= n; j++){
            adjMatrix[i][j] = 0; // We are considering by default zeroes
        }
    }
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1; // We can travel from u -> v
        // undirected graph
        adjMatrix[v][u] = 1; // We can travel from v -> u also

    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}