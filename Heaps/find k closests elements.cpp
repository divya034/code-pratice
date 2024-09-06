
using max heap:
TC:
for n elements, this results in O(n log k) time to build the heap
Sorting the final result of k elements takes O(k log k).
= O(n log k)

SC:
he heap stores at most k elements, which takes O(k) space.
he result vector stores k elements, which takes O(k) space.


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;

        for(int i = 0; i<arr.size(); i++){
            pq.push({abs(arr[i] - x), arr[i]});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;

        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

without popping size willl be nlogk
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;

        for(int i = 0; i<arr.size(); i++){
            pq.push({abs(arr[i] - x), arr[i]});
        }

        while(pq.size() > k){
            pq.pop();
        }

        vector<int> ans;

        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(ans.begin(), ans.end());

        return ans;
    }
};


using minheap:


class Solution {
public:
    class comparator{
        public:
        bool operator()(pair<int,int> a, pair<int,int> b){
            if(a.second == b.second){
                return a.first > b.first;
            }
            return a.second > b.second;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, comparator> pq;

        for(int i = 0; i<arr.size(); i++){
            pq.push({arr[i], abs(arr[i] - x)});
        }

        vector<int> ans;

        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
