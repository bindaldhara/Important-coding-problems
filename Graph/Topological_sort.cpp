Question link in GFG: https://practice.geeksforgeeks.org/problems/topological-sort/0/?track=dsa-workshop-1-graph&batchId=308

#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void topo(vector<int> adj[], int u, bool visited[], stack<int> &s) 
 {
     //making the current vertex as visited
        visited[u] = true; 
    
        //traversing  the adjacent vertices.
        for (auto v : adj[u])
        {
            //if  vertex is not visited, we call the function again
            if (visited[v]==false)
                topo(adj, v, visited,s); 
        }
        //pushing the current vertex into the stack.
        s.push(u); 
    }
    
    //Function to return list containing vertices in Topological order. 
    vector <int> topoSort(int N, vector<int> adj[]) 
    {
        bool visited[N + 1];  
        //marking all the nodes as false.              
        memset(visited, 0, sizeof visited); 
        
        stack<int> s;
        
        //traversing over all the vertices.
        for (int i = 0; i < N; i++) 
        {
            //if the current vertex is not visited, we call the topo function.
            if (visited[i]==false)              
                topo(adj, i, visited, s); 
        }
    
        vector <int> res;
        int i = -1;
        while (!s.empty())
        {
            //pushing elements of stack in list and popping them from stack.
            res.push_back (s.top()); 
            s.pop();
        }
        //returning the list.
        return res;
    }
};


 //  V: number of vertices
// res: topological sorted array
 //adj[]: input graph

int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
