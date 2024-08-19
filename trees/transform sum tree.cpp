class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
   int solve(Node* &root){
        if (root == NULL) {
            return 0;
        }
        
       if(root->left == NULL && root->right == NULL){
           int val = root->data;
           root->data = 0;
           return val;
       }
       
       int l = solve(root->left);
       int r = solve(root->right);
       
       int val = root->data;
       root->data = l + r;
       
       return root->data + val;
   }
   
    void toSumTree(Node *node)
    {
       if(node->left == NULL && node->right == NULL){
           node->data = 0;
           return;
       }
       
       solve(node);

    }
};
