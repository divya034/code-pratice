#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26] = {nullptr};
    bool isEnd = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->isEnd = true;
    }

    string searchRoot(const string& word) {
        Node* node = root;
        string rootFound = "";
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                break;  // No matching root
            }
            node = node->get(ch);
            rootFound += ch;
            if (node->isEnd) {
                return rootFound;  // Found a root
            }
        }
        return "";  // No root found
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (const string& root : dictionary) {
            trie.insert(root);
        }

        string result;
        string currentWord = "";
        
        // Manually process each character in the sentence
        for (char ch : sentence) {
            if (ch == ' ') {
                if (!currentWord.empty()) {
                    string root = trie.searchRoot(currentWord);
                    result += (root.empty() ? currentWord : root) + " ";
                    currentWord = "";  // Reset for the next word
                }
            } else {
                currentWord += ch;  // Build the current word
            }
        }
        
        // Handle the last word if there is one
        if (!currentWord.empty()) {
            string root = trie.searchRoot(currentWord);
            result += (root.empty() ? currentWord : root);
        }

        return result;
    }
};
