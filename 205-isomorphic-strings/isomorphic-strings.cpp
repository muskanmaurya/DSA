class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // If lengths don't match, instantly false
        if(s.length() != t.length()) return false;
        // Outer loop: pick a character
        for(int i = 0; i < s.size(); i++){
            // Inner loop: compare it with characters ahead of it
            for(int j = i + 1; j < s.size(); j++){
                // Rule 1: Same chars in 's' MUST map to same chars in 't'
                if(s[i] == s[j] && t[i] != t[j]) return false;
                // Rule 2: Different chars in 's' MUST NOT map to same chars in 't'
                if(s[i] != s[j] && t[i] == t[j]) return false;
            }
        }
        return true;
    }
};