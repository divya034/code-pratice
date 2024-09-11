class Solution{
    public:
    void heapify(vector<int> &c, int i, int n){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int swapindex = i;
        
        // Correct comparison of left and right children with the parent
        if(left < n && c[left] > c[swapindex]){
            swapindex = left;
        }
        if(right < n && c[right] > c[swapindex]){
            swapindex = right;
        }

        // If the current node is already in the correct position, no need to swap
        if(swapindex != i) {
            swap(c[i], c[swapindex]);
            heapify(c, swapindex, n);  // Recursively heapify the affected subtree
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // Merge both heaps into one vector
        vector<int> c(a.begin(), a.end());
        c.insert(c.end(), b.begin(), b.end());
        
        // Start heapifying from the last non-leaf node
        for(int i = (c.size() / 2) - 1; i >= 0; i--){
            heapify(c, i, c.size());
        }
        
        return c;
    }
};
