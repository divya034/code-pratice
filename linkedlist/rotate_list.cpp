class Solution {
public:
    int getLength(ListNode* head){
        ListNode* temp = head;
        int count = 0;

        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        return count;
    }
    // ListNode* reversell(ListNode* node){
    //     ListNode* prev = NULL;
    //     ListNode* curr = node;

    //     while(curr != NULL){
    //         ListNode* forw = curr->next;

    //         curr->next = prev;
    //         prev = curr;
    //         curr = forw;
    //     }

    //     return prev;
    // }
    ListNode* rotateRight(ListNode* head, int k) {
    //    mistake always have null check at the start
       if(head == NULL){
        return head;
       } 
       
    //    mistake didnt do k mod formula
    // if n = 4 and k = 8, target = 4-8 would be negative
       int n = getLength(head);
       k = k % n;
    // check for all K values at once
       if(k == n || n == 1 || k == 0 ){
        return head;
       }

       int target = n - k;
       ListNode* temp = head;

       for(int i = 0; i < target - 1; i++){
            temp = temp->next;
       }

       ListNode* newHead = temp->next;
       ListNode* newTail = newHead;
       temp->next = NULL;

       while(newTail->next != NULL){
        newTail = newTail->next;
       }

       newTail->next = head;

       return newHead;

    }
};
