SC: 
3N vector<int> &vis, 
vector<int> &tin, vector<int> &low

TC: DFS
V+2E---> UNDIRECTED GRAPH


class Solution {
    int timer = 1;
  public:
    void dfs(int node, int parent, vector<int>adj[], vector<int> &vis, 
        vector<int> &tin, vector<int> &low, vector<int> &mark){
            vis[node] = 1;
            tin[node] = low[node] = timer++;
            int child = 0;
            
            for(auto i : adj[node]){
                if(i == parent) continue;
                
                if(vis[i] == 0){
                    dfs(i, node, adj, vis, tin, low, mark);
                    low[node] = min(low[i], low[node]);
                    
                    if(low[i] >= tin[node] && parent != -1){
                        mark[node] = 1;
                    }
                    
                    child++;
                }
                else{
                    low[node] = min(low[node], tin[i]);
                }
            }
            
            if(child > 1 && parent == -1){
                mark[node] = 1;
            }
        }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
       
       int n = V;
       vector<int> vis(n,0);
       vector<int> tin(n,-1);
       vector<int> low(n, -1);
       
       vector<int> mark(n,0);
       
       for(int i = 0; i<n; i++){
           if(!vis[i]){
               dfs(i, -1, adj, vis, tin, low, mark);
           }
       }
       
       vector<int> ans;
       
       for(int i = 0; i<n; i++){
           if(mark[i] == 1){
               ans.push_back(i);
           }
       }
       
       if(ans.size() == 0){
           return {-1};
       }
       
       return ans;
    }
};


For finding bridges, the key is to determine whether an edge (between u and v) is a bridge or not. 
A bridge exists if there is no other way for the subtree rooted at v to connect to an ancestor of u.


For Articulation Points: We check tin[it] because we only care about whether there’s a back edge from it to an ancestor of node.
If there is, it means node has a way to connect back to its ancestors through it, and it might not be an articulation point.


  so what i understand-----
ANSWER
when vis[it] is 1 ---> we are considering it to be a potencial answer so we don't use low[it] instead use tin[it]
because if this is answer i.e articulation point ----> we will remove it...so we cant reach the ancestors through it?
When we find that vis[it] == 1, it means that it (the adjacent node of node) has already been visited in the DFS traversal, indicating that there is a 
back edge from node to it (a node that was visited earlier in the DFS). This back edge connects node to an ancestor of the current DFS subtree.

Now, for articulation points, the focus is on whether the current node (node) has an alternative way to reach its ancestors through its neighbors. 
If there's a back edge from node to a previously visited node (it), this is reflected in tin[it], which records how early this neighbor was discovered

HERE:
1 -- 2 -- 3 -- 4 -- 5
 \                  /
  ------------------

The presence of this back edge from NODE to IT creates an alternative path from NODE back to the earlier nodes in the DFS tree.
The presence of this back edge from 5 to 1 creates an alternative path from 5 back to the earlier nodes in the DFS tree.
Normally, if there's no back edge, the only way to reach nodes like 1, 2, 3, and 4 from 5 would be through the tree edge 
(the path 5 -> 4 -> 3 -> 2 -> 1)



However, the back edge 5 -> 1 provides a direct connection from 5 to 1, creating an alternative route. 
Even if we "cut" or "remove" node 4 from the graph, node 5 could still reach the rest of the graph through this back edge.
This back edge indicates that removing node 4 (or any other node in the path) wouldn't disconnect node 5 from the rest of the graph, 
because node 5 can still reach earlier nodes through the back edge to 1.
The back edge shows that node 5 (and its subtree) is not dependent on node 4 for connectivity to the rest of the graph. 
There is an alternative path to connect back to node 1, meaning node 4 is not an articulation point in this case.

When a back edge is found, it indicates that there exists a path back to an ancestor, which allows us to connect components even if a vertex is removed. Hence, if the low value 
of a child vertex is less than the tin value of the parent vertex, that child has a way to reach an ancestor that does not depend on the parent.



