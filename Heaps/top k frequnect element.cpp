TC:
build a map - n
push into the heap - nlogk
build ans - k
overal nlogk

SC:
min heap size of max k --k
ans vector-- k
O(k)
(min heap is enptied in the end) that is why MIN heap, with ans at bottom
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;

        for(auto i:nums){
            m[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto i : m){
            pq.push({i.second, i.first});

            if(pq.size() > k){
                pq.pop();
            }
        }


        vector<int> ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};
