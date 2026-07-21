class Solution {
public:
    //helper function to check if length is palindrome or not
    bool isPalindrome(string& s, int l, int r){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        //bruteforce
        int maxlen = 0;
        int start = 0;
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < s.length(); j++){
                if(isPalindrome(s, i, j)){
                    int currlen = j - i + 1;

                    if(currlen > maxlen){
                        maxlen = currlen;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxlen);
    }
};