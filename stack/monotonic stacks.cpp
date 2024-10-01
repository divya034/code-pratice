/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void nextGreater(vector<int> &arr){
    stack<int> s;
    vector<int> ans(arr.size(), -1);
    
    for(int i = 0; i<arr.size(); i++){
        // is the coming element greater than all prev elements? 
        // coming element is the ans for all smaller ele in stack
        while(!s.empty() && arr[s.top()] < arr[i]){
            int ind = s.top();
            
            ans[ind] = arr[i];
            
            s.pop();
        }
        
        s.push(i);
    }
    
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<"nextGreater"<<endl;
    
}

void prevGreater(vector<int> &arr){
    vector<int> ans(arr.size(), -1);
    stack<int> s;
    
    for(int i = 0; i<arr.size(); i++){
        // if on the top we have smaller anyway it wont be ans so pop
        // till we find something greater and maintain it as ans for now
      // Discarding the values, which wont be ans
        while(!s.empty() && arr[s.top()] <= arr[i]){
            s.pop();
            // pop all prev smaller
        }
        
        if(!s.empty()){
            ans[i] = arr[s.top()];
        }
        
        s.push(i);
    }
    
    
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<"prevGreater"<<endl;
}

void nextSmaller(vector<int> arr){
    vector<int> ans(arr.size(), -1);
    stack<int> s;
    
    
    for(int i = 0; i<arr.size(); i++){
        
        while(!s.empty() && arr[s.top()] > arr[i]){
            int index = s.top();
            
            ans[index] = arr[i];
            
            s.pop();
        }
        
        s.push(i);
    }
    
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<"nextsmall"<<endl;
}

void prevSmaller(vector<int> arr){
    stack<int> s;
    vector<int> ans(arr.size(), -1);
    
    for(int i = 0; i<arr.size(); i++){
        // Discarding the values, which wont be ans---any prev element smaller pop
        while(!s.empty() && arr[s.top()] >= arr[i]){
            s.pop();
        }
        
        // cant do arr[s.top()] > arr[] store ans becuase just
        if(!s.empty()){
            ans[i] = arr[s.top()];
        }
        
        s.push(i);
        
    }
    
    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<"prevsmall"<<endl;
}

int main()
{
    vector<int> arr{12,3,22,2,33,3};
    
    nextGreater(arr);
    prevGreater(arr);
    nextSmaller(arr);
    prevSmaller(arr);

    return 0;
}
