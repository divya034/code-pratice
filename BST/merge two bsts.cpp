class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> ans;
        
        Node* a = root1;
        Node* b = root2;
        
        stack<Node*> s1;
        stack<Node*> s2;
        
        while(!s1.empty() || !s2.empty() || a != nullptr || b != nullptr){
            while(a){
                s1.push(a);
                a = a->left;
            }
            while(b){
                s2.push(b);
                b = b->left;
            }
            
            // second condition means s1 is not empty
            if(s1.empty() || (!s2.empty() && s1.top()->data >= s2.top()->data)){
                Node* btop = s2.top();
                ans.push_back(btop->data);
                b = btop->right;
                s2.pop();
            }
            else{
                Node* atop = s1.top();
                ans.push_back(atop->data);
                a = atop->right;
                s1.pop();
            }
        }
        
        return ans;
    }
