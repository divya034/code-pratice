#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void prevGreater(vector<int> &v) {
    stack<int> s;
    vector<int> ans;  // Vector to store indices of previous greater elements

    for (int i = 0; i < v.size(); i++) {
        // Pop elements from the stack while they are less than or equal to the current element
        while (!s.empty() && v[s.top()] <= v[i]) {
            s.pop();
        }
        
        // If the stack is not empty, the top element is the index of the previous greater element
        if (!s.empty()) {
            ans.push_back(s.top());
        } else {
            ans.push_back(-1);  // No greater element found
        }
        
        // Push the current index onto the stack
        s.push(i);
    }
    
    // Print the indices of the previous greater elements
    for (auto index : ans) {
        cout << index << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v{5, 4, 3, 2, 1};
    
    prevGreater(v);

    return 0;
}
