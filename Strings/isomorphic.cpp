class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_to_t; // Map from characters in s to characters in t
        unordered_map<char, char> t_to_s; // Map from characters in t to characters in s
        
        for (int i = 0; i < s.size(); ++i) {
            char cs = s[i];
            char ct = t[i];
            
            // Check mapping s to t
            if (s_to_t.find(cs) == s_to_t.end()) {
                s_to_t[cs] = ct;
            } else {
                if (s_to_t[cs] != ct) {
                    return false; // Mapping inconsistency
                }
            }
            
            // Check mapping t to s
            if (t_to_s.find(ct) == t_to_s.end()) {
                t_to_s[ct] = cs;
            } else {
                if (t_to_s[ct] != cs) {
                    return false; // Mapping inconsistency
                }
            }
        }
        
        return true; // If mappings are consistent, they are isomorphic
    }
};
