class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Bruteforce
        int n = s.length();
        int maxlen = 0;
        for(int i = 0; i < n; i++){
            unordered_set<char> visited;
            int currlen = 0;
            for(int j = i; j < n; j++){
                if(visited.count(s[j])){
                    break;
                }
                
                visited.insert(s[j]);
                currlen++;
                maxlen = max(currlen, maxlen);
            }
        }
        return maxlen;
    }
};