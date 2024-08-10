class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL){
            return head;
        }

        Node* temp = head;
        Node* head2 = new Node(0);
        Node* iter = head2;
        
        // where all nodes random ptr exits in OLD LL, string is to denote if ptr is NULL
        unordered_map<int, string> map1;
        // where all the nodes->val are present in NEW LL
        unordered_map<int, Node*> map2;

        while(temp != NULL){
          iter->next = new Node(temp->val);
          iter = iter->next;
          
          if(temp->random == NULL) map1[temp->val] = "%";
          else map1[temp->val] = to_string(temp->random->val);

          map2[iter->val] = iter;

          temp = temp->next;
        }

        iter->next = NULL;

        iter = head2->next;

        while(iter != NULL){
            
            // whats the random ptr value of this in OLD LL
            string ptrvalue = map1[iter->val];
            if(ptrvalue == "%"){
                iter->random = NULL;
            }
            else
            // where this pointer value is present in NEW LL
            iter->random = map2[stoi(ptrvalue)];

            iter = iter->next;
        }

        return head2->next;

    }
};
