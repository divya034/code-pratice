#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void nextSmaller(vector<int> &v) {
    stack<int> s;
    vector<int> ans(v.size());  // Vector to store indices of next smaller elements

    for (int i = v.size() - 1; i >= 0; i--) {
        // Pop elements from the stack while they are greater than or equal to the current element
        while (!s.empty() && v[s.top()] >= v[i]) {
            s.pop();
        }
        
        // If the stack is not empty, the top element is the index of the next smaller element
        if (!s.empty()) {
            ans[i] = s.top();
        } else {
            ans[i] = -1;  // No smaller element found
        }
        
        // Push the current index onto the stack
        s.push(i);
    }
    
    // Print the indices of the next smaller elements
    for (auto index : ans) {
        cout << index << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v{5, 4, 3, 2, 1};
    
    nextSmaller(v);

    return 0;
}
