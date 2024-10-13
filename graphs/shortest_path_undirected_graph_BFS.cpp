TC:
O(V+2E)--->undirected
  
SC:
dist array---> O(N)
queue---->O(N)
adj--->o(N+E)

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> dist(N, INT_MAX);
        dist[src] = 0;
        
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto i: adj[node]){
                if(dist[node] + 1 < dist[i]){
                    dist[i] = dist[node] + 1;
                    q.push(i);
                }
            }
        }
        
        for(auto &i : dist){
            if(i == INT_MAX){
                i = -1;
            }
        }
        
        return dist;
    }
};
