HACKERRAANK
Recursive:
void findLength(SinglyLinkedListNode* head, int &pos, int &ans, int &index){
    if(head == NULL){
        return;
    }
    
    int value = head->data;
    head = head->next;
    
    findLength(head, pos, ans, index);
    
    if(index == pos){
        ans = value;
    }
    
    index++;
    
    return;
}

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
     
     int ans = -1;
     int index = 0;
     findLength(llist, positionFromTail, ans, index);
     
     return ans;
}


Iterative
int findLength(SinglyLinkedListNode* llist){
    SinglyLinkedListNode* temp = llist;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    
    return count;
}

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
     int n = findLength(llist);
     int nodeLocation = n - positionFromTail;
     SinglyLinkedListNode* temp = llist;
     
    if (positionFromTail >= n) {
        return -1;  // Or some error code depending on your requirements
    }

     for(int i = 0; i<nodeLocation - 1; i++){
         if(temp == NULL){
             break;
         }
         temp = temp->next;
     }
     
     
     return temp->data;
}
