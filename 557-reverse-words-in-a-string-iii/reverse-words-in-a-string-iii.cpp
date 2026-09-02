class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int n = s.length();
        for(int i = 0; i <= n; i++){
            if(i == n || s[i] == ' '){
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};