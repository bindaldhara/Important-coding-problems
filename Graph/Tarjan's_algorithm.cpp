
#include<bits/stdc++.h>
#include<stack>
#define NODE 5
using namespace std;
int graph[NODE][NODE] = {
   {0,0,1,1,0},                    
   {1,0,0,0,0},                       
   {0,1,0,0,0},                        
   {0,0,0,0,1},
   {0,0,0,0,0}
};

void findComponent(int u, int disc[], int low[], stack<int>&st, bool stackitem[]) {
   static int time = 0;
   disc[u] = low[u] = ++time;    //inilially discovery time and low value is 1
   st.push(u);
   stackitem[u] = true;    //flag as u in the stack
   for(int v = 0; v<NODE; v++) {
      if(graph[u][v]) {
         if(disc[v] == -1) {   //when v is not visited
            findComponent(v, disc, low, st, stackitem);
            low[u] = min(low[u], low[v]);
         } else if(stackitem[v])    //when v is in the stack, update low value for u
            low[u] = min(low[u], disc[v]);
      }
   }
   int poppedItem = 0;
   if(low[u] == disc[u]) {
      while(st.top() != u) {
         poppedItem = st.top();
         cout << poppedItem << " ";
         stackitem[poppedItem] = false;    //mark as item is popped
         st.pop();
      }
      poppedItem = st.top();
      cout << poppedItem <<endl;
      stackitem[poppedItem] = false;
      st.pop();
   }
}
void SCC() {
   int disc[NODE], low[NODE];
   bool stackitem[NODE];
   stack<int> st;
   for(int i = 0; i<NODE; i++) {    //initialize all elements
      disc[i] = low[i] = -1;
      stackitem[i] = false;
   }
   for(int i = 0; i<NODE; i++)    //initialize all elements
      if(disc[i] == -1)
         findComponent(i, disc, low, st, stackitem);
}

int main() {
   SCC();
   return 0;
}
