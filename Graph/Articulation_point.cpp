//Articulation points ie cut vertices which on removing disconnects the graph.

#include <bits/stdc++.h>
using namespace std;
 
// adj[] --> Adjacency List representation 
// u --> The vertex to be visited next
// parent --> Stores the parent vertex in DFS tree
// AP[] --> Stores articulation points
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> smallest discovery time reachable from u considering both types of edges.

void APUtil(vector<int> adj[], int u, bool visited[], int disc[], int low[], int& time, int parent, bool AP[]){
    // Count of children 
    int children = 0;
 
    // Marking the current node as visited
    visited[u] = true;
 
    // Initializing discovery time and low value
    disc[u] = low[u] = ++time;
 
    // traverse thorugh all vertices adjacent to this
    for (auto v : adj[u]) {
        // If v is not visited  then make it a child of u
        //  and again call the function for it
        if (!visited[v]) {
            children++;
            APUtil(adj, v, visited, disc, low, time, u, AP);
 
            low[u] = min(low[u], low[v]);
 
            if (parent != -1 && low[v] >= disc[u])
                AP[u] = true;
        }
 
        else if (v != parent)
            low[u] = min(low[u], disc[v]);
    }
 
    // If u is root of DFS tree and has two or more children.
    if (parent == -1 && children > 1)
        AP[u] = true;
}
 
void AP(vector<int> adj[], int V)
{
    int disc[V] = { 0 };
    int low[V];
    bool visited[V] = { false };
    bool AP[V] = { false };
    int time = 0, par = -1;
 
    for (int u = 0; u < V; u++)
        if (!visited[u])
            APUtil(adj, u, visited, disc, low, time, par, AP);
 
    for (int u = 0; u < V; u++)
        if (AP[u] == true)
            cout << u << " ";
}
 
//  function to add an edge
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
int main()
{
    // Create graphs given in above diagrams
    cout << "Articulation points : \n";
    int V = 5;
    vector<int> adj1[V];
    addEdge(adj1, 1, 0);
    addEdge(adj1, 0, 2);
    addEdge(adj1, 2, 1);
    addEdge(adj1, 0, 3);
    addEdge(adj1, 3, 4);
    AP(adj1, V);
    return 0;
}
