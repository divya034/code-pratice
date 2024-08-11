class Solution {
public:
    void solve(ListNode* head, int &carry){
        if(head == NULL){
            return;
        }

        solve(head->next, carry);

        int ans = carry > 0 ? head->val * 2 + carry : head->val * 2;
        carry = ans/10;
        head->val = ans % 10;
    }

ListNode* createCarry(int carry, ListNode* originalHead) {
    // Placeholder for the head of the linked list
    ListNode* head = nullptr;
    ListNode* tail = head;

    // Process each digit in the carry
    while (carry > 0) {
        // Extract the last digit of the carry
        int digit = carry % 10;

        // Create a new node with the extracted digit
        ListNode* node = new ListNode(digit);

        // Insert the new node at the beginning of the list
        if(head == nullptr) tail = node;
        node->next = head;
        head = node;

        // Update the carry to remove the last digit
        carry /= 10;
    }
      
    tail->next = originalHead;
    return head;  // Return the head of the newly formed list
}

    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        solve(head, carry);
        
        if(carry != 0){
           ListNode* carryHead = createCarry(carry, head);
           return carryHead;
        }
        else{
            return head;
        }
        
    }
};
