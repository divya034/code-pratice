TC: O(nlogk) + O(k log k) = nlogk
So, for each of the num elements, inserting into or popping from the heap takes O(log k) time.

SC: 
Result Vector (ans): This stores the final result and requires O(num) space, but it’s technically part of the output, not the extra working memory used during computation.
The min-heap (O(k)) is considered auxiliary space, as it is the temporary space used during the execution of the algorithm to aid in sorting the array
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        for(int i = 0; i<num; i++){
            min_heap.push(arr[i]);
            
            if(min_heap.size() > K){
                ans.push_back(min_heap.top());
                
                min_heap.pop();
            }
        }
        
        
        while(min_heap.size()){
            ans.push_back(min_heap.top());
            min_heap.pop();
        }
        
        return ans;
    }
};
