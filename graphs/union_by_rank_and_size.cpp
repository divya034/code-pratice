O(2ALPHA)--CONSTANT
SC:
  RANK AND PARENT VECTOR ---O(N)

The rank represents the approximate height of the tree
The size reprsent number of nodes in the tree
rank[ulp_u] < rank[ulp_v]:

In this case, we attach the root of the tree with a smaller rank (ulp_u) under the root of the tree with a larger rank (ulp_v).
The height of the overall tree does not change when we do this because the larger tree remains dominant.

 #include <bits/stdc++.h>
using namespace std;

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

int main()
{
    disjoint ds(7);

    ds.unionbysize(1, 2); 
    ds.unionbysize(2, 3); 
    ds.unionbysize(4, 5); 
    ds.unionbysize(6, 7); 
    ds.unionbysize(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findparent(3) == ds.findparent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.unionbysize(3, 7); 

    if(ds.findparent(3) == ds.findparent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 



    
    // ds.unionbyrank(1, 2); 
    // ds.unionbyrank(2, 3); 
    // ds.unionbyrank(4, 5); 
    // ds.unionbyrank(6, 7); 
    // ds.unionbyrank(5, 6); 
    
    // if(ds.findparent(3) == ds.findparent(7)){
    //     cout<<"same\n";
    // }
    // else{
    //     cout<<"not same\n";
    // }
    
    // ds.unionbyrank(3,7);
    
    // if(ds.findparent(3) == ds.findparent(7)){
    //     cout<<"same\n";
    // }
    // else{
    //     cout<<"not same\n";
    // }

    return 0;
}
