
Time Complexity (TC): O(n)
Space Complexity (SC): O(1)
class Solution {
public:
    void removeNode(ListNode* &temp, ListNode* &evenitr){
        // evenitr gets a new node
        evenitr->next = temp;
        evenitr = evenitr->next;

        // make individual node point to end
        temp->next = NULL;
    }

    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return head;
        }
        
        ListNode* even = new ListNode(0);
        ListNode* evenitr = even;

        ListNode* temp = head;
        ListNode* last = NULL;
        ListNode* prev = NULL;
        int index = 1;

        while(temp != NULL){
            if(index % 2 != 0){
                prev = temp;
                // mistake wrote prev after temp = temp->n
                temp = temp->next;
                index++;
            }
            else{
                ListNode* forw = temp->next;
                // BIG MISTAKE, need to connect prev LL to forw
                if(prev != nullptr) prev->next = forw;
                removeNode(temp, evenitr);
                temp = forw;
                index++;
            }
        }
      
      prev->next = even->next;
    //   even->next = NULL;
      delete even;
    //   delete placeholder

      return head;
        
    }
};
