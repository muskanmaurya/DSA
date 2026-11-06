class Solution {
public:
    int countDigits(int n){
        int sum = 0;
        while(n > 0){
            int ld = n % 10;
            sum += ld;
            n /= 10;
        }
        return sum;
    }
    int countBalls(int lowLim, int highLim) {
        unordered_map<int, int> mp;

        for(int i = lowLim; i <= highLim; i++){
            int digSum = countDigits(i);
            mp[digSum]++;
        }

        int maxBalls = 0;
        for(auto& pair : mp){
            maxBalls = max(maxBalls, pair.second);
        }

        return maxBalls;
    }
};