TC: V x E
O(E) for each relaxation iteration.
  This is doneV is the number of vertices):
sc:
dist array-- o(v)
adj list---o(V+E)

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        
        for(int i = 0; i<V-1; i++){
            for(auto j: edges){
                int node1 = j[0];
                int node2 = j[1];
                int wt = j[2];
                
                if(dist[node1] != 1e8 && dist[node1] + wt < dist[node2]){
                    dist[node2] = dist[node1] + wt;
                }
            }
        }
        
        // find negative cyle
        
        for(auto j: edges){
            int node1 = j[0];
            int node2 = j[1];
            int wt = j[2];
            
            if(dist[node1] != 1e8 && dist[node1] + wt < dist[node2]){
                return {-1};
            }
        }
        
        return dist;
    }
};
