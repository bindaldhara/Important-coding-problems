#include <bits/stdc++.h>
using namespace std;
 
void bridgeUtil(int u, bool visited[], int disc[],int low[], int parent[],vector<int>adj[]){
    
    static int time = 0;
    // Marking current node as visited
    visited[u] = true;
 
    // Initializing discovery time and low value
    disc[u] = low[u] = ++time;
 
    // Traverse through all vertices adjacent to this
    for(auto v:adj[u]){  
        // If v is not visited, then again call the function for it
        if (!visited[v]){
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent,adj);

            low[u]  = min(low[u], low[v]);

            if (low[v] > disc[u])
              cout << u <<" " << v << endl;
        }
 
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
 
void bridge(vector<int> adj[], int V){
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];

    for (int i = 0; i < V; i++){
        parent[i] = -1;
        visited[i] = false;
    }

    for (int i = 0; i < V; i++){
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent,adj);
    }
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
  // adj[] --> Adjacency List representation 
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> smallest discovery time reachable from u considering both types of edges.
// parent --> Stores the parent vertex in DFS tree
    cout << "Bridges are: \n";
    int V=5;
    vector<int> g1[V];
    addEdge(g1,1, 0);
    addEdge(g1,0, 2);
    addEdge(g1,2, 1);
    addEdge(g1,0, 3);
    addEdge(g1,3, 4);
    bridge(g1,V);
    return 0;
}
