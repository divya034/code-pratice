TC: (V+E)LOGV
+ O(N) ---> backtracking in parent array

SC:
Adj---> O(N + 2E)
dist and parent array ---> O(N)
pq ---> o(n)

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<pair<int, int>> adj[n+1];
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        // shortest path to reach each node is the node itself
        vector<int> parent(n + 1);
        for(int i = 1; i<=n; i++){
            parent[i] = i;
        }
        
        vector<int> dist(n + 1, INT_MAX);
        dist[1] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0,1});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            for(auto i : adj[node]){
                int adjnode = i.first;
                int adjwt = i.second;
                
                if(dis + adjwt < dist[adjnode]){
                    dist[adjnode] = dis + adjwt;
                    pq.push({dis + adjwt , adjnode});
                    parent[adjnode] = node;
                }
            }
        }
        
            if(dist[n] == INT_MAX) {
        return {-1};
    }
        vector<int> path;
        
        int current = n;
        
        while(parent[current] != current){
            path.push_back(current);
            current = parent[current];
        }
        
        path.push_back(1);
           path.push_back(dist[n]);
        
        reverse(path.begin(), path.end());
        return path;
        
    }
};
