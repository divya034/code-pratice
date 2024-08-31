NOT WORKING USING BST ITERATOR:
class BSTinorder{
    public:
    stack<Node*> s;
    BSTinorder(Node* root){
        pushall(root);
    }
    
    int next(){
        Node* tmp = s.top();
        s.pop();
        
        if(tmp->right){
            pushall(tmp->right);
        }
        
        return tmp->data;
    }
    
    void pushall(Node* root){
        while(root){
            s.push(root);
            root = root->left;
        }
    }
    
    bool hasnext(){
        return !s.empty();
    }
};

class BSTreverse{
    public:
    stack<Node*> s;
    BSTreverse(Node* root){
        pushall(root);
    }
    
    void pushall(Node* root){
        while(root){
            s.push(root);
            root = root->right;
        }
    }
    
    int next(){
        Node* tmp = s.top();
        s.pop();
        if(tmp->left){
            pushall(tmp->left);
        }
        
        return tmp->data;
    }
    
    bool hasNext(Node* root){
        return !s.empty();
    }
};

class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        BSTinorder b1(root1);
        BSTreverse b2(root2);
        
        int i = b1.next();
        int j = b2.next();
        int count = 0;
        
        while(i < j){
            // cout<<"i "<<i<<" "<<"j "<<j<<endl;
            if(i + j == x){
                count++;
                i = b1.next();
                j = b2.next();
            }
            if(i + j > x){
                j = b2.next();
            }
            if(i + j < x){
                i = b1.next();
            }

        }
        
        return count;
    }
};
