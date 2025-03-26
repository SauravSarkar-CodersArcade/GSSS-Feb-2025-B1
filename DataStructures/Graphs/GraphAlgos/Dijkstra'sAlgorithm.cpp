#include <bits/stdc++.h>
using namespace std;
class DijkstraPQ {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int, int>>> &adj, int S){
        // Min Heap -> Priority Queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;
        // Initialise the diatance array to infinite values
        // To suggest that the nodes are unreachable
        vector<int> distTo(V, INT_MAX);
        // Make the diatance to the source node = 0
        // Because src -> src can be reached at 0 distance
        distTo[S] = 0;
        pq.push({0,S});
        // Pop the miniumum element from the min-heap
        // Traverse to all the adjacent nodes 
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop(); // Remove the node from the priority queue
            // Traverse to all it's adjacent nodes
            // Check whether the previous distance is greater than the 
            // current distance
            for(auto it : adj[node]){
                int v = it.first;
                int w = it.second;
                if(dis + w < distTo[v]){
                    distTo[v] = dis + w; // Relaxation -> Abdul Bari
                    // If the current distance is smaller
                    // push the node & the distance into the priority queue
                    pq.push({dis + w, v});
                }
            }
        } 
        // Return the distance array which has the shortest distance
        // from the source node to all other nodes in the graph
        return distTo;
    }
};
int main() {
	int V = 6, S = 0;
    vector<vector<pair<int,int>>> adj(V);
    // Add all the edges of the graph serially node by node
    adj[0].push_back({1,4});
    adj[0].push_back({2,4});
    adj[1].push_back({0,4});
    adj[1].push_back({2,2});
    adj[2].push_back({0,4});
    adj[2].push_back({1,2});
    adj[2].push_back({3,3});
    adj[2].push_back({4,1});
    adj[2].push_back({5,6});
    adj[3].push_back({2,3});
    adj[3].push_back({5,2});
    adj[4].push_back({2,1});
    adj[4].push_back({5,3});
    adj[5].push_back({2,6});
    adj[5].push_back({3,2});
    adj[5].push_back({4,3});
    DijkstraPQ obj;
    vector<int> result = obj.dijkstra(V, adj, S);
    for(int i=0; i<V; i++){
        cout << result[i] << " ";
    }cout << endl;
	return 0;
}
