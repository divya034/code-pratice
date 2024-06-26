#include <iostream>
#include <string>
#include <map>
#include <climits>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        // Create a map to count the frequency of each character
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        
        // Find the character with the highest frequency
        int max_count = INT_MIN;
        char max_char;
        for (auto i : mp) {
            if (i.second > max_count) {
                max_count = i.second;
                max_char = i.first;
            }
        }
        
        // If the highest frequency is more than half the length of the string plus one, return ""
        if (max_count > (s.size() + 1) / 2) {
            return "";
        }
        
        // Create a string to store the result, initialized with spaces
        string ans(s.size(), ' ');

        // Place the most frequent character at even indices
        int index = 0;
        while (max_count > 0) {
            ans[index] = max_char;
            max_count--;
            index += 2;
        }

        // Remove the placed character from the map
        mp.erase(max_char);

        // Place the remaining characters
        for (auto i : mp) {
            while (i.second > 0) {
                // If we reach the end of the string, start placing characters at odd indices
                if (index >= s.size()) {
                    index = 1;
                }
                ans[index] = i.first;
                index += 2;
                i.second--;
            }
        }
        
        return ans;
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

