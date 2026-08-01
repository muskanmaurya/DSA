class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int> cnt(26, 0);

        int maxcnt = 0;
        char maxchar;
        for(char c : s){
            cnt[c - 'a']++;
            if(cnt[c - 'a'] > maxcnt){
                maxcnt = cnt[c - 'a'];
                maxchar = c;
            }
        }

        if(maxcnt > (n + 1)/2){
            return "";
        }

        string result = s;
        int idx = 0;
        while(cnt[maxchar - 'a'] > 0){
            result[idx] = maxchar;
            idx += 2;
            cnt[maxchar - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            while(cnt[i] > 0){
                if(idx >= n){
                    idx = 1;
                }
                result[idx] = (char)('a' + i);
                idx += 2;
                cnt[i]--;
            }
        }

        return result;
    }
};