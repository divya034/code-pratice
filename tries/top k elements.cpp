#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Trie {
private:
    unordered_map<string, int> wordFreq;  // Use a map to store word frequencies
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

public:
    void insert(string word) {
        wordFreq[word]++;
    }

    vector<string> getFreq(int k) {
        for (const auto& entry : wordFreq) {
            pq.push({entry.second, entry.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());  // Reverse to get descending order
        return ans;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        Trie trie;

        for (const auto& word : words) {
            trie.insert(word);
        }

        return trie.getFreq(k);
    }
};
