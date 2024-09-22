struct Node {
    Node* links[26]; // Links to child nodes
    vector<string> products; // Stores products for suggestions

    Node() {
        fill(begin(links), end(links), nullptr);
    }

    // Checks if a node exists for the given character
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    // Creates a new node for the given character
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Gets the node for the given character
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

    // Inserts a product into the trie
    void insert(const string& product) {
        Node* node = root;
        for (char ch : product) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
            // Maintain a sorted list of products at each node
            node->products.push_back(product);
            sort(node->products.begin(), node->products.end());
            if (node->products.size() > 3) {
                node->products.pop_back(); // Keep only top 3 lexicographical products
            }
        }
    }

    // Retrieves suggested products based on the prefix
    vector<string> getSuggestions(const string& prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch)) {
                return {}; // No products found for this prefix
            }
            node = node->get(ch);
        }
        return node->products; // Return the sorted product list for the prefix
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;

        // Sort products lexicographically
        sort(products.begin(), products.end());

        // Insert products into the Trie
        for (const string& product : products) {
            trie.insert(product);
        }

        vector<vector<string>> result;
        string prefix = "";

        // Get suggestions for each prefix of the searchWord
        for (char ch : searchWord) {
            prefix += ch; // Build the prefix
            result.push_back(trie.getSuggestions(prefix)); // Get suggestions for the current prefix
        }

        return result;
    }
};
