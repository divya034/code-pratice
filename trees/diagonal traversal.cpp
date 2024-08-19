vector<int> diagonal(Node *root)
{
   queue<Node*> q;
   
   q.push(root);
    vector<int> ans;
    // if (root == nullptr) 
    //     return ans;
     while(!q.empty()){
         Node* temp = q.front();  
         q.pop();
       while(temp != NULL){
           ans.push_back(temp->data);
           
           if(temp->left){
               q.push(temp->left);
           }
    
           temp = temp->right;
        }
     }
   
   return ans;
}
