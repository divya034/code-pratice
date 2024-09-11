 Function iscbt(Node* root):
Time Complexity:

The function uses BFS (Breadth-First Search), which visits every node of the tree exactly once.
space complexity is determined by the queue, which in the worst case may contain the maximum number of nodes at the last level

checkmax(struct Node* tree):
Time Complexity:

The function recursively traverses every node in the binary tree. For n nodes, it will visit each node exactly once.

In the worst case (for a skewed tree), the height can be n, so the space complexity is O(h), where h is the height of the tree.
For a balanced binary tree, the height is O(log n), so the space complexity can be O(log n) in the best case and O(n) in the worst case

overall:
This function calls both checkmax(tree) and iscbt(tree) once.
 Since both have time complexity O(n), the overall time complexity of isHeap is O(n).

Space Complexity:
The space complexity is the sum of the space used by checkmax and iscbt.
The worst-case space complexity is O(n) due to the recursion in checkmax and the queue in iscbt.

class Solution {
  public:
   bool iscbt(Node* root) {
        queue<Node*> q;
        q.push(root);
        bool foundNull = false;

        while(!q.empty()){
             Node* frontele = q.front();
             q.pop();

             if(frontele == NULL){
                foundNull = true;
             }

             if(frontele != NULL && foundNull == true){
                return false;
             }
             
             if(frontele != NULL){
             q.push(frontele->left);
             q.push(frontele->right);
             }
        }

        return true;
    }
    bool checkmax(struct Node* tree){
        if(tree == NULL){
            return true;
        }
        
        bool left = checkmax(tree->left);
        bool right = checkmax(tree->right);
        
        bool node = true;
        
        if(tree->right && tree->left)
            node = tree->data > tree->right->data
                    && tree->data > tree->left->data;
        else if( tree->left)
            node = tree->data > tree->left->data;
        else if( tree->right)
            node = tree->data > tree->right->data;
        
        return left && right && node;
        
    }
    
    bool isHeap(struct Node* tree) {
        return checkmax(tree) && iscbt(tree);
    }
};
