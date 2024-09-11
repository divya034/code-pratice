TC: O(n)*2 for traversing all elements, o(nlogk) to insert into max heap of size k
SC: O(K) for max heap of size k

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq; 
        // max heap
        for(auto i: points){
            // i is a vector
            int dist = i[0]*i[0] + i[1]*i[1];

            pq.push({dist,i});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);

            pq.pop();
        }

        return ans;
    }
};
