struct Node {
    Node* links[26];
    bool isEndOfWord = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        isEndOfWord = true;
    }

    bool isEnd() {
        return isEndOfWord;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // Insert a word into the Trie
    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();  // Mark end of the word
    }

    // Search for a word with exactly one mismatch
    bool searchInTrie(string& word, Node* node, int index, int mismatchCount) {
        if (index == word.size()) {
            // If we've traversed the entire word, check if we have exactly one mismatch and if it's a valid word
            return mismatchCount == 1 && node->isEndOfWord;
        }

        char currentChar = word[index];
        
        // Case 1: Continue with the same character
        if (node->containsKey(currentChar)) {
            if (searchInTrie(word, node->get(currentChar), index + 1, mismatchCount)) {
                return true;
            }
        }

        // Case 2: Try changing the character (i.e., allow one mismatch)
        if (mismatchCount == 0) {  // Only allow one mismatch
            for (int i = 0; i < 26; ++i) {
                if (node->links[i] && (i != currentChar - 'a')) {
                    if (searchInTrie(word, node->links[i], index + 1, mismatchCount + 1)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    // Public search function
    bool search(string word) {
        return searchInTrie(word, root, 0, 0);  // Start with 0 mismatches
    }
};

class MagicDictionary {
private:
    Trie trie;

public:
    MagicDictionary() {}

    // Build the dictionary
    void buildDict(vector<string> dictionary) {
        for (string word : dictionary) {
            trie.insert(word);
        }
    }

    // Search for a word with exactly one character mismatch
    bool search(string searchWord) {
        return trie.search(searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
