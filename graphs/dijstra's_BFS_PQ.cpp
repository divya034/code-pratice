TC: O(n+e)log n traversing all nodes and edges
ther can be n nodes in the PQ

SC:
dist---o(n)
pq---o(n)
adj list = o(v+e)


class Solution
{
	public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
       
       pq.push({0, S});
       
       vector<int> dist(V, INT_MAX);
       
       dist[S] = 0;
       
       while(!pq.empty()){
           int node_dist = pq.top().first;
           int node = pq.top().second;
           pq.pop();
           
           for(auto nbr: adj[node]){
               int nbr_wt = nbr[1];
               int nbr_node = nbr[0];
               
               if(node_dist + nbr_wt < dist[nbr_node]){
                    dist[nbr_node] = node_dist + nbr_wt;
                    pq.push({dist[nbr_node], nbr_node});
               }
           }
       }
       
       return dist;
    }
};
