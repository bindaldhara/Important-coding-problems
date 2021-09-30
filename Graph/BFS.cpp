//Question link in GFG: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1/?track=dsa-workshop-1-graph&batchId=308

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
   
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<bool> vis(V, false);
        int s = 0;

        vis[s] = true; //marking first vertex as visited and then pushing it in queue
        vector<int> res;

        queue<int> q; 
        q.push(s);

        while (!q.empty()) {
            
            int t = q.front();
            res.push_back(t);
            q.pop();
  // for every connected components of front element in queue 
            for (int v : adj[t]) { 
                // if not visited then pushing in queue and marking as visited
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    
        return res; // returning the final output
    }
};

    int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
