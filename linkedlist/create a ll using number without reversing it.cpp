CREATE IN THE RIGHT ORDER

ListNode* attachCarry(int carry) {
    // Placeholder for the head of the linked list
    ListNode* head = nullptr;

    // Process each digit in the carry
    while (carry > 0) {
        // Extract the last digit of the carry
        int digit = carry % 10;

        // Create a new node with the extracted digit
        ListNode* node = new ListNode(digit);

        // Insert the new node at the beginning of the list
        node->next = head;
        head = node;

        // Update the carry to remove the last digit
        carry /= 10;
    }

    return head;  // Return the head of the newly formed list
}



CRAETE IN REVERSER ORDER:

ListNode* attachCarry(int carry) {
    // Placeholder to carry the linked list
    ListNode* head = nullptr;
    ListNode* current = nullptr;

    while (carry > 0) {
        // Extract the last digit of the carry
        int digit = carry % 10;
        
        // Create a new node with the extracted digit
        ListNode* node = new ListNode(digit);
        
        // If the list is empty, initialize the head
        if (!head) {
            head = node;
            current = head;
        } else {
            // Otherwise, link the new node to the current list
            current->next = node;
            current = current->next;
        }

        // Update the carry to remove the last digit
        carry /= 10;
    }

    return head;  // Return the head of the newly formed list
}
