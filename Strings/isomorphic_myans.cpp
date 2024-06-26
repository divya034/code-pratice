class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int map_string[256] = {0};
        int taken[256] = {0};
        
        // perform mapping for all elements in s to elements in t
        // and mapping t to s to check if t element is taken
        for(int i = 0; i < s.size(); i++){
            if(map_string[s[i]] == 0 && taken[t[i]] == 0){
            map_string[s[i]] = t[i];
            taken[t[i]] = 1;
            }
            //present s is not mapped to present t, that means s mapping was taken by something else
            if(map_string[s[i]] != t[i]){
                return false;
            }
            //t is taken
            else if(map_string[s[i]] == 0){
               return false;
            }
        }

        // // check if all the elements are mapped to corresponding element
        // for(int i = 0; i < s.size(); i++){
        //     if(map_string[s[i]] != t[i]){
        //         return false;
        //     }
        // }


        return true;


    }
};
