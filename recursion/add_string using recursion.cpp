class Solution {
public:
    string addStrings(string num1, string num2) {
       int i = num1.size() - 1;
       int j = num2.size() - 1;

       int carry = 0;
       int pre_sum = 0;

       string ans;

       while(i >= 0 && j >= 0){
            int n1 = num1[i] - '0';
            int n2 = num2[j] - '0';

            pre_sum = n1 + n2 + carry;
            carry = pre_sum / 10;
            ans += to_string(pre_sum % 10);

            i--;
            j--;
       }

       while(i>=0){
        int n1 = num1[i] - '0';

        pre_sum = n1 + carry;
        carry = pre_sum / 10;
        ans += to_string(pre_sum % 10);
        i--;

       }

// mistake while(j)---we need valid index not true
     while(j>=0){
        // mistake while copying code i remained num2 as num1
        int n2 = num2[j] - '0';

        pre_sum = n2 + carry;
        carry = pre_sum / 10;
        ans += to_string(pre_sum % 10);
        j--;
       }


// mistake: forgot this condition
        if(carry > 0) {
           ans += to_string(carry);
       }
      
       reverse(ans.begin(), ans.end());
       return ans;
    }
};


ORRRRRRR

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += num1[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += num2[j] - '0';
                j--;
            }
            carry = sum / 10;
            result += to_string(sum % 10);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution solution;
    string num1 = "123";
    string num2 = "456";
    cout << solution.addStrings(num1, num2) << endl; // Output should be "579"
    return 0;
}

