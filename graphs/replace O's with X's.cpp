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
