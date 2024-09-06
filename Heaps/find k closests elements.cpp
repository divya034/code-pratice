
using max heap:
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
