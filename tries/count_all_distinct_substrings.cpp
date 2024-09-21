struct Node{
    Node* links[26];
    
    bool containskey(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node; 
        // new empty ref node
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }
};

class Trie{
    private:
    Node* root;
    int count;

    public:
    Trie(){
        root = new Node();
        count = 0;
    }

    void insertAndCount(string word, int start){
        Node* node = root;

        for(int i = start; i<word.size(); i++){
            if(!node->containskey(word[i])){
                 node->put(word[i], new Node());
                 count++;
            }
            
            node = node->get(word[i]);
        }
    }

    int getCount(){
        return count;
    }
};
int countDistinctSubstrings(string &s)
{
    Trie trie;
    // Insert all suffixes of the string into the Trie
    for (int i = 0; i < s.size(); i++) {
        trie.insertAndCount(s, i);
    }

    // Add 1 to count the empty string as a distinct substring
    return trie.getCount() + 1;
    
}
