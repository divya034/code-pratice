class Solution {
    struct Node{
        Node* links[26];
        int count = 0;

        bool containsKey(char ch){
            return links[ch - 'a'];
        }

        void put(char ch, Node* node){
            links[ch - 'a'] = node;
        }

        Node* get(char ch){
            return links[ch - 'a'];
        }

        int getCount(){
            return count;
        }
    };

    class Trie{
        private:
            Node* root;

        public:

        Trie(){
            root = new Node();
        }

        void insertTrie(string word){
            Node* node = root;

            for(int i = 0; i<word.size(); i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i], new Node());
                }

                node = node->get(word[i]);
                node->count++;
            }
        }

        int prefixCount(Node* node,char ch){
            
            node = node->get(ch);
            return node->getCount();
        }
        
        Node* getRoot() {
            return root;
        }
    };
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;

        for(auto i : strs){
            trie.insertTrie(i);
        }

        string ans = "";
        Node* root = trie.getRoot();
        for(auto ch : strs[0]){
            if (trie.prefixCount(root, ch) < strs.size()) {
                return ans;
            }
            ans += ch;
            root = root->get(ch);
        }

        return ans;
    }
};
