/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

bool check(int arr[],int n, int i){
    if(i == n){
        return true;
    }
    
    if(arr[i] < arr[i+1]){
        check(arr,n,i+1);
    }
    else{
        return false;
    }
    
    return true;
}

int main()
{
    int arr[] = {1,2,3};
    bool sorted = false;
    int n = 4;
    cout<<check(arr, 4,0);

    return 0;
}
