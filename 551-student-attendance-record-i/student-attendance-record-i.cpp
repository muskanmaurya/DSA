class Solution {
public:
    bool checkRecord(string s) {
        int n = s.length();
        int cntA = 0;
        int cntL = 0;
        for(char c : s){
            if(c == 'A'){
                cntA++;
                cntL = 0;
            }
            else if(c == 'L'){
                cntL++;
            }
            else {
                cntL = 0;
            }

            if(cntA >= 2 || cntL >= 3){
                return false;
            }
        }
        return true;
    }
};