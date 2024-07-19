/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

bool ispalin(string s, int i, int j){
    if(i >= j){
        return true;
    }
    
    if(s[i] == s[j]){
        return ispalin(s, i+1, j-1);
    }
    else{
        return false;
    }
}

int main()
{
    string s = "pom";
    
    cout<<ispalin(s, 0, s.size() - 1);

    return 0;
}
