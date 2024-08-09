class Solution{
  public:
  
    // void insert(Node* temp, Node* head1){
    //     Node* prev = head1;
    //     Node* element = head1->next;
    //     Node* forw = element->next;
        
    //     // head1->next is the element we need to insert
    //     temp->next = element;
    //     element->next = NULL;
    //     prev->next = forw;
    // }
    Node* findIntersection(Node* head1, Node* head2)
    {
        unordered_map<int, int> m;
        
        for(Node* i = head2; i!= NULL; i =i->next){
            m[i->data]++;
        }
        
        Node* iter = NULL;
        Node* ansHead = NULL;
        
        for(Node* i = head1; i!= NULL; i = i->next){
            // mistake
            if(m[i->data] >= 1){
                if(iter == NULL){
                    iter = i;
                    ansHead = iter;
                    m[i->data]--;
                }
                else{
                    iter->next = i;
                    iter = iter->next;
                    m[i->data]--;
                }
            }
            
        }
        
        if(iter != NULL){
            iter->next = NULL;
        }
        
        return ansHead;
    }
};
