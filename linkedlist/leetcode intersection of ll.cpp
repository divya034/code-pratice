o(1) space:

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while(t1 != t2){
            if(t1 == nullptr){
                t1 = headB;
            }
            else{
                t1 = t1->next;
            }
            if(t2 == nullptr){
                t2 = headA;
            }
            else{
                t2 = t2->next;
            }
        }


        return t2;
    }
};


o(m)

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		unordered_map<ListNode*, int> m;
		while(headA != NULL){
			m[headA]++;
			headA = headA -> next;
		}
		while(headB != NULL){
			if(m[headB] > 0){
				return headB;
			}
			headB = headB -> next;
		}
		return NULL;
	}
};
