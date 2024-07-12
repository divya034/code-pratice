class Solution{
    public:
    
    bool isSafe(int px, int py, vector<vector<bool>>& vis, vector<vector<int>>& m, int n){
        // if possible? 1 or 0 in m
        // visisted or not

        if(px < 0 || py < 0 || px >= n || py >= n){
            return false;
        }
        if(m[px][py] == 1 && vis[px][py] == false){
            return true;
        }
        else{
            return false;
        }
        
        // if (px < 0 || py < 0 || px >= n || py >= n || m[px][py] == 0 || vis[px][py]) {
        //     return false;
        // }
        // return true;
        
    }
    void recur(int px, int py, string op, vector<string>& ans, 
        vector<vector<int>>& m, int n, vector<vector<bool>>& vis, vector<string>& dir ){
        // MADE A MISTALE WROTE N instead of n-1
        if(px == n - 1 && py == n - 1){
            ans.push_back(op);
            return;
        }
        
        // MADE A MISTAKE WROTE 1 instead of -1
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        
        for(int i = 0; i<dir.size(); i++){
            // DID NOT TAKE NEWX COORDINATES, used px = px + dx etc
            // because for next value of i, we need to preserve px value like when issafe if false OR when we comeback from recursion
          
            int newx = px + dx[i];
            int newy = py + dy[i];
            
            if(isSafe(newx, newy, vis, m, n)){
                op += dir[i];
                vis[newx][newy] = true;
                
                recur(newx, newy, op, ans, m, n, vis, dir);
                
                op.pop_back();
                vis[newx][newy] = false;
                
            }
        }
 
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<string> dir{"U", "D", "L","R"};

        vector<string> ans;
        int px = 0;
        int py = 0;
        string op = "";
        
        // I forgot THIS CONDITION
        // Set the isSafe conditions at the start
        vis[px][py] = true;
        
        if(m[0][0] == 0){
            return ans;
        }
        
        recur(px, py, op, ans,m, n, vis, dir);
        
        return ans;
        
    }
};
