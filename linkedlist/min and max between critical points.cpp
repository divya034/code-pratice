class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == NULL){
            return {-1, -1};
        }
        vector<int> index;

        int count = 1;
        ListNode* temp = head->next;
        ListNode* prev = head;
        
        // 3->4->NULL when temp is 4 stop
        // LOGICAL MISTAKE
        // MIN would not always be index of 0 - index 1, ....3 5 6 ...ans is 6-5 = 1
//max would not always be diff of adjacent elemenst 3 5 6 ....ans is 6 - 3 = 3, instead diff between 1st and last element
        while(temp->next != NULL){
            ListNode* forw = temp->next;
            count++;
            if(temp->val > prev->val && temp->val > forw->val){
                index.push_back(count);
            }
            else if(temp->val < prev->val && temp->val < forw->val){
                index.push_back(count);
            }

            prev = temp;
            temp = forw;
            forw = forw->next;
        }

        if(index.size() >= 2){
        int max = index[index.size()-1] - index[0];
        int mini = INT_MAX;
        for(int i = 0; i < index.size()-1; i++){
            cout<<endl<<index[i]-index[i+1]<<endl;
            mini = min(abs(index[i]-index[i+1]), mini);
        }
        return {mini, max};
        }

        else{
            return{-1,-1};
        }

    }
};
