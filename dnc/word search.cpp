class Solution {
public:

bool solve(vector<vector<char>>& b, string w, int r, int c, int i){

       if(i == w.size()){
        return true;
       }

       if(r<0 || r>=b.size() || c<0 || c>= b[0].size() || b[r][c] != w[i]){
        return false;
       }

       char t = b[r][c];
    //    visit
        b[r][c] = '%';
       bool found = solve(b, w, r+1, c, i+1) || solve(b, w, r-1, c, i+1) || solve(b, w, r, c+1, i+1) 
       || solve(b, w, r, c-1, i+1);



        // unvisit
         b[r][c] = t;

         return found;

}
    bool exist(vector<vector<char>>& b, string w) {
        for(int i = 0; i<b.size(); i++){

            for(int j = 0; j<b[0].size(); j++){
                if(solve(b, w, i, j, 0)){
                    return true;
                }
            }
        } 

        return false;

    }
};
