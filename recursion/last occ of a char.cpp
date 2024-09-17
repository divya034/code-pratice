Righ to left:
#include <iostream>
using namespace std;

void check(string s, int n, char ch, int i, int &ans){

   if(i == -1){
       return;
   }
   
   if(s[i] == ch){
       ans = i;
       return;
   }
   
   check(s, n, ch, i-1, ans);

}

int main()
{
    string s = "divyaaaa";
    int ans = -1;
    char ch = 'a';
    check(s, s.size(), ch, s.size() - 1, ans);
    
    cout<<ans;
    
    
    return 0;
}


LEFT TO right:


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
