#include <bits/stdc++.h>
using namespace std;

void printsub(vector<int>&v, int i){
    if(i == v.size()){
        return;
    }
    
    vector<int> ans;
    for(int j = i; j <v.size(); j++){
        ans.push_back(v[j]);
        
        for(auto x: ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }
        
        printsub(v, i+1);

}

int main()
{
    vector<int> v{1,2,3,12};
    
    printsub(v, 0);

    return 0;
}
