int countRev (string s)
{   stack<char> st;
  int count = 0;
  
  
 if(s.size()%2 != 0){
      return -1;
  }
  
   
  for(int i = 0; i<s.size(); i++){
      if(s[i] == '{'){
          st.push(s[i]);
      }
      else if(s[i] == '}'){
        //   if balanced
          if(!st.empty() && st.top() == '{'){
              st.pop();
              continue;
          }
          
          st.push(s[i]);
      }
  }
   
       while(!st.empty()){
        char topele = st.top();
        st.pop();
        // mistake used int
        char curr = st.top();
        
        if(topele == curr){
            count += 1;
            st.pop();
        }
        else{
            count += 2;
            st.pop();
        }
        
    }
   
//   int n = st.size();
   

//   solve(st, n, 0, count);
// //   there are min two elements

    
    return count;
}
