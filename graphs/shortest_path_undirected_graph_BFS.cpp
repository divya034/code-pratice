TC:
O(V+2E)--->undirected
  
SC:
dist array---> O(N)
queue---->O(N)
adj--->o(N+E)

class Solution {
  public:

vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // Adjacency list representation
       vector<pair<int, int>> adj[N];  // Adjacency list for weighted graph
    for (int i = 0; i < M; i++) {
        int u = edges[i][0], v = edges[i][1], weight = edges[i][2];
        adj[u].push_back({v, weight});
    }

    vector<int> dist(N, INT_MAX); 
    queue<int> q;
    q.push(0);
    dist[0] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Explore neighbors
       for (int j = 0; j < adj[node].size(); j++) {
            int nextNode = adj[node][j].first;
            int edgeWeight = adj[node][j].second;
            
            // Relaxation step
            if (dist[node] + edgeWeight < dist[nextNode]) {
                dist[nextNode] = dist[node] + edgeWeight;
                q.push(nextNode);
            }
        }
    }

    // Replace unreachable nodes' distances with -1
    for (auto &it : dist) {
        if (it == INT_MAX) it = -1;
    }
    
    return dist;
    }
};
