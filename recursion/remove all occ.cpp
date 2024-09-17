In the worst case, the function will remove one occurrence of part in each recursive call. After removing part, the size of the string decreases by m. So, there will be approximately O(n/m) recursive calls.

Since there are O(n/m) recursive calls, and each call involves O(n) operations, the overall time complexity can be expressed as
O(n^2/m)

Space Complexity: O(n) due to recursion stack depth and memory usage for string copies

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


ITERATIVE
TC is same n/m * n to find pos
class Solution {
public:

    string removeOccurrences(string s, string part) {
         
      int pos = s.find(part);

      while(pos != -1){
        s.erase(pos, part.size());
        pos = s.find(part);
      }

      return s;
    }
};
