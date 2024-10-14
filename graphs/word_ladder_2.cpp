

GPT, ONLY CHECKING LEVEL LOGIC WAS CHANGED FRON STRIVER
vector<vector<string>> findSequences(string b, string e, vector<string>& wordList) {
    queue<vector<string>> q;
    q.push({b});
    unordered_set<string> s(wordList.begin(), wordList.end());
    
    vector<string> used;
    vector<vector<string>> ans;
    int level = 0;
    
    while (!q.empty()) {
        int size = q.size();  // Get the current level size
        vector<string> tempUsed;  // Track used words at this level
        
        for (int i = 0; i < size; ++i) {
            vector<string> topvector = q.front();
            q.pop();
            
            string last = topvector.back();
            
            // If we found the target word
            if (last == e) {
                // If it's the first answer, or the same length as previous answers
                if (ans.empty() || ans[0].size() == topvector.size()) {
                    ans.push_back(topvector);
                }
                // Since we are finding the shortest sequence, we don't need to check further
                continue;
            }
            
            // Transform each character in the current word
            for (int i = 0; i < last.size(); ++i) {
                char original = last[i];
                
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    last[i] = ch;
                    
                    if (s.find(last) != s.end()) {
                        topvector.push_back(last);  // Add the new word to the sequence
                        q.push(topvector);          // Push the new sequence to the queue
                        tempUsed.push_back(last);   // Mark this word to be erased at this level
                        topvector.pop_back();       // Restore original state
                    }
                }
                
                last[i] = original;  // Restore the original character
            }
        }
        
        // After processing the entire level, remove used words from the set
        for (const string& word : tempUsed) {
            s.erase(word);
        }
    }
    
    return ans;
}


STRIVER LOGIC: GPT CODE:

vector<vector<string>> findSequences(string b, string e, vector<string>& wordList) {
    queue<vector<string>> q;
    q.push({b});
    unordered_set<string> s(wordList.begin(), wordList.end());
    
    vector<string> used;
    vector<vector<string>> ans;
    int level = 0;  // Start level from 0
    
    while (!q.empty()) {
        vector<string> topvector = q.front();
        q.pop();
        
        // Check if we have entered a new level (sequence size has increased)
        if (topvector.size() > level) {
            level++;
            for (auto it : used) {
                s.erase(it);  // Erase words that were used in the previous level
            }
            used.clear();  // Clear the list of used words for the new level
        }
        
        string last = topvector.back();
        
        // If we found the end word, process the result
        if (last == e) {
            if (ans.empty()) {
                ans.push_back(topvector);
            } else if (ans[0].size() == topvector.size()) {
                ans.push_back(topvector);
            }
        }
        
        // Generate all possible transformations by changing one letter
        for (int i = 0; i < last.size(); i++) {
            char original = last[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                last[i] = ch;
                
                // If the transformed word exists in the set
                if (s.find(last) != s.end()) {
                    topvector.push_back(last);  // Add the transformed word
                    q.push(topvector);  // Push the new sequence into the queue
                    used.push_back(last);  // Mark this word as used
                    topvector.pop_back();  // Backtrack for the next iteration
                }
            }
            last[i] = original;  // Restore the original character
        }
    }
    
    return ans;  // Return all shortest sequences found
}

