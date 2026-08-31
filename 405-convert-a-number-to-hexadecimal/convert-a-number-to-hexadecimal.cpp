class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        unsigned int n = num;

        string hexChars = "0123456789abcdef";
        string result = "";

        while(n > 0){
            int last4Bits = n & 15;
            result += hexChars[last4Bits];
            n >>= 4;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};