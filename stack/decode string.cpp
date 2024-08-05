tc and sc?

#include <stack>
#include <string>

class Solution {
public:
    string decodeString(string str) {
        stack<char> s;

        for(auto i : str){
            if(i == ']'){
                // Find the string to repeat
                string newString;
                while(!s.empty() && s.top() != '['){
                    newString = s.top() + newString;
                    s.pop();
                }
                
                // Pop the opening bracket '['
                s.pop();
                
                // Find the number of repetitions
                string numStr;
                while(!s.empty() && isdigit(s.top())){
                    numStr = s.top() + numStr;
                    s.pop();
                }
                
                int freq = stoi(numStr); // Convert string to integer
                
                // Repeat the string and push it back into the stack
                string repeatedString;
                while(freq--){
                    repeatedString += newString;
                }
                
                // Push the repeated string back into the stack
                for(auto j : repeatedString){
                    s.push(j);
                }
            }
            else {
                s.push(i);
            }
        }

        // Construct the final decoded string from stack
        string ans;
        while(!s.empty()){
            ans = s.top() + ans;
            s.pop();
        }

        return ans;
    }
};
