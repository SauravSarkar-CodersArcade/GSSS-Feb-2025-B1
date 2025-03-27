#include <bits/stdc++.h>
using namespace std;
class Prims {
public:
    int MinimumSpanningTreeSum(int V, vector<pair<int, int>> adj[]){
        // Min heap to store {edge weight, node}
        priority_queue
        <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0); // Visited Array
        pq.push({0,0}); // Start from 0 with weight 0
        int sum = 0;
        while(!pq.empty()){
            auto [wt, node] = pq.top();
            pq.pop();
            if(vis[node]) continue; // If node is already visited, skip
            vis[node] = 1; // mark node as visited 
            sum += wt; // Add edge weight to MST sum
            // Traverse all the adjacent neighbours of the current node
            for(auto [adjNode, edW] : adj[node]){
                if(!vis[adjNode]){
                    pq.push({edW, adjNode});
                }
            }
        }
        return sum;
    }
};
int main(){
    int V = 5;
    vector<vector<int>> edges = {
        {0,1,2},{0,2,1},{1,2,1},{2,3,2},{3,4,1},{4,2,2}
    }; 
    // Adjacency List 
    vector<pair<int, int>> adj[V];
    for(auto& edge : edges){
    int u = edge[0], v = edge[1], weight = edge[2];
    adj[u].emplace_back(v, weight);
    adj[v].emplace_back(u, weight);
    }
    Prims obj;
    int mstSum = obj.MinimumSpanningTreeSum(V, adj);
    cout << "The minimum sum of all edge weights is: " << mstSum << endl;
    return 0;
}