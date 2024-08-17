class Solution {
public:
    void leaf(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(root->data);
        }
        
        leaf(root->left, ans);
        leaf(root->right, ans);
        
        return;
        
    }
    
    void right(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        
        if(root->left == nullptr && root->right == nullptr){
            return;
        }
        
// mistake didnt write if and else consition for BOTH left and right functions
        if(root->right)
          right(root->right, ans);
        else{
           right(root->left, ans);
        }
        
        ans.push_back(root->data);
        
        return;
    }
    
    void left(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        
        // exclude leaf nodes
        if(root-> left == nullptr && root->right == nullptr){
            return;
        }
        
        ans.push_back(root->data);
        // mistake didnt write if and else consition for BOTH left and right functions
        if(root->left)
        left(root->left, ans);
        
        else{
            left(root->right, ans);
        }

        return;
    }
    vector <int> boundary(Node *root)
    {
        //   1. print root
        // 2. print left boundary
        // 3. print leaf nodes
        // 4. print reverse right boundary
        
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        ans.push_back(root->data);
        
        left(root->left, ans);
        
        leaf(root->left, ans);
        leaf(root->right, ans);
        
        right(root->right, ans);
        
        return ans;
    }
};
