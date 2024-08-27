class Solution {
public:
    // Function to perform inorder traversal and store values
    void inorder(TreeNode* root, vector<int>& sortedNodes) {
        if (!root) return;
        inorder(root->left, sortedNodes);
        sortedNodes.push_back(root->val);
        inorder(root->right, sortedNodes);
    }

    // Function to find floor and ceil using binary search
    vector<int> findFloorCeil(vector<int>& sortedNodes, int value) {
        int n = sortedNodes.size();
        int floor = -1, ceil = -1;
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (sortedNodes[mid] == value) {
                return {value, value};
            } else if (sortedNodes[mid] < value) {
                floor = sortedNodes[mid];
                low = mid + 1;
            } else {
                ceil = sortedNodes[mid];
                high = mid - 1;
            }
        }
        return {floor, ceil};
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> sortedNodes;
        inorder(root, sortedNodes);

        vector<vector<int>> ans;
        for (int query : queries) {
            ans.push_back(findFloorCeil(sortedNodes, query));
        }
        return ans;
    }
};



O(nodes * all nodes in queries)
O(N*M)
class Solution {
public:
    int findFloorBT(TreeNode* root, int value){
           int ans = -1;
           while(root){
            if(root->val == value){
                return root->val;
            }
            else if(root->val > value){
                root = root->left;
            }
            else{
                ans = root->val;
                root = root->right;
            }
           }

           return ans;
    }

    int findCeilBT(TreeNode* root, int value){
           int ans = -1;
           while(root){
            if(root->val == value){
                return root->val;
            }
            else if(root->val > value){
                ans = root->val;
                root = root->left;
            }
            else{
                root = root->right;
            }
           }

           return ans;
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        // [largest value <= query, smallest value >= query]
        // if not -1
        vector<vector<int>> ans;
        for(int i = 0; i <= queries.size() - 1; i++){
            TreeNode* temp = root;
            int floor = findFloorBT(temp, queries[i]);

            if(floor == queries[i]){
                ans.push_back({floor, floor});
                continue;
            }
            
            int ceil = findCeilBT(temp, queries[i]);
            
            ans.push_back({floor, ceil});


        }

        return ans;


    }
};
