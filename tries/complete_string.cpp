#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
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
        }

        void insertTrie(string word){
            Node* node = root;
            for(int i = 0; i<word.size(); i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i], new Node());
                }

                node = node->get(word[i]);
            }

            node->flag = true;
        }

        bool prefixExist(string word){
            Node* node = root;
            for(int i = 0; i<word.size(); i++){
                if(!node->containsKey(word[i])){
                    return false;
                }

                node = node->get(word[i]);
                if(node->flag == false) return false;
                // prefix needs to be present as a word
            }

            return true;
        }
};
string completeString(int n, vector<string> &a){
   
   Trie trie;

   for(auto i : a){
       trie.insertTrie(i);
    }
    string longest = "";

   for(auto it: a){
       if(trie.prefixExist(it)){
           if(it.size() > longest.size()){
               longest = it;
           }
           else if(it.size() == longest.size() && it < longest){
               longest = it;
           }
       }
   }

   if(longest == ""){
       return "None";
   }

    return longest;
}
