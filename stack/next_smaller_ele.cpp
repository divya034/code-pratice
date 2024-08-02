#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void nextSmaller(vector<int> &v) {
    stack<int> s;
    vector<int> ans(v.size());  // Vector to store values of next smaller elements

    for (int i = v.size() - 1; i >=0; i--) {
        // Pop elements from the stack while they are greater than or equal to the current element
        while (!s.empty() && s.top() > v[i]) {
            s.pop();
        }
        
        // If the stack is not empty, the top element is the next smaller element
        if (!s.empty()) {
            ans[i] = s.top();
        } else {
            ans[i] = -1;  // No smaller element found
        }
        
        // Push the current element onto the stack
        s.push(v[i]);
    }
    
    // Print the values of the next smaller elements
    for (auto val : ans) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v{5, 7, 8, 21, 1, 2};
    
    nextSmaller(v);

    return 0;
}
