class Solution {
public:

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


MY SOLUTION BY ITERATING OVER LL INSTEAD OF COUNT


class Solution {
public:

    pair<ListNode*, int> reversell(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw = curr->next;
        int count = 0;

        while(curr != NULL){
           forw = curr ->next;

            curr->next = prev;
            prev = curr;
            curr = forw;
            count++;

        }

        return {prev,count};
    }
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> s;
        // reverse because we need to traverse from end
        auto [reversedHead, count] = reversell(head);

        ListNode* temp = reversedHead;
        vector<int> ans(count);

        int i = 0;

        while(temp != NULL){
           while(!s.empty() && s.top() <= temp->val){
            s.pop();
           }
           
        //    mistake didnt write this condition
            if (!s.empty()) {
                ans[i] = s.top();
            }
            else{
                ans[i] = 0;
            }
            
           i++;
           s.push(temp->val);
           temp = temp->next;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
