class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int> cnt(26, 0);

        for(char c : s){ // count freq of each char
            cnt[c - 'a']++;
        }
        vector<pair<int, int>> freq;
        for(int i = 0; i < 26; i++){ //group chars with their freq & sort descending
            if(cnt[i] > 0){
                freq.push_back({cnt[i], (char)('a' + i)});
            }
        }
        sort(freq.rbegin(), freq.rend());
        if(freq[0].first > (n + 1) / 2) return "";

        string ans = s;
        int idx = 0;

        for(auto& p : freq){ //Interleave chars into even and odd
            int freqCnt = p.first;
            char ch = p.second;

            while(freqCnt > 0){
                if(idx >= n) idx = 1;

                ans[idx] = ch;
                idx += 2;
                freqCnt--;
            } 
        }
        return ans;
    }
};