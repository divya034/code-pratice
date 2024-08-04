    pair<ListNode*, int> reversell(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int count = 0;

        while (curr != nullptr) {
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
            count++;
        }

        return {prev, count};
    }

    vector<int> nextLargerNodes(ListNode* head) {
        if (!head) return {};

        // Reverse the linked list and get the count of nodes
        auto [reversedHead, count] = reversell(head);
        vector<int> ans(count, 0);
        stack<int> s;
        ListNode* temp = reversedHead;

        for (int i = 0; i < count; ++i) {
            while (!s.empty() && s.top() <= temp->val) {
                s.pop();
            }

            if (!s.empty()) {
                ans[i] = s.top();
            }

            s.push(temp->val);
            temp = temp->next;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
