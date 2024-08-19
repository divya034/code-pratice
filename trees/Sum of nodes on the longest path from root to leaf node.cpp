class Solution
{
public:
    void solve(Node* root, int len, int sum, int &maxlen, int &maxsum){
        if(root == NULL){
            if(len > maxlen || len == maxlen && sum > maxsum){
                maxlen = len;
                maxsum = sum;
            }
            //mistake forgot to return
            return;
        }
        
        sum = sum + root->data;
        
        solve(root->left, len + 1, sum, maxlen, maxsum);
        solve(root->right, len + 1, sum, maxlen, maxsum);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        if(root == NULL){
            return 0;
        }
        
        int maxlen = 0;
        int maxsum = INT_MIN;
        solve(root,0,0,maxlen, maxsum);
        
        return maxsum;
    }
};
