
#include <iostream>
using namespace std;

void sorting(int arr[], int n){
    for(int i = 0; i < n; i++){
        int mini = i;
        for(int j = i; j < n; j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        
        swap(arr[i], arr[mini]);
    }
}

int main()
{
    int arr[] = {1,22,1,11,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    sorting(arr, n);
    
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
