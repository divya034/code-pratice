/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    // int  = 7;
    double ans = floor(sqrt(54));
    double factor = 1;
    double finalans = ans;
    for(int i = 0; i<3; i++){
        factor = factor/10;
        
        for(int j = 0; j<=9; j++){

            double newans = factor*j + ans;
            cout<<"newans "<<newans<<endl;
            if(newans * newans <= 54){
                finalans = newans;
                 cout<<"finalans "<<finalans<<endl;
            }
            else{
                break;
            }
        }
    }
    
    cout<<finalans;

    return 0;
}
