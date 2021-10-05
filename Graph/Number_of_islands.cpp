GFG Question link:https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1/?track=md-graph&batchId=144#

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    vector<int> dx = {-1, 0, 1, 0, 1, -1, -1, 1};
    vector<int> dy = {0, -1, 0, 1, 1, 1, -1, -1};
 // Below arrays tells all eight possible movements from a cell.
    bool isValid(int x, int y, int n, int m) {
        return (x >= 0 and x < n and y >= 0 and y < m);
    }

   
    int numIslands(vector<vector<char>>& grid) {
      // matrix n*m
        int n = grid.size();
        int m = grid[0].size();

        // boolean array to mark visited cells and initially all are unvisited
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        //  queue for BFS.
        queue<pair<int, int>> q;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // if cell is unvisited and grid value is 1, we increment the
                // count and mark it as visited and then push it in queue.
                if (!vis[i][j] and grid[i][j] == '1') {
                    ans++;
                    vis[i][j] = true;

                    q.push({i, j});
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int k = 0; k < 8; k++) {
                            // if row and column number is in range, grid value
                            // is 1 and cell is not yet visited,
                            if (isValid(x + dx[k], y + dy[k], n, m) and
                                !vis[x + dx[k]][y + dy[k]] and
                                grid[x + dx[k]][y + dy[k]] == '1') {
                                // we push the cell in queue and mark it
                                // visited.
                                q.push({x + dx[k], y + dy[k]});
                                vis[x + dx[k]][y + dy[k]] = true;
                            }
                        }
                    }


}
            }
        }
        return ans;
    }

};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
} 
