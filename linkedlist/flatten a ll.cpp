class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    
    Node* merge(Node* a, Node* b){
        if(!a) return b;
        if(!b) return a;
        
        // take two vertical ll
        
        Node* ans;
        if(a->data < b->data){
            ans = a;
            // next node would be after next comparison
            a->bottom = merge(a->bottom, b);
        }
        else{
            ans = b;
            b->bottom = merge(a, b->bottom);
        }
        
        return ans;
    }
    Node *flatten(Node *root) {
       
       if(root == NULL){
           return root;
       }
       
       Node* ans = merge(root, flatten(root->next));
        return ans;
    }
};
