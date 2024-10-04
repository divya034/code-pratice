class Solution {
  public:
  
   void dfs(int initial, vector<vector<int>>& ans, 
        int row,int col, int newColor){
            int n = ans.size();
            int m = ans[0].size();
            ans[row][col] = newColor;
            vector<int> dx = {-1, +1, 0, 0};
            vector<int> dy = {0, 0, -1, +1};
            
            for(int i = 0; i<dx.size(); i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol< m 
                && ans[nrow][ncol] == initial && ans[nrow][ncol] != newColor){
                    dfs(initial, ans, nrow, ncol,newColor);
                }
            }
            
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // if(image[sr][sc] == newColor){
        //     return image;
        // }
        
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>>ans = image;
        q.push({sr, sc});
        int initialColor = image[sr][sc];
        image[sr][sc] =  newColor;
        dfs(initialColor, ans, sr, sc, newColor);

        
        return ans;
        
    }
