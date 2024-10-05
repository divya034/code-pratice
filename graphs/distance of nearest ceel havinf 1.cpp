quueue initialisation and BFS = O(n * m) + O(n * m) 
space complexity: queue o(m*n)
  ans array o(n*m)




class Solution {
  public:
    
    void bfs(vector<vector<int>> &grid, vector<vector<int>> &ans, queue<pair<pair<int,int>,int>> q){
        // d, u,r,l
        vector<int> x = {+1, -1, 0, 0};
        vector<int> y = {0, 0, +1, -1};
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
        
            for(int k = 0; k < x.size(); k++){
                int nrow = row + x[k];
                int ncol = col + y[k];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && 
                    ncol < m && ans[nrow][ncol] > dist + 1 &&
                        grid[nrow][ncol] == 0){
                            
                     ans[nrow][ncol] = dist + 1;
                     q.push({{nrow,ncol}, dist + 1});
                }
            }
        }
        
    }
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                     q.push({{i,j}, 0});
                     ans[i][j] = 0;
                }

            }
        }
        
        bfs(grid, ans, q);
        
        return ans;
    }
};
