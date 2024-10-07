TC: find all the edges-- o(n+e)
sort--- e---ElogE
iterate on all edges---
E x 4*ALPHA
Total-- ElogE + Ex4alpha

SPACE:
EGES --O(E)
RANK, PARENT, SIZE ARR = O(N)
TOTAL- E+ N



class disjoint{
  private:
  vector<int> rank, parent, size;
  
  public:
  disjoint(int n){
      rank.resize(n+1,0);
      parent.resize(n+1,0);
      size.resize(n+1);
      
      for(int i = 0; i<=n; i++){
          parent[i] = i;
      }
   }
  
    //   path compression
  int findparent(int node){
      if(node == parent[node]){
          return node;
      }
      
    //   logn --> return findparent(parent[node]);
      return parent[node] = findparent(parent[node]);
  }
  
  void unionbyrank(int u, int v){
    //   connects u and v
      int p_u = findparent(u);
      int p_v = findparent(v);
      
    //   same componenet, ultimate parent is same
      if(p_u == p_v){
          return;
      }
      
      if(rank[p_u] < rank[p_v]){
          parent[p_u] = p_v;
      }
      
      else if(rank[p_u] > rank[p_v]){
          parent[p_v] = p_u;
        //   height will remain same
      }
      
      else{
        //  height is same because on other side
        // attach anyone to anyone
        parent[p_v] = p_u;
        rank[p_u]++;
        // height will increase when both were same height before
        
      }
      
  }
  
    void unionbysize(int u, int v) {
        int p_u = findparent(u);
        int p_v = findparent(v);
        
        // already attached
        if(p_u == p_v) return;
        
        if(size[p_u] < size[p_v]){
            parent[p_u] = p_v;
            size[p_v] += p_u;
        }
        else{
            // we will change size in all cases
            // size[p_u] > size[p_v] or EQUAL
            // attach p_v under p_u
            parent[p_v] = p_u;
            size[p_u] += p_v;
        }
        
    }
  
  
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        // adj nodes will only have {adjnode and weight connecting them]
        // we need node, adjnode, wt
        
        for(int i = 0; i < V; i++){
            for(auto j: adj[i]){
                int adjnode = j[0];
                int wt = j[1];
                int node = i;
                
                edges.push_back({wt, {node, adjnode}});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        // edges can be bidirectional---> 1 to 2 will be inserted and 2 to 1 also
        // But disjoint sent will only consider 1 because 1 and 2 will become part of same component by the time we reach 2,1
        
        int totalwt = 0;
        disjoint ds(V);
        for(auto i: edges){
            int wt = i.first;
            int u = i.second.first;
            int v = i.second.second;
            
            // if they belong to the same component
            if(ds.findparent(u) != ds.findparent(v)){
                totalwt += wt;
                ds.unionbysize(u,v);
            }
        }
        
        
        return totalwt;
    }
};
