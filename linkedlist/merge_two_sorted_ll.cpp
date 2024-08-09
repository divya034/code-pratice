
RECURSIVE WAY
class Solution {
public:
    // Function which returns the root of the flattened linked list.
    
    Node* mergeTwoLists(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;
        
        Node* result;
        
        if (a->data < b->data) {
            result = a;
            result->bottom = mergeTwoLists(a->bottom, b);
        } else {
            result = b;
            result->bottom = mergeTwoLists(a, b->bottom);
        }
        
        result->next = NULL; // Set next to null since we're flattening the list
        return result;
    }

    Node* flatten(Node* root) {
        if (!root || !root->next) return root;
        
        // Recursively flatten the next list
        root->next = flatten(root->next);
        
        // Merge this list with the next flattened list
        root = mergeTwoLists(root, root->next);
        
        return root;
    }
};


NOT IN SORTED FORMAT:

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* findTail(Node* root){
        
        if(root == NULL){
            return NULL;
        }
        
        Node* temp = root;
        
        // to get tail node dont go till NULL go till 1 before NULL
        while(temp->bottom != NULL){
            temp = temp->bottom;
        }
        
        return temp;
    }
    
    Node* solve(Node* root){
        if(root == NULL){
            return NULL;
        }
        
        
        for(Node* i = root; i != NULL; i = i->next){
            if(i->bottom){
                Node* tail = findTail(i->bottom);
                
                Node* forw = i->next;
                i->next = i->bottom;
                i->bottom = NULL;
                tail->next = forw;
            }
        }
        
        return root;
    }
    
    Node *flatten(Node *root) {
        Node* ans = solve(root);

        return ans;
    }
};
