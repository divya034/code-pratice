#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        // Step 1: Count the frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Create a max-heap based on the character frequency
        priority_queue<pair<int, char>> maxHeap;
        for (const auto& entry : freq) {
            maxHeap.push({entry.second, entry.first});
        }

        // Step 3: Rebuild the string
        string result = "";
        pair<int, char> prev = {-1, '#'};

        while (!maxHeap.empty()) {
            auto current = maxHeap.top();
            maxHeap.pop();
            result += current.second;

            // Decrease the frequency and add the previous character back to the heap if it still has remaining count
            if (prev.first > 0) {
                maxHeap.push(prev);
            }

            current.first--;
            prev = current;
        }

        // If the length of the result is not equal to the original string, it's not possible to reorganize
        if (result.length() != s.length()) {
            return "";
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "aab";
    cout << sol.reorganizeString(s) << endl; // Output: "aba" or some other valid reorganization

    s = "aaab";
    cout << sol.reorganizeString(s) << endl; // Output: "" (not possible to reorganize)

    return 0;
}
