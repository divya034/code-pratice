#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Sort the array based on the custom comparator
        sort(arr.begin(), arr.end(), [x](int a, int b) {
            if (abs(a - x) == abs(b - x))
                return a < b;
            return abs(a - x) < abs(b - x);
        });

        // Select the first k elements
        vector<int> result(arr.begin(), arr.begin() + k);

        // Sort the result to return in ascending order
        sort(result.begin(), result.end());

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;
    vector<int> result = sol.findClosestElements(arr, k, x);

    for(int num : result) {
        cout << num << " ";
    }
    return 0;
}
