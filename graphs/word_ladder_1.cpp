
Tc:
for loop ---> O(number of words in list) --- O(N) x 25 chars
it only goes into queue if it is present in the list TC = N x 
Internal loop: word length x 26 x log N (for set)  

number of transitions will max run for N times( number of words in the wordlist)

SC:
queue--> max will have all words from word list
set----->will ahve all from wordList


class Solution {
public:
    int wordLadderLength(string start, string target, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({start, 1});
        unordered_set<string> s(wordList.begin(), wordList.end());
        s.erase(start); 
        // code is working without above step^
        
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word == target) return step;    
            
            for(int i = 0; i<word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    
                    if(s.find(word) != s.end()){
                        s.erase(word);
                        q.push({word, step+1});
                    }
                }
                
                word[i] = original;
            }
        }
        
        
        return 0;
    }
};

Tanuja:
yt comment:

   bool isAdjacent(const string& word1, const string& word2) {
        int diff = 0;
        for (int i = 0; i < word1.size(); ++i) {
            if (word1[i] != word2[i]) {
                diff++;
                if (diff > 1) return false;
            }
        }
        return diff == 1;
    }

   // Function to create the adjacency list graph
    unordered_map<string, vector<string>> buildGraph(vector<string>& wordList) {
        unordered_map<string, vector<string>> graph;

        // Add an empty list for each word
        for (const string& word : wordList) {
            graph[word] = {};
        }

        // Connect each word with its adjacent words
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                if (isAdjacent(wordList[i], wordList[j])) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        return graph;
    }

    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // If targetWord is not in the wordList, no valid transformation is possible
        if (find(wordList.begin(), wordList.end(), targetWord) == wordList.end()) {
            return 0;
        }

        // Include the startWord in the word list if it's not already there
        if (find(wordList.begin(), wordList.end(), startWord) == wordList.end()) {
            wordList.push_back(startWord);
        }

        // Build the graph from the word list
        unordered_map<string, vector<string>> graph = buildGraph(wordList);

        // Perform BFS to find the shortest path
        unordered_map<string, int> distance;
        for (const string& word : wordList) {
            distance[word] = INT_MAX;  // Initialize distances with infinity
        }
        distance[startWord] = 1;

        queue<string> q;
        q.push(startWord);

        while (!q.empty()) {
            string currentWord = q.front();
            q.pop();

            // Traverse all neighbors of the current word
            for (const string& neighbor : graph[currentWord]) {
                if (distance[neighbor] == INT_MAX) {  // If not visited
                    distance[neighbor] = distance[currentWord] + 1;
                    q.push(neighbor);

                    // If we reach the target word, return the distance
                    if (neighbor == targetWord) {
                        return distance[neighbor];
                    }
                }
            }
        }

        // If BFS completes without finding the targetWord, return 0
        return 0;
    }
