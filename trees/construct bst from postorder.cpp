class Solution {
public:
    void getmapping(vector<int> &inorder, unordered_map<int, int> &m){
        for(int i = 0; i < inorder.size(); i++){
            m[inorder[i]] = i;
        }
    }

    TreeNode* constructTree(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &m, int &postindex, 
    int inorderstart, int inorderend){
         // MISTAKE WROTE PREORDER CONSITION POSTINDEX >= SIZE
      // MISTAKE DIDNT PASS POSTINDEX BY REFERENCE
        if(postindex < 0){
            return nullptr;
        }

        if(inorderstart > inorderend){
            return nullptr;
        }

        int element = postorder[postindex];
        postindex--;

        TreeNode* node = new TreeNode(element);

        int inorderindex = m[element];

        node->right = constructTree(inorder, postorder, m, postindex, inorderindex + 1, inorderend);
        node->left = constructTree(inorder, postorder, m, postindex, inorderstart, inorderindex - 1);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inorderstart = 0;
        int inorderend = inorder.size() - 1;
        unordered_map<int, int> m;
        getmapping(inorder, m);
        int postindex = postorder.size() - 1;
        
        return constructTree(inorder, postorder, m, postindex, inorderstart, inorderend);
    }
};
