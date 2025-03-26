#include <bits/stdc++.h>
using namespace std;
class GraphCycleDetectDFSUndirected{
private:
    bool dfs(int node, int parent, int vis[], vector<int> adjList[]){
        vis[node] = 1;
        // Visit the adjacent nodes one by one
        for(auto adjacentNode : adjList[node]){
            // If the adjacent node is unvisited, it is visited
            if(!vis[adjacentNode]){
                if(dfs(adjacentNode, node, vis, adjList)){
                    return true;
                }
            }
            // visited node, but it is not the parent node
            // it means that it was visited earlier in that path
            else if(adjacentNode != parent){
                return true;
            } 
        }
        return false;
    }
    public:
    bool detectCycle(int V, vector<int> adjList[]){
        int vis[V+1] = {0}; // Zero based indexing
        for(int i=1; i<=V; i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adjList)){
                    return true;
                }
            }
        }
        return false;
    }
};
int main() {
	int V = 7;
    vector<int> adjList[V+1];
    adjList[1] = {2,3};
    adjList[2] = {1,5};
    adjList[3] = {1,4,6};
    adjList[4] = {3};
    adjList[5] = {2,7};
    adjList[6] = {3,7};
    adjList[7] = {5,6};
    GraphCycleDetectDFSUndirected obj;
    bool ans = obj.detectCycle(V, adjList);
    if(ans){
        cout << "Cycle is detected.\n";
    }else{
        cout << "Cycle is not detected.\n";
    }
    return 0;
}
