Time Complexity:
Insert: 
O(N×L) for inserting all words.

Count Words Equal To: 
O(L) for a single query.

Count Words Starting With: 
O(L) for a single query.

Erase: 
O(L) for erasing a single word.

Space Complexity: 
O(N×L) in the worst case for storing all Trie nodes, assuming no shared prefixes.

#include <bits/stdc++.h> 

struct Node{
    Node* links[26];
    int count_words;
    int count_prefix;

    bool containsKey(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }
};
class Trie{
    private:
    Node* root;

    public:

    Trie(){
        root = new Node();
        root->count_words = 0;
        root->count_prefix = 0;
    }

    void insert(string &word){
        Node* node = root;
        for(int i = 0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
            node->count_prefix++;
        }
        
        node->count_words++;
    }

    int countWordsEqualTo(string &word){
        Node* node = root;

        for(int i = 0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }

            node = node->get(word[i]);
        }

        return node->count_words;
    }

    int countWordsStartingWith(string &word){
        Node* node = root;

        for(int i = 0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }

            node = node->get(word[i]);
        }

        return node->count_prefix;
    }

    void erase(string &word){
        Node* node = root;

        for(int i = 0; i<word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->count_prefix--;
            }
            else{
                return;
            }
        }

        node->count_words--;
    }
};
