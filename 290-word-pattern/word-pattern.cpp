class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string currentWord = "";
        
        // Fix: Only push to words when we hit a SPACE or END OF STRING
        for (int i = 0; i <= s.length(); i++) {
            if (i == s.length() || s[i] == ' ') {
                if (!currentWord.empty()) {
                    words.push_back(currentWord);
                    currentWord = "";
                }
            } else {
                currentWord += s[i];
            }
        }
        
        if (pattern.length() != words.size()) {
            return false;
        }
        
        int n = pattern.length();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (pattern[i] == pattern[j] && words[i] != words[j]) {
                    return false;
                }
                if (pattern[i] != pattern[j] && words[i] == words[j]) {
                    return false;
                }
            }
        }  
        return true;
    }
};