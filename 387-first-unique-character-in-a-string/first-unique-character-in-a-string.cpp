class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        for(int i = 0; i < n; i++){
            bool isDup = false;
            for(int j = 0; j < n; j++){
                if(s[i] == s[j] && i != j){
                    isDup = true;
                    break;
                }
            }
            if(isDup == false) return i;
        }
        return -1;
    }
};