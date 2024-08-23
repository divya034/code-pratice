class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node* root){
        if(root == nullptr){
            return {0,0};
        }
        
        pair<int,int> l = solve(root->left);
        pair<int,int> r = solve(root->right);
        
        pair<int,int> curr;
        
        // when node is being considered take only excluded part
        curr.first = root->data + l.second + r.second;  // Include current node
        // when present node is not being considered take which is maximum
        // because you can choose inc or exc from prev node
        curr.second = max(l.first, l.second) + max(r.first, r.second);  // Exclude current node

        return curr;
    }
    int getMaxSum(Node *root) 
    {
        pair<int,int> p;
        // include and exclude root values
        p = {0,0};
        int ans = INT_MIN;
        
        p = solve(root);
        return max(p.first, p.second);
        
    }
};
