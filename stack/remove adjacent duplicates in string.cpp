// class Solution {
// public:
//     string removeDuplicates(string s) {
         
//         int i =0;
//             int st= s.length()-2;
//             while(i<=st){
   
//                 if (s[i]==s[i+1]){

//                     s.erase(i,2);

//                     if (i!= 0){
//                         i=i-1;
//                     }

//                 }
//                 else{

//                     i++;
//                     }
//             }

        
//             return s;
        
//     }
// };

class Solution {
public:
    string removeDuplicates(string s) {
         
       stack<char> st;
      // O(N) 
       for(int i = 0; i<s.size(); i++){
         if(!st.empty() && st.top() == s[i]){
            st.pop();
         }
         else{
            st.push(s[i]);
         }
       } 
 
      string ans;
    // put from stack to new string O(n)
       while(!st.empty()){
        char ch = st.top();
        ans = ans + ch;
        st.pop();
       }       

    reverse(ans.begin(), ans.end());
       return ans;
    }

};
