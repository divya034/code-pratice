    ListNode* reversell(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        ListNode* next = nullptr;

        // Reverse until reaching the node after 'end'
        while (curr != end) {
            next = curr->next; // Store the next node
            curr->next = prev; // Reverse the link
            prev = curr;       // Move prev to the current node
            curr = next;       // Move curr to the next node
        }
        
        // Return the new head of the reversed segment
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k <= 1) return head;

        ListNode* dummy = new ListNode(0); // Dummy node to handle the new head
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* end = head;

        while (end != nullptr) {
            // Move 'end' to the last node of the current k-group
            for (int i = 1; i < k && end != nullptr; ++i) {
                end = end->next;
            }

            // If 'end' is nullptr, it means the list doesn't have enough nodes for another group
            if (end == nullptr) break;

            ListNode* start = prev->next;  // Start of the current group
            ListNode* nextGroup = end->next; // Node after the current k-group

            // Reverse the current k-group
            end->next = nullptr; // Temporarily end the list to reverse
            prev->next = reversell(start, end);

            // Connect the reversed group with the next part of the list
            start->next = nextGroup;

            // Move 'prev' to the end of the reversed group
            prev = start;
            end = nextGroup; // Move 'end' to the start of the next group
        }

        // The new head is after the dummy node
        head = dummy->next;
        delete dummy; // Free the memory used by the dummy node

        return head;
    }
