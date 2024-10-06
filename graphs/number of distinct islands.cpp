TC: O(n*M) for loop in main to check for islands
each cell is visited once
+
Set insert:
nxlxlogk
n---total islands
l---avg size of each islands
logk--k is the number of islands already present at the the time of insertion


SC:
NXM FOR VIS
s X l for set where s is the number of islands and L is the number of cells
n x m for queue

DFS AND BFS BOTH
class Solution {
  public:
    void bfs(set<vector<pair<int, int>>> &s, vector<vector<int>> &grid,
        vector<vector<int>> &vis, int i, int j){
            queue<pair<int, int>> q;
            
            q.push({i, j});
            vis[i][j] = 1;
            int n = grid.size();
            int m = grid[0].size();
            int srcx = i;
            int srcy = j;
            
            vector<int> x = {-1,1,0,0};
            vector<int> y = {0,0, -1, 1};
            
            vector<pair<int,int>> path;
            
            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for(int k = 0; k<4; k++){
                    int nrow = row + x[k];
                    int ncol = col + y[k];
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                        && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 1){
                        
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                        path.push_back({srcx - nrow, srcy - ncol});
                        
                    }
                }
                
            }
            
            s.insert(path);
        }
        
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        set<vector<pair<int, int>>> s;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1)
                    bfs(s, grid, vis, i, j);
            }
        }
        
        return s.size();
    }
};  


DFS
class Solution {
  public:
    void bfs(vector<pair<int, int>> &path, vector<vector<int>> &grid,
        vector<vector<int>> &vis, int i, int j, int x1, int y1){
            // queue<pair<int, int>> q;
            
            // q.push({i, j});
            int n = grid.size();
            int m = grid[0].size();
            
            vis[i][j] = 1;
            vector<int> x = {-1,1,0,0};
            vector<int> y = {0,0, -1, 1};
            
            
            // while(!q.empty()){
            int row = i;
            int col = j;
            
            for(int k = 0; k<4; k++){
                int nrow = row + x[k];
                int ncol = col + y[k];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                    && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 1){
                    
                    // q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                    path.push_back({x1 - nrow, y1 - ncol});
                    bfs(path, grid, vis, nrow, ncol, x1, y1);
                    
                }
            }
            
        }
        
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int, int>>> s;
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int, int>> path;
                    bfs(path, grid, vis, i, j, i, j);
                    s.insert(path);

                }
                    
            }
        }
        
        return s.size();
    }
};
