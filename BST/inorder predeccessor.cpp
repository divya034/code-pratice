https://workat.tech/problem-solving/practice/inorder-predecessor-bst
The time complexity of the findPredecessor function is O(h), where h is the height of the binary tree.
In the worst case, h could be the height of the tree, which
is O(log N) for a balanced binary search tree (BST) or O(N) for a completely unbalanced BST (like a linked list)

Node* findPredecessor(Node* root, Node* p) {
    Node* curr = root;
	Node* pre = NULL;
	
	while(curr != NULL){
		if(curr->data < p->data){
			pre = curr;
			curr = curr->right;
		}
		else{
			curr = curr->left;
		}
	}
	
	return pre;
}
