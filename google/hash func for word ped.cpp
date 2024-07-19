#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table; // Hash table to store indices
    int tableSize;     // Size of the hash table

    // Simple hash function based on polynomial rolling hash
    int hashFunction(const string& key) {
        const int p = 31;      // A prime number for hashing
        const int m = tableSize; // Size of the hash table (modulo value)
        long long hashValue = 0;
        long long p_pow = 1;

        for (char c : key) {
            hashValue = (hashValue + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }

        return hashValue;
    }

public:
    HashTable(int size) : tableSize(size) {
        table.resize(size, -1); // Initialize hash table with -1 (indicating empty slots)
    }

    // Insert a word into the hash table
    void insert(const string& key) {
        int index = hashFunction(key);
        table[index] = 0; // Example insertion; adjust based on requirements
        cout << "Word \"" << key << "\" hashed to index: " << index << endl;
    }

    // Get index of a word
    int getIndex(const string& key) {
        int index = hashFunction(key);
        return index;
    }
};

int main() {
    HashTable hashTable(10); // Create a hash table with size 10

    hashTable.insert("ishma");
    hashTable.insert("mode");
    hashTable.insert("I");

    cout << "Index of 'ishma': " << hashTable.getIndex("ishma") << endl;
    cout << "Index of 'mode': " << hashTable.getIndex("mode") << endl;
    cout << "Index of 'I': " << hashTable.getIndex("I") << endl;

    return 0;
}
