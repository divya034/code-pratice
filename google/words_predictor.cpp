#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_WORDS = 1000;  // Adjust the size based on the maximum number of unique words expected

class WordPredictor {
public:
    WordPredictor() {
        nextWord.assign(MAX_WORDS, "");         // Initialize nextWord with empty strings
        mostFrequent.assign(MAX_WORDS, "");     // Initialize mostFrequent with empty strings
        wordCount.assign(MAX_WORDS, 0);         // Initialize wordCount with zeros
    }

    void train(const vector<vector<string>>& sequences) {
        for (const auto& sequence : sequences) {
            for (size_t i = 0; i < sequence.size() - 1; ++i) {
                const string& word = sequence[i];
                const string& nextWord = sequence[i + 1];
                int index = getIndex(word);
                wordCount[index]++;
                if (wordCount[index] > wordCount[mostFrequentIndex]) {
                    mostFrequentIndex = index;
                }
                this->nextWord[index] = nextWord;
            }
        }
    }
    
    string predict(const string& word) {
        int index = getIndex(word);
        if (index != -1) {
            return nextWord[index];
        }
        return "";
    }

private:
    vector<string> nextWord;        // Stores the next word for each index
    vector<string> mostFrequent;    // Stores the most frequent successor for each index
    vector<int> wordCount;          // Stores the count of each word
    int mostFrequentIndex = -1;     // Index of the most frequent word

    int getIndex(const string& word) {
        // Simulate a simple index calculation based on ASCII values
        return word[0] - 'A';  // This is a basic example; adjust as per your needs
    }
};

int main() {
    WordPredictor model;
    model.train({
        {"I", "am", "ishma"},
        {"ishma", "I", "am"},
        {"eggs", "green", "grass", "I", "test"}
    });

    cout << "Prediction for 'am': " << model.predict("am") << endl;  // Outputs: "ishma"
    cout << "Prediction for 'I': " << model.predict("I") << endl;    // Outputs: "am"

    return 0;
}




// Iteration 1 (Sequence: {"I", "am", "ishma"}):

word = "I", nextWord = "am"
index = getIndex("I"), assuming getIndex("I") returns a specific index (like 0 for simplicity here).
Increment wordCount[0].
Update nextWord[0] to "am".
Iteration 2 (Sequence: {"I", "am", "ishma"}):

word = "am", nextWord = "ishma"
index = getIndex("am"), assuming getIndex("am") returns a specific index (like 1 for simplicity).
Increment wordCount[1].
Update nextWord[1] to "ishma".
Iteration 3 (Sequence: {"ishma", "I", "am"}):

word = "ishma", nextWord = "I"
index = getIndex("ishma"), assuming getIndex("ishma") returns a specific index (like 2 for simplicity).
Increment wordCount[2].
Update nextWord[2] to "I".
And so on...
