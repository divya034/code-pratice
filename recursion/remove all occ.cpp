class Solution {
public:

    string removeOccurrences(string s, string part) {
         
      int size = s.find(part);

      if(size != -1){
        s.erase(size, part.size());
        return removeOccurrences(s, part);
      }


      return s;
    }
};
