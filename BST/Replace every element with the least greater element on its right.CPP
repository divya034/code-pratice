TC:
Insertion in BST:Each insertion into the BST has a time complexity of 
O(h), where 
h is the height of the tree.
n the worst case, the BST can become a skewed tree (like a linked list)

Processing Each Element:
You process each element in the array once. For each element, you perform an insertion into the BST and find its successor.

O(N^2)

SC:
Space for BST Nodes:
You need space for the BST nodes, which is 
O(n), where 
n is the number of elements in the input array.
Replace every element with the least greater element on its right
Auxiliary Space: RECURSION STACK SPACE: O(N) OR O(H)
Additional Space: Result vector : o(N)


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    Node* insert(Node* root, int val, int &succ) {
        if (root == nullptr) {
            return new Node(val);
        }

        if (val >= root->data) {
            root->right = insert(root->right, val, succ);
        } else {
            succ = root->data; 
            root->left = insert(root->left, val, succ);
        }

        return root;
    }

    vector<int> replaceElements(vector<int>& arr) {
        Node* root = nullptr;
        vector<int> result(arr.size(), -1);

        for (int i = arr.size() - 1; i >= 0; --i) {
            int succ = -1;
            root = insert(root, arr[i], succ); // Update the tree and find the successor
            result[i] = succ; // Store the successor for current element
        }

        return result;
    }
};
