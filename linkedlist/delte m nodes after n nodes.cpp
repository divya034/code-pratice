
BEST CODE:

class Solution {
public:
    void linkdelete(struct Node **head, int n, int m) {
        Node* temp = *head;  // Correctly dereference head to get the actual node

        while(temp != NULL) {
            // Skip m nodes
            for(int i = 0; i < m-1; i++) {
                if(temp == NULL) break;
                temp = temp->next;
            }

            if(temp == NULL) break;

            // Delete n nodes
            for(int j = 0; j < n; j++) {
                if(temp == NULL || temp->next == NULL) break;
                
                Node* del = temp->next;   // Node to delete
                temp->next = del->next;   // Bypass the node to delete
                delete del;               // Delete the node
            }

            // Move to the next node after deletion
            temp = temp->next;
        }
    }
};



class Solution {
public:
    void linkdelete(struct Node **head, int n, int m) {
        Node** temp = head;

        while (*temp != NULL) {
            // Skip m nodes
            for(int i = 0; i < m-1; i++) {
                if(*temp == NULL) break;
                temp = &(*temp)->next;
            }

            if (*temp == NULL) {
                break;
            }

            // Delete n nodes
            for(int i = 0; i < n; i++) {
                if(*temp == NULL || (*temp)->next == NULL) break;
                // del of next = temp->next->next
                Node* del = (*temp)->next;  // Get the node to delete
                (*temp)->next = del->next;  // Bypass the node to delete
                delete del;                 // Delete the node
            }

            temp = &(*temp)->next; 
        }
    }
};



class Solution {
public:
    void linkdelete(struct Node **head, int n, int m) {
        Node** temp = head;
        int x = n;
        int y = m;

        while (*temp != NULL) {  // Dereference temp to get the actual Node pointer
            m = y;
            n = x;

            // Skip m nodes
            while (m > 1 && *temp != NULL) {
                temp = &(*temp)->next;  // Use &(*temp)->next to update temp
                m--;
            }

            if (*temp == NULL) {
                break;
            }

            // Delete n nodes
            while (n > 0 && (*temp)->next != NULL) {
                Node* del = (*temp)->next;  // Get the node to delete
                (*temp)->next = del->next;  // Bypass the node to delete
                delete del;                 // Delete the node
                n--;
            }
            
            temp = &(*temp)->next; 
        }
    }
};
