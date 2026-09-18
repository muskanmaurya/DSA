class Solution {
public:
    int characterReplacement(string s, int k) {
        //Optimal
        int n = s.length();
        int l = 0, r = 0, maxF = 0, maxL = 0;
        int hash[26] = {0};

        while(r < n){
            hash[s[r] - 'A']++;
            maxF = max(maxF, hash[s[r] - 'A']);
            if((r - l + 1) - maxF > k){
                hash[s[l] - 'A']--;
                maxF = 0;
                l++;
            }

            if((r - l + 1) - maxF <= k){
                maxL = max(maxF, r - l + 1);
            }
            r++;
        }
    return maxL;  
    } 
};