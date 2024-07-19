class Solution {
public:
   void reversestr(vector<char>&s, int i, int j){
    if(i >= j){
        return;
    }

    swap(s[i], s[j]);
    i++; j--;

    reversestr(s,i,j);

   }

    void reverseString(vector<char>& s) {
        
        int j = s.size() - 1;
        int i = 0;
        reversestr(s, i, j);
        // int l = 0;
        // int h = s.size() - 1;

        // while(l <= h){
        //     swap(s[l], s[h]);
        //     l++;
        //     h--;
        // }

        // reverse(s.begin(), s.end());
    }
};
