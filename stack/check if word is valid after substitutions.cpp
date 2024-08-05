class Solution {
public:
    bool isValid(string str) {
        stack<char> s;

        for(auto i : str){
            if(i == 'c'){
                // find abc pattern
                // if there is no ab in stack
                if(s.empty()) return false;

                if(s.top() == 'b'){
                    s.pop();
                }
                else{
                    return false;
                }

// mistake didnt write s.empty()
                if(s.empty() || s.top() != 'a'){
                    return false;
                }
                else{
                    s.pop();
                }
            }

            else{
                s.push(i);
            }
        }

        if(s.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};



USING STR MANIPULATION

class Solution {
public:
    bool isValid(string str) {

        if(str.size() == 0){
            return true;
        }
        int found = str.find("abc");

        if(found != string::npos){
            string left = str.substr(0,found);

            string right = str.substr(found + 3, str.size());
            
            return isValid(left + right);
        }

        return false;
    }
};
