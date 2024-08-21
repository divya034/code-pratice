For post order Morris Traversal->
We will modify the preorder morris traversal from root->left->right to root->right->left. For this we need to do one more change. While in normal preorder and inorder, we were creating thread from right most node of left subtree to present node, here we will create thread from left most node of right subtree to present node as here we have to cover right subtree before left subtree

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root)
        {
            TreeNode *curr = root;//We will create thread from left most node of right subtree to present node and will
            						//travell to that node using curr
            if(curr->right)//if root has right child
            			//We can't push directly this root node val to ans as we are not sure whether we are here
            			//thorough thread link after covering right subtree or we are here for the first time
            {
                curr = curr->right;
                while(curr->left && curr->left != root)//go to left most node of right subtree
                    curr=curr->left;
                if(curr->left != root)//not threaded yet
                {
                    ans.push_back(root->val);//it means root was visited for first time and this is modified preorder hence 
                    						//push this node's val to ans
                    curr->left = root;//create the thread
                    root = root->right;//go to right to cover right subtree as modified preorder is root->right->left
                }
                else//was threaded
                {
                    curr->left = NULL;//break the thread
                    root = root->left;//right subtree has been covered hence now cover the left one
                    					//no need to push this node value as we are here for the second time using thread
                    					//link
                }
            }
            else//root hasn't right child
            {
                ans.push_back(root->val);//modified preorder is root->right->left hence push this value before going to left
                root = root->left;
            }
        }
        reverse(ans.begin(),ans.end());//reversing root->right->left to left->right->root to make it post order
        return ans;
    }
};
