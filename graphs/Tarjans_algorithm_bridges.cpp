TC:
DFS:
O(N+2E)
  
Adj list
o(n+2e)
  
sc:
3N for vector disc, vis, low
N+2E for adj list---as its undirected graph



class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, 
        vector<int> &vis, vector<vector<int>> &bridges){
            vis[node] = 1;
            // presently initialse both with reaching time
            disc[node] = low[node] = timer++;

            for(auto i : adj[node]){
                if(i == parent) continue;

                if(vis[i] == 1){
                    // already vis before this node is called
                    // that means this adj node is already in the path to reach node-->same component
                    // whichever is the lower node, both can reach
                    low[node] = min(low[i], low[node]);
                }
                else{
                    dfs(i, node, adj, disc, low, vis, bridges);
                    low[node] = min(low[i], low[node]);
                    // if low[node] did not get updated with child's low[i] that means parent can already reach a lower ancertor than child
                    // disc[node] < low[it]
                    // that means child's lowest reachable node comes after parent so we can partition graph here
                    if(disc[node] < low[i]){
                        bridges.push_back({node, i});
                    }
                    // if(disc[node] >= low[i]) ---> child can reach lowest node(ancestor DFS) that come before/when parent is inserted
                }
            }
        }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // create neighbors:
        vector<vector<int>> adj(n);

        for(auto i: connections){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // create discovery time and lowest possible insertion time node we can reach (oldest ancestor in DFS call)
        vector<int> disc(n,-1);
        vector<int> low(n,-1);
        vector<int> vis(n, 0);
        vector<vector<int>> bridges;
        int parent = -1;

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i, parent, adj, disc, low, vis, bridges);
            }
        }
        // or for connected compoenents dfs(0, -1, adj, disc, low, vis, bridges)

        return bridges;
        
    }
};
