Time Complexity: 
O(n)
Space Complexity: 
h is the height of the tree. For a balanced tree, this is 
O(logn), and for a skewed tree, this is 
O(n).

//  mistake pass index as REFERENCE
void build(int arr[], int &index, int minr, int maxr, int n1) {
    // Base case: if index is out of bounds or the element is not in the valid range
    if (index >= n1 || arr[index] < minr || arr[index] > maxr) {
        return;
    }

    // Current element is valid, proceed to process
    int ele = arr[index++];
    
    // Build left subtree with updated range
    build(arr, index, minr, ele, n1);
    // Build right subtree with updated range
    build(arr, index, ele, maxr, n1);
}

// Main function to solve the problem
int solve(int* A, int n1) {
    int index = 0;
    int minr = INT_MIN;
    int maxr = INT_MAX;
    int n1 = sizeof(arr) / sizeof(arr[0]);
    build(A, index, minr, maxr, n1);
    
    // Check if the entire array was processed
    if (index == n1) {
        return 1;
    } else {
        return 0;
    }
}

// Example usage
int main() {
    int arr[] = {10, 5, 1, 7, 40, 50};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    
    cout << solve(arr, n1) << endl; // Output: 1 (valid BST preorder traversal)
    return 0;
}
