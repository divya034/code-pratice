class Solution {
public:
    string reorganizeString(string s) {
        
        // create mapping
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }
        
        // finding the largest character
        int max_count = INT_MIN;
        char max_char;
        for(auto i : mp){
            if(i.second > max_count){
                max_char = i.first;
                max_count = i.second;
            }
        }
          
        // placing the largest character
        int index = 0;
        // string s;f
        while(index < s.size() && max_count > 0){
              s[index] = max_char;
              max_count--;
              index += 2;
        }

        if(max_count != 0){
            return "";
        }

        mp[max_char] = 0;
        cout<<"index"<<index;

        for(auto i : mp){
            while(i.second > 0){
                index = index >= s.size() ? 1 : index;
                s[index] = i.first;
                index += 2;
                i.second--;
            }
        }
         
    return s;

    }
};
