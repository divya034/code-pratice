https://workat.tech/problem-solving/practice/inorder-predecessor-bst
TC:
SC:

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
