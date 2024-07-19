/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int check(string s, int n, char ch, int i, int &ans){

    if(i == n){
        return ans;
    }
    
    if(s[i] == ch){
        ans = i;
    }
    
    check(s,n,ch,i+1,ans);
    
    return ans;

}

int main()
{
    string s = "divyaaaa";
    int n = s.size();
    char ch = 'a';
    int ans = -1;
    cout<<check(s,n,ch,0,ans);
    
    return 0;
}
