class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //optimal - Dynamic Sliding Window
        int n = s.length();
        int maxlen = 0;
        unordered_map<char, int> lastSeen;
        int l = 0; //left pointer SW
        for(int r = 0; r < n; r++){  //right pointer of SW
            char c = s[r];
            // If character was seen before AND its index is inside current window [left, right]
            if(lastSeen.count(c) && lastSeen[c] >= l){
                l = lastSeen[c] + 1;
            }
            lastSeen[c] = r; // Update last seen index of character
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};