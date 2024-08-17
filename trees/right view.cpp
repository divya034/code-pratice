class Solution
{
    public:
    void solve(Node* root, vector<int> &ans, int level){
        if(root == nullptr){
            return;
        }
        
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        
        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
        // MISTAKE LEVEL + 1
// WILL INCREMENT THE LEVEL VALUE SO FOR ROOT->LEFT CALL IT WILL BE CuurentLEVEL + 2
        // solve(root->right, ans, level++);
        // solve(root->left, ans, level++);
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       
       if(root == nullptr){
           return ans;
       }
       
       solve(root, ans, 0);
    }
};
