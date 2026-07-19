class Solution {
public:
    int firstUniqChar(string s) {
        // optimal
        int n = s.length();
        vector<int> count(26, 0);
        for(char c : s){
            count[c - 'a']++;
        }
        for(int i = 0; i < n; i++){
            if(count[s[i] - 'a'] == 1) return i;
        }
        return -1;  
    }
};