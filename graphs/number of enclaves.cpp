TC: border traversal: o(m+n)
  bfs: (m*n)

sc:
o(n*m) vis array

BFS AND DFS:
class Solution {
  public:
    void bfs(vector<vector<int>> &grid, vector<vector<int>> &vis,
        int i, int j){
        
        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> x = {-1, +1, 0, 0};
        vector<int> y = {0, 0, -1, +1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int k = 0; k<4; k++){
                int nrow = row + x[k];
                int ncol = col + y[k];
                
                if(nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol <m &&
                    grid[nrow][ncol] == 1 && vis[nrow][ncol] != 1){
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // top and bottom
        for(int j = 0; j<m; j++){
            if(grid[0][j] == 1){
                bfs(grid, vis, 0, j);
            }
            
            if(grid[n-1][j] == 1){
                bfs(grid, vis, n-1, j);
            }
        }
        
        // left and right columns
        for(int i = 0; i<n; i++){
            if(grid[i][0] == 1){
                bfs(grid, vis, i, 0);
            }
            
            if(grid[i][m-1] == 1){
                bfs(grid, vis, i, m-1);
            }
        }
        
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] != 1){
                    count++;
                }
            }
        }
        
        return count;
    }
};



DFS:

class Solution {
  public:
    void bfs(vector<vector<int>> &grid, vector<vector<int>> &vis,
        int i, int j){
    
        vis[i][j] = 1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> x = {-1, +1, 0, 0};
        vector<int> y = {0, 0, -1, +1};
        
        int row = i;
        int col = j;
        
        for(int k = 0; k<4; k++){
            int nrow = row + x[k];
            int ncol = col + y[k];
            
            if(nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol <m &&
                grid[nrow][ncol] == 1 && vis[nrow][ncol] != 1){
                    vis[nrow][ncol] = 1;
                    bfs(grid, vis, nrow, ncol);
                }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // top and bottom
        for(int j = 0; j<m; j++){
            if(grid[0][j] == 1){
                bfs(grid, vis, 0, j);
            }
            
            if(grid[n-1][j] == 1){
                bfs(grid, vis, n-1, j);
            }
        }
        
        // left and right columns
        for(int i = 0; i<n; i++){
            if(grid[i][0] == 1){
                bfs(grid, vis, i, 0);
            }
            
            if(grid[i][m-1] == 1){
                bfs(grid, vis, i, m-1);
            }
        }
        
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] != 1){
                    count++;
                }
            }
        }
        
        return count;
    }
};

