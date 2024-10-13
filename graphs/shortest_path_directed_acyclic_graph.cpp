TC: 
O(N+E) ---> Topo sort
o(N+e) --->stack processing

SC:
Stack --> o(N)
adj---> O(N+E)
Recursive stack space O(N) --->toptosort
vis-->o(n)
dist-->o(N)
  
Nodet 0 :
The intuition behind using topological sorting in the context of finding 
the shortest paths in a Directed Acyclic Graph (DAG) is that every node reachable from the source will be in the stack after processing the source node.

Note 1:
when a node comes up in topo sort, all the possible paths to reach that node are considered (as in-degree has become 0),
that's why when we pop it out from the stack, whatever distance is stored in distance array is the final distance for that node.

Note 2:
BFS from source would be better??
it will have more TC than the topo sort logic, since you'd need to revisit a node's adjacent/child nodes if you encounter a shorter path for them in the future again

Note 3:
The question again  has been modified. 
If there is something else (not 0) at the top of the stack, we must not  process that and simply keep popping it until we encounter 0 at the top. 

class Solution {
  public:
void toposort(int node, vector<int> &vis, vector<pair<int,int>> adj[], stack<int> &st) {
        vis[node] = 1;
        
        // Loop over all adjacent nodes of 'node'
        for (int j = 0; j < adj[node].size(); j++) {
            int adjnode = adj[node][j].first;  // Get the adjacent node
            if (!vis[adjnode]) {
                toposort(adjnode, vis, adj, st);
            }
        }
        
        st.push(node);
    }

    // Shortest Path in Directed Acyclic Graph (DAG)
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // Adjacency list representation
        vector<pair<int, int>> adj[N];
        
        // Construct the graph with weights
        for (auto i : edges) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({v, wt});  // Add directed edge with weight
        }
        
        // Step 1: Perform topological sorting
        vector<int> vis(N, 0);
        stack<int> st;
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                toposort(i, vis, adj, st);
            }
        }
        
        // Step 2: Initialize distance array with infinity
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;  // Assuming source node is 0
        
        // Step 3: Process nodes in topological order
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            // If the node has been reached (its distance is not infinity)
            if (dist[node] != INT_MAX) {
                for (auto i : adj[node]) {
                    int adjNode = i.first;
                    int wt = i.second;
                    
                    // Relaxation step
                    if (dist[node] + wt < dist[adjNode]) {
                        dist[adjNode] = dist[node] + wt;
                    }
                }
            }
        }
        
        // Step 4: Replace unreachable nodes' distance with -1
        for (int i = 0; i < N; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};
