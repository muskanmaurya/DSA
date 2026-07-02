class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Optimal Solution
        // If lengths don't match, instantly false
        if(s.length() != t.length()) return false;
        // Two arrays of size 256 initialized to 0
        int mapST[256] = {0};
        int mapTS[256] = {0};

        for(int i = 0; i < s.size(); i++){
            char cs = s[i];
            char ct = t[i];
            // If they have been mapped before, do they match the current pair?
            if(mapST[cs] != 0 && mapST[cs] != ct) return false;
            if(mapTS[ct] != 0 && mapTS[ct] != cs) return false;

            mapST[cs] = ct;
            mapTS[ct] = cs;
        }
        return true;
    }
};