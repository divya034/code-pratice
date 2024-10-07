TC: ElogE ---E FOR WHILE LOOP IT WILL HAVE ALL EDGES, LOG E--- FOR PQ SIZE
  
  + ElogE ---FOR I: ADJ[NODE], INSERTION into pq

SC: VIS ARRAY AND ADJ vector
o(v)



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        
        vector<int> vis(V, 0);
        
        pq.push({0,0});
        int sum = 0;
        
        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();
            
            int wt = i.first;
            int node = i.second;
            
            if(vis[node] == 1) continue;
            
            //here add the node and parent into MST, if parent = -1
            // just mark node (0) as visited and add its adj nodes
            // pq.push(adj_wt, adj_node, node)
            // because node becomes parent
            vis[node] = 1;
            sum += wt;

            for(auto j: adj[node]){
                int adj_node = j[0];
                int adj_wt = j[1];
                
                if(vis[adj_node] == 0){
                    pq.push({adj_wt, adj_node});
                }
            }
        }
        
        return sum;
    }
};
