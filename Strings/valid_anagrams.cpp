class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char,int> mp;
        unordered_map<char,int> mp2;

        for(int i = 0; i<s.size(); i++){
            mp[s[i]]++;
        }

        for(int i = 0; i<t.size(); i++){
            mp2[t[i]]++;
        }

        return mp == mp2;
    }
};
