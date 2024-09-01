NOT WORKING ON GFG BUT CORRECT

Time Complexity:
O(N1 + N2): Where N1 and N2 are the number of nodes in root1 and root2, respectively. Each node is pushed and popped from the stack exactly once, so the overall time complexity is linear with respect to the total number of nodes in both trees.

    Space Complexity:
O(h1 + h2): In the worst case, this could be 
O(N1+N2) if the trees are skewed, but typically it's much smaller, especially for balanced trees
class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        Node* a = root1;
        Node* b = root2;
        stack<Node*> s1;
        stack<Node*> s2;
        
        int c = 0;
        
        while(true){
            while(a){
                s1.push(a);
                a = a->left;
            }    
            
            while(b){
                s2.push(b);
                b = b->right;
            }
            
            Node* atop = s1.top();
            Node* btop = s2.top();

            
            if(atop->data + btop->data == x){
                c++;
                a = atop->right;
                s1.pop();
                
                b = btop->left;
                s2.pop();
            }
            else if(atop->data + btop->data > x){
                b = btop->left;
                s2.pop();
            }
            else{
                a = atop->right;
                s1.pop();
            }
            
            if(s1.empty() || s2.empty()){
                break;
            }

        }
        
        return c;
    }
};


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
