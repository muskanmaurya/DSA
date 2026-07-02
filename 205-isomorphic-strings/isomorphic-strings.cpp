class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // If lengths don't match, instantly false
        if(s.length() != t.length()) return false;

        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;
        for(int i = 0; i < s.size(); i++){
            char cs = s[i];
            char ct = t[i];

        // Check Rule 1: Does charS already have a rule that doesn't match charT?
            if(mapST.contains(cs) && mapST[cs] != ct) return false;
        // Check Rule 2: Does charT already have a rule that doesn't match charS?
            if(mapTS.contains(ct) && mapTS[ct] != cs) return false;

            mapST[cs] = ct;
            mapTS[ct] = cs;
        }
        return true;
    }
};