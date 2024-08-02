
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void findsmaller(vector<int> &v){
    stack<int> s;
    s.push(-1);
    vector<int> ans;
    
    for(int i = 0; i<v.size(); i++){
        
        while(!s.empty() && s.top() >= v[i]){
            s.pop();
        }
        
        ans.push_back(s.top());
        s.push(v[i]);
    }
    
    // reverse(ans.begin(), ans.end());
    for(auto i : ans){
        cout<<i<<" ";
    }
}

int main()
{
    stack<int> s;
    
    vector<int> v{12,1,21,21,1,1,2};
    
    findsmaller(v);

    return 0;
}
