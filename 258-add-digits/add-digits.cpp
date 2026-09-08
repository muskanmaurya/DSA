class Solution {
public:
    int addDigits(int num) {
        long long sum = 0;
        while(num > 0){
            long long ld = num % 10;
            sum += ld;
            num /= 10;
        }
        if(sum >= 10) return addDigits(sum);
        
        return sum;
    }
};