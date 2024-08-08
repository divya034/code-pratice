class Solution {
public:
    string simplifyPath(string path) {
        string current;
        int i = 0;
        int n = path.size();
        stack<string> s;

        while(i < path.size()){
            int start = i;
            int end = i + 1;
            cout<<"at "<<start<<" "<<end<<endl;

            while(end <= n - 1 && path[end] != '/'){
                end++;
            }
            
            current = path.substr(start, end - start);
            cout<<current<<endl;
            i = end;

            if(current == "/.."){
                if(!s.empty())
                s.pop();
            }
            else if(current == "/." || current == "/"){
                continue;
            }
            else{
                s.push(current);
            }


        }
        
// or use a new ANS STRING
        current = !s.empty() ? "" : "/";

        while(!s.empty()){
            current = s.top() + current;
            s.pop();
        }

        return current;
    }
};
