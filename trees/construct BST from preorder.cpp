/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   void getmapvalues(unordered_map<int, int> &m, vector<int> inorder){
          
          for(int i = 0; i<inorder.size(); i++){
             m[inorder[i]] = i;
          }
   }
    TreeNode* constructTree(vector<int> preorder, vector<int> inorder,unordered_map<int, int> &valmap, int &preindex, 
    int inorderstart, int inorderend, int size){
        if(preindex >= size){
            return NULL;
        }

        if(inorderstart > inorderend){
            return NULL;
        }

        int element = preorder[preindex];
        preindex++;

        TreeNode* node = new TreeNode(element);

        int indexinorder = valmap[element];

        node->left = constructTree(preorder, inorder, valmap, preindex, inorderstart, indexinorder - 1, size);
        node->right = constructTree(preorder, inorder, valmap, preindex, indexinorder + 1, inorderend, size);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> valmap;
        getmapvalues(valmap, inorder);
        int inorderstart = 0;
        int inorderend = inorder.size() - 1;
        int size = preorder.size();
        int preindex = 0;

        return constructTree(preorder, inorder, valmap, preindex, inorderstart, inorderend, size);
    }
};
