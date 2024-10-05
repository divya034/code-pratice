if o is on the boundary that can never be converted to x
when the o is not on the bounday its neighbours should be X
    -if the neighbor is 0 && notboundary: can convert present ele + neighbor into X (if surrounded by X)--recursion
    -else the neighbor is 0 && boundary: can't convert present ele or neighbor
    -else if nneighbor is X---it is creating a boundary

// or if set of 0s is connected to boundary--->cant be converted to X
// if a set of 0s are not connected to boundary--->can be converted to X
// check the 0s on the boundary, if these zeros are connected to any other 0s, mark them as visited
// traverse through the matrix if ans[I][j] == '0' & visited[I][j] is not true, then ---> ans[I][J] == 'X'


CORRECT:
TC: 
DFS: O(N*M)

SC:
vis array: o(nxm)
queue: o(mxn)
ans: o(mxn)

    
class Solution{
public:
    void dfs(queue<pair<int,int>> &q, 
        vector<vector<char>> &ans, vector<vector<int>> &vis, int i, int j){
            q.push({i, j});
            vis[i][j] = 1;
            
            vector<int> x = {-1, 1, 0, 0};
            vector<int> y = {0, 0, -1, 1};
            int n = ans.size();
            int m = ans[0].size();
            
            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for(int K = 0; K<4; K++){
                    int nrow = row + x[K];
                    int ncol = col + y[K];
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                        && ans[nrow][ncol] == 'O' && vis[nrow][ncol] != 1){
                            vis[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                        }
                }
                
            }
        }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // check from the ans matrix
        queue<pair<int,int>> q;
        vector<vector<char>> ans = mat;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // top
        for(int i = 0; i<m; i++){
            if(mat[0][i] == 'O'){
                dfs(q, ans, vis, 0, i);
            }
        }
        
        for(int i = 0; i<m; i++){
            if(mat[n-1][i] == 'O'){
                dfs(q, ans, vis, n-1, i);
            }
        }
        
        // left
        for(int i = 0; i<n; i++){
            if(mat[i][0] == 'O'){
                dfs(q, ans, vis, i, 0);
            }
        }
        
        for(int i = 0; i<n; i++){
            if(mat[i][m-1] == 'O'){
                dfs(q, ans, vis, i, m-1);
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(ans[i][j] == 'O' && vis[i][j] == 0){
                    ans[i][j] = 'X';
                }
            }
        }
        
        return ans;
    }
};



WRONG:
class Solution{
public:
    bool islast(int i, int j, vector<vector<char>> mat){
        if()
    }
    void bfs(queue<pair<int,int>> q, vector<vector<char>> mat, 
        vector<vector<char>> ans){
        
        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // will be valid as we are only pushing non last elements in queue
            // in main function
                int up = ans[row + x[0]][col + y[0]];
                int down = ans[row + x[1]][col + y[1]];
                int left =  ans[row + x[2]][col + y[2]];
                int right =  ans[row + x[3]][col + y[3]];
                
                
                if(up == 'X' && down =='X' && left == 'X' && right == 'X'
                   && islast(row + x[0], col + y[0], ans) == false 
                   && islast(row + x[1], col + y[1], ans) == false 
                   && islast(row + x[2], col + y[2], ans) == false
                   && islast(row + x[3], col + y[3], ans) == false)){

                    ans[row][col] = 'X';
                    q.push({i,j});
                }
            // }
            
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // check from the ans matrix
        queue<pair<int,int>> q;
        vector<vector<char>> ans;
        
        for(int nrow = 0; nrow<n; nrow++){
            for(int ncol = 0; ncol<m; ncol++){
                if(mat[i][j] == 'O' && ncol != 0 && ncol != m-1 && nrow != 0 
                         && nrow != n-1){
                    // ans[i][j] = 'X';     
                    q.push({nrow,ncol});
                    bfs(q, mat, ans, i, j);
                    
                }
            }
        }
    }
};
