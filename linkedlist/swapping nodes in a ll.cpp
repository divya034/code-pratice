class Solution {
public:
    void swapnode(ListNode* &head, ListNode* &prev1, ListNode* &temp1, ListNode* &prev2, ListNode* &temp2) {
        if (temp1 == temp2) return;  // If the nodes are the same, no need to swap

        // Handle the case where one of the nodes is the head
        if (prev1 != NULL) {
            prev1->next = temp2;
        } else {
            head = temp2;  // temp1 is the head, so now head should point to temp2
        }

        if (prev2 != NULL) {
            prev2->next = temp1;
        } else {
            head = temp1;  // temp2 is the head, so now head should point to temp1
        }

        // Swap the next pointers of temp1 and temp2
        ListNode* temp = temp1->next;
        temp1->next = temp2->next;
        temp2->next = temp;
    }


    int getLength(ListNode* head){
        int c = 0;
        ListNode* temp = head;

        while(temp != nullptr){
            c++;
            temp = temp->next;
        }

        return c;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        int n = getLength(head);
        if(k > n){
            return head;
        }

        int move = n-k;
        int index = 1;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        ListNode* prev1 = NULL;
        ListNode* prev2 = NULL;

// getting last
        for(int i = 0; i <= move-1; i++){
            prev2 = temp2;
            temp2 = temp2->next;
        }

// getting first value
        for(int i = 0; i < k-1; i++){
            prev1 = temp1;
            temp1 = temp1->next;
        }

       swapnode(head, prev1, temp1, prev2, temp2);

      return head;

    }
};
