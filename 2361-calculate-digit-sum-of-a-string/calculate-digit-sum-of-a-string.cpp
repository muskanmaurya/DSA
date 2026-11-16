class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.length();
        if(s.length() <= k) return s;
        
        string nw = "";
        int sum = 0;
        int l = k;

        for(int i = 0; i < n; i++){
            sum += s[i] - '0';
            l--;

            if(l == 0 || i == s.length() - 1){
                nw += to_string(sum);
                sum = 0;
                l = k;
            }
        }
        return digitSum(nw, k);
    }
};