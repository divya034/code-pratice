class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
          

        // int first = strs[0]; // first string
        string ans;
        for(int i = 0; i < strs[0].size(); i++){ //EACH character colum
        // each string in rows
            for(int j = 1; j < strs.size(); j++){ // finish row wise first
                if(strs[j][i] != strs[0][i]){
                    return ans;
                }
            }
            ans += strs[0][i];
        }

        return ans;


    }
        

};
