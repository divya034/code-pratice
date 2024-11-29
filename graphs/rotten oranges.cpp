neetcode:
class Solution {
public:
    int bfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid){
        vis[i][j] = 1;
        int time = 0;

        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {-1,1,0,0};

        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            int size = q.size();
            bool foundFresh = false;
            q.pop();

            // check all 4 direction from each rotten fruit
            for(int s = 0; s < size; s++){
                for(int k = 0; k<4; k++){
                    int new_x = x + dx[k];
                    int new_y = y + dy[k];
                    
                    while(new_x >= 0 && new_x < r &&
                        new_y >= 0 && new_y < c &&
                        grid[new_x][new_y] == 1 && 
                        vis[new_x][new_y] != 1){
                                cout<<new_x<<" "<<new_y<<endl;
                            vis[new_x][new_y] = 1;
                            q.push({new_x, new_y});
                            foundFresh = true;

                    }
                }
            }

            if(foundFresh) time++;
        }

        return time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int c = grid[0].size();
        int r = grid.size();
        vector<vector<int>> vis(r, vector<int>(c, 0));
        int minute = 0;

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j] == 2 && !vis[i][j]){
                    minute = bfs(i, j, vis, grid);
                }
            }
        }

        return minute;
    }
};

// move level wise
// for example level 1:---> 
// rot all the vertical and horizontal fresh fruit(1) from all rotten(2)
// if we found a (1) in any 4 directions from (2), minute++
// Time complexity:
// BFS--> 
// O(V+E)

// Extra Space used:
// queue - o(V)
// vis- grid.size()







Tc: BFS of all nodes worst case
    o(nxm)
    
SC: O(nxm)
    o(nxm)
    queue and ans matrix
    
correct:
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    void bfs(vector<vector<int>> &ans, int &t, queue<pair<pair<int,int>,int>>& q){
        
        int n = ans.size();
        int m = ans[0].size();
        
        vector<int> x = {0, 0, -1, +1};
        vector<int> y = {-1, +1, 0, 0};
        
        while(!q.empty()){
            
            int row = q.front().first.first;
            int col = q.front().first.second;
            int curr_time = q.front().second;
            q.pop();
            
            for(int k = 0; k<x.size(); k++){
                int nrow = row + x[k];
                int ncol = col + y[k];
                
                if(nrow >= 0 && nrow < n && 
                    ncol >= 0 && ncol < m && ans[nrow][ncol] != 0 
                    && ans[nrow][ncol] != 2){
                        ans[nrow][ncol] = 2;
                        q.push({{nrow, ncol}, curr_time + 1});
                        // when going from t = 0 -->1
                        // all elements with t = 
                        // 0 level will make t as 1 only
                        t = max(t, curr_time + 1);  // Update the time
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
       queue<pair<pair<int,int>,int>> q;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},t});
                }
            }
        }
        
        bfs(ans, t, q);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(ans[i][j] == 1) return -1;  // If there's any fresh orange left
            }
        }
    
        
        return t;
    }
};


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
