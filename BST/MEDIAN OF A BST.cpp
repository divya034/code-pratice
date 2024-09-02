int morrisnodes(Node* root) {
    Node* curr = root;
    int count = 0;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            count++;
            curr = curr->right;
        } else {
            Node* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = nullptr;
                count++;
                curr = curr->right;
            }
        }
    }

    return count;
}

float actual(Node* root, int n){
    Node* curr = root;
    int c = 0;
    
    int odd1 = (n + 1)/2, odd1val = -1;
    int even1 = n/2, even1val = -1;
    int even2 = (n/2) + 1, even2val = -1;

    while(curr != NULL){
        if(curr->left == nullptr){
            c++;
            if(c == odd1) odd1val = curr->data;
            if(c == even1) even1val = curr->data;
            if(c == even2) even2val = curr->data;
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            
            while(prev->right != nullptr && prev->right != curr){
                prev = prev->right;
            }
            
            if(prev->right == nullptr){
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = 0;
                c++;
                
                if(c == odd1) odd1val = curr->data;
                if(c == even1) even1val = curr->data;
                if(c == even2) even2val = curr->data;
                curr = curr->right;
            }
        }
    }
    
    float med = 0.0;

    if(n%2 == 0){
        med = (even1val + even2val) / 2.0;
    }
    else{
        med = odd1val;
    }
    
    
    return med;
}


float findMedian(struct Node *root)
{
      int n = morrisnodes(root);

      float ans = actual(root, n);
      
      return ans;
}
