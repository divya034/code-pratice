class Solution {
  public:
    // Function to find the number of islands.
    void bfs(vector<vector<int>>& vis, vector<vector<char>> &grid, int i, int j){
        queue<pair<int, int>> q;
        q.push({i,j});
        vis[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            // insert all its neighbours in 8 directions
            q.pop();
            
            for(int x = -1; x <= 1; x++){
                for(int y = -1; y <= 1; y++){
                    if(x == 0 && y == 0) continue;
                    int nrow = row + x;
                    int ncol = col + y;
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                    && vis[nrow][ncol] != 1 && grid[nrow][ncol] == '1'){
                        q.push({nrow,ncol});
                        vis[nrow][ncol] = 1;
                     }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<int>> vis(r, vector<int>(c, 0));
        int count = 0;
        
        for(int i = 0; i<r; i++){
            
            for(int j = 0; j<c; j++){
                
                if(grid[i][j] != '0' && !vis[i][j]){
                    bfs(vis, grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};
