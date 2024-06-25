class Solution {
public:
    string reverseOnlyLetters(string s) {

     int l = 0;
     int h = s.size() - 1;

     while(l < h){
        if( isalpha(s[l]) && isalpha(s[h])){
            swap(s[l], s[h]);
            l++;
            h--;
        }
        // isalpha doesnt return a 1 or 0, it returns 1 or 
        else if(isalpha(s[l]) != 0){
            h--;
        }
        else{
            l++;
        }
     }

     return s;

    }

};
