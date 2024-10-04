TC:
The BFS can potentially visit all the cells in the image (matrix). Since you visit each cell only once, the time complexity is O(n × m),

Space Complexity (SC)
Visited Array:

You are using a visited array vis of size n × m to keep track of whether a cell has been visited. This takes O(n × m) space.
Queue for BFS:

In the worst case (if the entire grid needs to be filled), the queue may hold all cells of the grid. This also requires O(n × m) space.
class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        if(image[sr][sc] == newColor){
            return image;
        }
        
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        q.push({sr, sc});
        int initialColor = image[sr][sc];
        image[sr][sc] =  newColor;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            vis[row][col] = 1;
            q.pop();
            
            vector<int> dx = {-1, +1, 0, 0};
            vector<int> dy = {0, 0, -1, +1};
            
            for(int i = 0; i<dx.size(); i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol< m && image[nrow][ncol] == initialColor && !vis[nrow][ncol]){
                    image[nrow][ncol] = newColor;
                    q.push({nrow,ncol});
                }
            }
        }
        
        return image;
        
    }
};
