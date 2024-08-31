MINE:
BOTH CODES SAME:
BST Traversal: Both BSTIterator instances (l and r) traverse the BST.
 Each next() call performs a controlled traversal of the BST, either moving left (in-order) or right (reverse in-order).
Each call to next() involves traversing down a branch of the tree,
 which on average is O(log N) where N is the number of nodes in the tree. Since you could potentially traverse every node once,
 the worst-case time complexity for all next() calls together is O(N).
Total Time Complexity: 
Since the findTarget function only iterates through the BST once and each iteration takes O(log N) time, the overall time complexity is:
TC = O(N)

Space Used by Stack in BSTIterator:

The stack s in each BSTIterator object holds nodes from the tree. In the worst case (e.g., a completely skewed tree), the stack might hold up to O(H) nodes, where H is the height of the tree.
For a balanced BST, H = O(log N), and for a skewed BST, H = O(N).
Since you have two iterators (l and r), the total space used by both stacks is O(H) + O(H) = O(H).
Auxiliary Space: Other than the stack, the auxiliary space used by the algorithm is constant (O(1)).

Total Space Complexity: The overall space complexity is driven by the space required to store the stack in each iterator:

SC = O(H), where H is the height of the tree.


class BSTIterator {
public:
    stack<TreeNode*> s;
    bool reverse;
    void pushall(TreeNode* root){
       while(root != NULL){ 
        s.push(root);
        if(reverse == false){
           root = root->left;
        }
        else{
            root = root->right;
        }
       }
    }
    // reverse = TRUE = BEFORE
    // reverse = false = NEXT

    BSTIterator(TreeNode* root, bool reverse) {
        this->reverse = reverse;
        pushall(root);
    }
    
    int next() {
        TreeNode* tmp = s.top();
        s.pop();
        if(reverse == false){
            pushall(tmp->right);
        }
        else{
            pushall(tmp->left);
        }

        return tmp->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();
    while(i < j){
        if(i + j < k){
            i = l.next();
        }
        else if(i + j > k){
            j = r.next();
        }
        
        else if(i + j == k){
            return true;
        }
        
        return false;
    }
};


CHATHPT:


class BSTIterator {
public:
    stack<TreeNode*> s;
    bool reverse = false;

    BSTIterator(TreeNode* root, bool isReverse) : reverse(isReverse) {
        pushall(root);
    }
    
    void pushall(TreeNode* root) {
        while (root != NULL) {
            s.push(root);
            if (!reverse) {
                root = root->left;  // forward: go left
            } else {
                root = root->right; // backward: go right
            }
        }
    }
    
    int next() {
        TreeNode* tmp = s.top();
        s.pop();
        if (!reverse) {
            pushall(tmp->right); // forward: after left, go right
        } else {
            pushall(tmp->left);  // backward: after right, go left
        }
        return tmp->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l(root, false);  // Iterator for smallest values (inorder)
        BSTIterator r(root, true);   // Iterator for largest values (reverse inorder)

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k) {
                return true;
            } else if (i + j < k) {
                i = l.next();  // move forward pointer
            } else {
                j = r.next();  // move backward pointer
            }
        }

        return false;
    }
};
