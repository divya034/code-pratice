OPTIMIZED LOVE BABBAR

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
        stack<pair<int, int>> s; 
        // store index and value
        ListNode* temp = head;
        vector<int> ans;

        int i = 0;

        while(temp != NULL){
           ans.push_back(0);


           while(!s.empty() && s.top().second < temp->val){
            auto topele = s.top();
            s.pop();
            // present val is greater than prev element pushed in stack
            ans[topele.first] = temp->val;

           }

           s.push({i, temp->val});
           i++;
           temp = temp->next;
        }

        return ans;
    }
};

CREATING AN ARRAY:

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        // Extract values from the linked list into a vector
        vector<int> values;
        for (ListNode* node = head; node != nullptr; node = node->next) {
            values.push_back(node->val);
        }

        int n = values.size();
        vector<int> nextGreater(n, 0);
        stack<int> s;  // Stack to store the next greater elements

        // Traverse the values vector from the end to the beginning
        for (int i = n - 1; i >= 0; --i) {
            // Maintain the stack such that the top of the stack is the next greater element
            while (!s.empty() && s.top() <= values[i]) {
                s.pop();
            }

            // If the stack is not empty, the top element is the next greater element
            if (!s.empty()) {
                nextGreater[i] = s.top();
            }

            // Push the current value onto the stack
            s.push(values[i]);
        }

        return nextGreater;
    }
};




REVERSE LL AND TRAVERSE LL
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
