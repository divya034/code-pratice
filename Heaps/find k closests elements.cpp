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
