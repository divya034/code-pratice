

#include <bits/stdc++.h>
using namespace std;

class disjoint{
  private:
  vector<int> rank, parent;
  
  public:
  disjoint(int n){
      rank.resize(n+1,0);
      parent.resize(n+1,0);
      
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
      }
      
      else{
        //   rank is same
        // attach anyone to anyone
        parent[p_v] = p_u;
        rank[p_u]++;
        
        // height will increase when both were same height before
        
      }
  }
  
  
};

int main()
{
    disjoint ds(7);
    
    ds.unionbyrank(1, 2); 
    ds.unionbyrank(2, 3); 
    ds.unionbyrank(4, 5); 
    ds.unionbyrank(6, 7); 
    ds.unionbyrank(5, 6); 
    
    if(ds.findparent(3) == ds.findparent(7)){
        cout<<"same\n";
    }
    else{
        cout<<"not same\n";
    }
    
    ds.unionbyrank(3,7);
    
    if(ds.findparent(3) == ds.findparent(7)){
        cout<<"same\n";
    }
    else{
        cout<<"not same\n";
    }

    return 0;
}
