void constructTree(Node* root, vector<int> &ans, int level){
    if(root == NULL){
        return;
    }
    
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    // mistake passed level by reference
    level = level + 1;
    constructTree(root->left, ans, level);
    constructTree(root->right, ans, level);

}
vector<int> leftView(Node *root)
{
    vector<int> ans;
    int level = 0;
    constructTree(root, ans, level);
    
    return ans;
}
