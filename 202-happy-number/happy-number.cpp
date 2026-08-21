class Solution {
public:
    bool isHappy(int n) {
        while (n != 1 && n != 4) {
            int currSum = 0;
            while(n > 0){
                int digit = n % 10;
                currSum += digit * digit;
                n = n / 10;
            }
            n = currSum;
        }
        return n == 1;
    }
};