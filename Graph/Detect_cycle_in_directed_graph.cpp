Question link in GFG: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/?track=dsa-workshop-1-graph&batchId=308

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recSt,
                      vector<int> adj[]) {
        //making current vertex as visited
        visited[v]=true;
        recSt[v]=true;
        // traversing adjacents of vertex
        for(int u:adj[v]){
            if(visited[u]==false && isCyclicUtil(u,visited,recSt,adj))
            return true;
            else if(recSt[u]==true)
            return true;
        }
        recSt[v]=false;
        return false;
    }

  public:

    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<bool> visited(V, false);
        vector<bool> recSt(V, false);

        for (int i = 0; i < V; i++)
            if (isCyclicUtil(i, visited, recSt, adj)) return true;

        return false;
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
