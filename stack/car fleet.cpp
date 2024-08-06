CORRECT
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> v;
        int n = position.size();

        // Calculate the time to reach the target for each car
        for (int i = 0; i < n; i++) {
            double t = double(target - position[i]) / double(speed[i]);
            v.push_back({position[i], t});
        }
        
        // Sort cars based on their positions
        sort(v.begin(), v.end());
        
        stack<double> s;

        for (int i = 0; i < n; i++) {
            // While the stack is not empty and the current car's time is greater than
            // the time at the top of the stack, pop the stack
            while (!s.empty() && v[i].second >= s.top()) {
                s.pop();
            }
            // Push the current car's time onto the stack
            s.push(v[i].second);
        }
        
        // The size of the stack represents the number of car fleets
        return s.size();
    }
};




WRONG:
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
 vector<pair<int, double>> v;
        int n = position.size();

        for (int i = 0; i < n; i++) {
            double t = double(target - position[i]) / double(speed[i]);
            v.push_back({position[i], t});
        }
        
        // Sort cars based on their positions
        sort(v.begin(), v.end());
        
        int ans = 0;
        double mxTime = 0;

        stack<int> s;

        for(int i = 0; i<n; i++){
            // if prev inserted is less than present
            // or if present time is greater than prev time- prev reaches faster
            if(!s.empty() && v[i].second > s.top()){
                s.pop(); 
                // replace smaller pos which is faster
            }
            // put the greater pos which is slower
            s.push(v[i].second);
        }
        
        return s.size();
         
    }
};





