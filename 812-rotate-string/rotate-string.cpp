class Solution {
public:
    bool rotateString(string s, string goal) {
        //bruteforce
        if(s.length() != goal.length()) return false;

        for(int i = 0; i < s.length(); i++){
            s = s.substr(1) + s[0];

            if(s == goal) return true;
        }
        return false;
    }
};