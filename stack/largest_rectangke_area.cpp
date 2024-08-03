class Solution {
public:
    vector<int> nextsmallest(vector<int>& h){
        stack<int> s;
        vector<int> ans(h.size());

        for(int i = h.size() - 1; i >= 0; i--){

            while(!s.empty() && h[s.top()] >= h[i]){
                s.pop();
            }

            if(s.empty()){
             ans[i] = -1;
            }
            else{
                ans[i] = s.top();
            }

            s.push(i);
        }

        return ans;
    }

    vector<int> prevsmallest(vector<int>& h){
        stack<int> s;
        vector<int> ans(h.size());

        for(int i = 0; i < h.size(); i++){

            while(!s.empty() && h[s.top()] >= h[i]){
                s.pop();
            }

            if(s.empty()){
             ans[i] = -1;
            }
            else{
                ans[i] = s.top();
            }

            s.push(i);
        }

        return ans;
    }


    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = nextsmallest(heights);

        vector<int> prev = prevsmallest(heights);

        for(int i = 0; i<next.size(); i++){
            if(next[i] == -1){
                next[i] = next.size();
            }
        }
         
        int area = INT_MIN;
        for(int i = 0; i<heights.size(); i++){
            int width = next[i] - prev[i] - 1;

            int length = heights[i];

            area = max(area, width*length);
        }

        for(auto i : next){
            cout<<i<<" ";
        }
        cout<<endl;

        
        for(auto i : prev){
            cout<<i<<" ";
        }
      return area;
    }
};
