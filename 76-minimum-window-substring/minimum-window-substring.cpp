class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int minL = INT_MAX, sIdx = -1;
        int l = 0, r = 0, cnt = 0;  
        int hash[256] = {0};

        for(int i = 0; i < m; i++) hash[t[i]]++;

        while(r < n){
            if(hash[s[r]] > 0){
                cnt++;
            }
            hash[s[r]]--;

            while(cnt == m){
                if(r - l + 1 < minL){
                    minL = r - l + 1;
                    sIdx = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return (sIdx == -1) ? "" : s.substr(sIdx, minL);     
    }
};