class Solution {
public:
    //helper function to check if length is palindrome or not
    int expendFromCenter(string& s, int l, int r){
        while(l >= 0 && r <s.length() && s[l] == s[r]){
            l--;
            r++;
        }
        return r - l - 1;
    }
    string longestPalindrome(string s) {
        //better
        if(s.empty()) return "";
        int maxlen = 0;
        int start = 0;
        for(int i = 0; i < s.length(); i++){
            int len1 = expendFromCenter(s, i, i);

            int len2 = expendFromCenter(s, i, i + 1);

            int len = max(len1, len2);

            if(len > maxlen){
                maxlen = len;

                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxlen);
    }
};