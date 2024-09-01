Time Complexity: 
O(n)
Space Complexity: 
h is the height of the tree. For a balanced tree, this is 
O(logn), and for a skewed tree, this is 
O(n).

//  mistake pass index as REFERENCE
void build(int arr[], int &index, int minr, int maxr, int n1){
    if(index >= n1 || arr[index] < min || arr[index] > max){
        return;
    }
    
    int ele = arr[index];
    index++;
    
    build(arr, index, minr, ele);
    build(arr, index, ele, maxr);
}
int solve(int* A, int n1) {
    int index = 0;
    int minr = INT_MIN;
    int maxr = INT_MAX;
    int n1 = sizeof(arr) / sizeof(arr[0]);
    build(A, index, minr, maxr, n1);
    
   return index == n1;
}
