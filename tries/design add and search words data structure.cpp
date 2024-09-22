struct Node {
    Node* links[26]; // Pointers to children nodes for each character (a-z)
    bool isEndOfWord = false; // Flag to mark the end of a word

    // Checks if a character node exists
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    // Creates a link to the new node for the given character
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Returns the node linked to the given character
    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

class Trie {
private:
    Node* root;

    // Recursive function to handle wildcard search
    bool searchInNode(string &word, int index, Node* node) {
        if (!node) return false; // If the node is NULL, return false

        // If reached the end of the word, check if it's marked as a word
        if (index == word.size()) {
            return node->isEndOfWord;
        }

        char ch = word[index];
        if (ch == '.') {
            // If the character is '.', try all possible children nodes
            for (int i = 0; i < 26; i++) {
                if (node->links[i] && searchInNode(word, index + 1, node->links[i])) {
                    return true;
                }
            }
            return false; // If none of the paths worked
        } else {
            // If it's a regular character, continue down the corresponding child node
            return node->containsKey(ch) && searchInNode(word, index + 1, node->get(ch));
        }
    }

public:
    Trie() {
        root = new Node(); // Initialize the root node
    }

    // Adds a word to the Trie
    void addWord(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node()); // Create a new node if it doesn't exist
            }
            node = node->get(ch); // Move to the next node
        }
        node->isEndOfWord = true; // Mark the end of the word
    }

    // Searches for a word or pattern in the Trie
    bool search(string word) {
        return searchInNode(word, 0, root); // Start searching from the root node
    }
};

class WordDictionary {
private:
    Trie trie; // Use the Trie for word storage and search

public:
    WordDictionary() {}

    // Adds a word into the dictionary
    void addWord(string word) {
        trie.addWord(word); // Add the word to the Trie
    }

    // Returns if the word is in the dictionary (with support for '.' wildcard)
    bool search(string word) {
        return trie.search(word); // Search the word in the Trie
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
