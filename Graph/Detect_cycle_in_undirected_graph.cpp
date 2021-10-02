Question link in GFG: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/?track=dsa-workshop-1-graph&batchId=308

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
   
bool isCycleUtil(int u, int par, vector<int> adj[], vector<bool>& visited) {
        //making current vertex as visited
        visited[u] = true;

        // traversing on adjacent edges
        for (int v : adj[u]) {
            if (v == par) continue;

            //if the current vertex is visited thn we return true and 
            //if not visited thn we call the function again
            if (visited[v]) return true;
            if (isCycleUtil(v, u, adj, visited)) return true;
        }
        return false;
    }

    
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool> visited(V, false);

        // iterating over all the vertices.
        for (int i = 0; i < V; i++) {
            // if vertex is not visited, we call the function again
            if (visited[i]==false) {
            if( isCycleUtil(i, -1, adj, visited)==true);
                // if cycle is found, we return true.
             return true;
            }
        }
        return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} 
