GFG Question Link: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1/?track=dsa-workshop-1-graph&batchId=308

#include<bits/stdc++.h>
using namespace std;

class Solution{
 public:

 void transpose(int V, vector<int> adj[], vector<int> transpose_adj[])
 {
        for (int u = 0; u < V; u++)
            for (auto v : adj[u])
                transpose_adj[v].push_back(u);
    }
    
    stack<int> s;
    void dfs(vector<int> adj[], bool *visited, int u)
    {
        //making the current node as visited.
        visited[u] = true;
        
        //iterating over adjacent vertices 
        //if any adjacent vertex is not visited then calling function recursively .
        for (auto v : adj[u])
        {
            if (visited[v] == 0)
                dfs(adj, visited, v);
        }
    }
    
    void fillorder(vector<int> adj[], bool *visited, int u)
    {
        //making the current node as visited.
        visited[u] = true;
        //iterating over adjacent vertices 
        //if any adjacent vertex is not visited then calling function recursively .
       
        for (auto v : adj[u])
            if (visited[v] == 0)
                fillorder(adj, visited, v);
        
        //pushing vertex into the stack.
        s.push(u);
    }
    

    int kosaraju(int V, vector<int> adj[])
    {
        //using boolean list to mark visited nodes and currently
        //marking all the nodes as false.
        bool visited[V];
        memset(visited, 0, sizeof(visited));
        
        //filling vertices in stack according to their finishing times.
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                fillorder(adj, visited, i);
        
        //creating transpose of adjacency list.
        vector<int> transpose_adj[V];
        transpose(V, adj, transpose_adj);
    
        //marking all the nodes as not visited again.
        for (int i = 0; i < V; i++)
            visited[i] = false;
    
        int ans = 0;
        
        //now processing all vertices in order defined by stack.
        while (!s.empty())
        {
            //popping a vertex from stack.
            int temp = s.top();
            s.pop();

//if vertex is not visited, we call dfs function
            //and increment the counter.
            if (!visited[temp]) {
                dfs(transpose_adj, visited, temp);
                ans++;
            }
        }
       
        return ans;
    }
};


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
