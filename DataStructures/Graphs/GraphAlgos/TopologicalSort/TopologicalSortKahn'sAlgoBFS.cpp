#include <bits/stdc++.h>
using namespace std;
class TopologicalSortBFSKahn {
public:
    vector<int> topoSort(int V, vector<int> adj[]){
        int indegree[V] = {0};
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // Node is now in your topo sort answer (Linear Order)
            // So, remove the indegree of the adjacent neighbours
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return topo;
    }
};
int main() {
	// V = 6
    vector<int> adj[6] = {{},{},{3},{1},{0,1},{0,2}};
    int V = 6;
    TopologicalSortBFSKahn obj;
    vector<int> ans = obj.topoSort(V, adj);
    for(auto node : ans){
        cout << node << " ";
    }cout << endl;
	return 0;
}
