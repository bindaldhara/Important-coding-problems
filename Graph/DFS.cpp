Question link in GFG: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/0/?track=dsa-workshop-1-graph&batchId=308

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:

   void DFSUtil(int i, vector<int> adj[], int V, bool vis[],vector<int> &res) {
        if (vis[i]) return;

        // marking vertex as visited and adding it to final output
        vis[i] = true;
        res.push_back(i);

        // traversing for connected components
        // and if not visited then recursively calling the function
        for (int j : adj[i]) {
            if (!vis[j]) DFSUtil(j, adj, V, vis, res);
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        bool vis[V]; // array to track vertices as visited or not
        memset(vis, false, sizeof(vis)); //initially all vertices are marked as not visited

        vector<int> res;
        for (int i = 0; i < V; i++) {
// if the vertex is not visited then calling the function again
            if (!vis[i]) {
                DFSUtil(i, adj, V, vis, res);
            }
        }
        
        return res;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} 
