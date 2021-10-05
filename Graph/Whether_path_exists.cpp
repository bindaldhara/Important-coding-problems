GFG Question link:https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1/?track=md-graph&batchId=144#

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        
        vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,-1,0,1};  
    
    // to check whether the cell is within the matrix bounds or not.
    bool isValid(int x, int y, int n, int m){
        return (x >= 0 and x < n and y >=0 and y < m);
    }
  
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        //making  BFS queue 
        queue<pair<int, int>>q;
        
        //traversing all the cells of the matrix.
        for(int i = 0; i < n; i++)
        {
         for(int j = 0; j < m; j++)
         {
             // if the value of the cell in the matrix is 1(source) then push into the queue.
          if(grid[i][j] == 1){
           q.push({i,j});
          }
         }
        }
        
        while(!q.empty())
        {
         int x = q.front().first;
         int y = q.front().second;
         q.pop();
         for(int i = 0; i < 4; i++)
         {
          int n_x = x + dx[i];
          int n_y = y + dy[i];
          
          //checking if cell is within matrix bounds
          if(isValid(n_x, n_y, n, m))
          {
              //if the value of current cell is 2(destination) , we return true.
           if(grid[n_x][n_y] == 2)
            return true;
            
           //if the value of current cell is 3(blank cell) then we replace the value
           //with 1 and push the cell into the queue.
           if(grid[n_x][n_y] == 3){
            grid[n_x][n_y] = 1;
            q.push({n_x, n_y});
           }
          }
         }
        }
        return false;

    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
} 
