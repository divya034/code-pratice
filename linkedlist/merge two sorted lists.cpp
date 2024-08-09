/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void add(ListNode* &temp, ListNode* &addnode){
         ListNode* forw = addnode->next;
         addnode->next = NULL;

         temp->next = addnode;
         temp = temp->next;

         addnode = forw;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // ListNode dummy(0);
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;

        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                add(temp, l1);
            }
            else if(l1->val > l2->val){
                add(temp, l2);
            }
            else{
                add(temp, l1);
                add(temp, l2);
            }
        } 

        if(l1){
            temp->next = l1;
        }
        else if(l2){
            temp->next = l2;
        }  

        return head->next;   
    }
};
