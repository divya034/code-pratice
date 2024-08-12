class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
         
        ListNode* startzero = head;
        ListNode* newll = NULL;
        ListNode* temp = head->next;

        int sum = 0;

        while(temp != NULL){
            if(temp->val == 0){
                if(newll == NULL){
                    newll = head;
                    newll->val = sum;
                }
                else{
                   newll->next->val = sum;
                   newll = newll->next;
                }
                sum = 0;

            }
            else{
                sum = sum + temp->val;
            }

            temp = temp->next;
        }
     

       temp = newll->next;
       newll->next = NULL;

       while(temp){
        ListNode* next = temp->next;
        delete temp;
        temp = next;                             
       }

        return head;

    }
};
