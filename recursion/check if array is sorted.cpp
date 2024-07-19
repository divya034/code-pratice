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
    
    if(n == 1){
        return true;
    }
    
    if(arr[i] < arr[i+1]){
        return check(arr,n,i+1);
        // cout<<"index"<<i<<" "<<i+1<<endl;
    }
    else{
        return false;
    }

}

int main()
{
    int arr[] = {1,2,3,11,2};
    bool sorted = false;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<check(arr,n,0);

    return 0;
}
