
// NOT ALL TEST CASES ARE PASSING

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
       int r = mat.size();
       int c = mat[0].size();
       stack<pair<int,int>> st;
       
       int celebrity = -1;
       for(int i = 0; i<r; i++){
           int know = 0;
           for(int j = 0; j<c; j++){
              if(mat[i][j] == 1){
                  st.push({i,j});
                  know = 1;
              }
           }
           
           if(know == 0){
               celebrity = i;
           }
       }
       
    //   check if all know the same celebrity
    
       while(!st.empty()){
           int topele = st.top().second;
           st.pop();
           
           if(topele != celebrity){
               return -1;
           }
       }
       
       return celebrity;
    }
};



// STACKS

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int> >& m) {
        int total = m.size();
        stack<int> s;

        // Push all people into the stack
        for (int i = 0; i < total; i++) {
            s.push(i);
        }

        // Find the potential celebrity
        while (s.size() > 1) {
            int top1 = s.top();
            s.pop();
            int top2 = s.top();
            s.pop();

            // If top1 knows top2, then top1 cannot be a celebrity
            if (m[top1][top2] == 1) {
                s.push(top2);
            } 
            // top2
            else {
                s.push(top1);
            }
        }

        // If stack is empty, no celebriTY
      // MISTAKE DIDNT KNOW THIS
        if (s.empty()) {
            return -1;
        }

        // Potential celebrity
        int celeb = s.top();
        
        // Verify if this person is a celebrity
        // Celeb should not know anyone
        for (int i = 0; i < total; i++) {
            if (m[celeb][i] != 0) {
                return -1;
            }
        }
// MISTAKE DIDNT CHECK THIS
        // Everyone else should know celeb
        for (int i = 0; i < total; i++) {
            if (i != celeb && m[i][celeb] != 1) {
                return -1;
            }
        }

        return celeb;
    }
};

