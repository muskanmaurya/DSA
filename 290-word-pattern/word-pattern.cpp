class Solution {
public:
    bool wordPattern(string pattern, string s) {
        //optimal with optimization
        stringstream ss(s);
        string word;
        vector<string> words;

        while(ss >> word) words.push_back(word);
        if(pattern.length() != words.size()) return false;
        // tracking with index  
        unordered_map<char, int> charIdx;  //last seen position (e.g., 'a': 1)
        unordered_map<string, int> wordIdx; //last seen position (e.g., "dog": 1)

        for(int i = 0; i < pattern.length(); i++){
            // Check if last seen 1-based positions are equal
            if(charIdx[pattern[i]] != wordIdx[words[i]]) return false;
            // Store (i + 1) as the 1-based index
            charIdx[pattern[i]] = i + 1;
            wordIdx[words[i]] = i + 1;

        }
    return true;
    }
};