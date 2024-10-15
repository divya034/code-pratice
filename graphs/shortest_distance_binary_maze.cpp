TC: all N * M cells in the grid need to be visited once.

SC:
queue can contain at most N * M elements in the worst case (i.e., if all cells are added to the queue).
O(n*M)
dist array same^
class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> dest) {
        
        queue<pair<int, pair<int, int>>> q;
        // dist, row&col
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        dist[source.first][source.second] = 0;
        
        q.push({0, source});
        vector<int> x = {-1, 1, 0, 0}; // For moving up, down, left, right
        vector<int> y = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            // Check if we have reached the destination
            if (row == dest.first && col == dest.second) {
                return dis;
            }
            
            // Traverse in all 4 directions
            for (int i = 0; i < 4; i++) {
                int newr = row + x[i];
                int newc = col + y[i];
                
                // Check if the new position is within bounds, not visited, and walkable
                if (newr >= 0 && newr < r &&
                    newc >= 0 && newc < c &&
                    dist[newr][newc] > dis + 1 &&
                    grid[newr][newc] == 1) {
                    
                    // Update distance for the new cell
                    dist[newr][newc] = dis + 1;
                    
                    // Push the new position into the queue
                    q.push({dist[newr][newc], {newr, newc}});
                }
            }
        }
        
        // If the destination is unreachable, return -1
        return -1;
    }
};
