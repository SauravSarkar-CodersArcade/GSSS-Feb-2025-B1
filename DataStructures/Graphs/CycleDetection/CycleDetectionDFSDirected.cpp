#include <bits/stdc++.h>
using namespace std;
class GraphCycleDetectDFSDirected {
private:
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;
        // We traverse the adjacent nodes one by one
        for(auto it : adj[node]){
            // If it is not visited
            if(!vis[it]){
                if(dfsCheck(it, adj, vis, pathVis)){
                    return true;
                }
            }
            // If the node has been previously visited and is in the same path
            // it is path visited also
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
    public:
    bool isCyclic(int V, vector<int> adj[]){
        int vis[V+1] = {0};
        int pathVis[V+1] = {0}; 
        // Check all the nodes of the graph in case of disconnected graph
        for(int i=1; i<=V; i++){
            if(!vis[i]){
                if(dfsCheck(i,adj,vis,pathVis)){
                    return true;
                }
            }
        }return false;
    }
};
int main() {
    int V = 10;
    vector<int> adj[V+1];
    adj[1] = {2};
    adj[2] = {3,8};
    adj[3] = {4,7};
    adj[4] = {5};
    adj[5] = {6};
    adj[6] = {};
    adj[7] = {5};
    adj[8] = {9};
    adj[9] = {10};
    adj[10] = {8};
    GraphCycleDetectDFSDirected obj;
    bool ans = obj.isCyclic(V, adj);
    if(ans){
        cout << "Cycle is detected.\n";
    }else{
        cout << "Cycle is not detected.\n";
    }
}
