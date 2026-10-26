class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int minRepeat = b.length() / a.length();
        int cnt = 0;
        string curr = "";

        for(int i = 0; i < minRepeat + 2; i++){
            curr += a;
            cnt++;

            if(curr.find(b) != string::npos){
                return cnt;
            }
        }
        return -1;
    }
};