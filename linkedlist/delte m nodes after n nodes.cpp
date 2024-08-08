*/
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
