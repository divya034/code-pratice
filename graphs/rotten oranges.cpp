wrong:
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    void bfs(vector<vector<int>> ans, int &t, int i, int j){
        
        queue<pair<int,int>> q;
        q.push({i,j});
        int n = ans.size();
        int m = ans[0].size();
        
        vector<int> x = {0, 0, -1, +1};
        vector<int> y = {-1, +1, 0, 0};
        
        while(!q.empty()){
            
            int row = q.front().first;
            int col = q.front().second;
            
            for(int k = 0; k<x.size(); k++){
                int nrow = row + x[k];
                int ncol = col + y[k];
                
                if(nrow >= 0 && nrow < n && 
                    ncol >= 0 && ncol < m && ans[nrow][ncol] != 0 
                    && ans[nrow][ncol] != 2){
                        ans[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                        t++;
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        vector<vector<int>> ans = grid;
        
        int n = grid.size();
        int m = grid[0].size();
        int t = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    bfs(ans, t, i, j);
                }
            }
        }
        
        return t;
    }
};
