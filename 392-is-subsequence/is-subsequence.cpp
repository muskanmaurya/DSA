class Solution {
public:
    bool isSubsequence(string s, string t) {
        //Bruteforce
        int lastFound = -1;
        for(int i = 0; i < s.length(); i++){
            bool isfound = false;
            for(int j = lastFound + 1; j < t.length(); j++){
                if(s[i] == t[j]){
                    isfound = true;
                    lastFound = j;
                    break;
                }
            }
            if (!isfound) return false;
        }
        return true;
    }
};