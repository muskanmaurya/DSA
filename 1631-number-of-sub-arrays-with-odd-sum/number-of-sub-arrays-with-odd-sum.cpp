class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int cnt = 0;
        int MOD = 1e9 + 7;
        int currSum = 0;
        int oddCnt = 0;
        int evenCnt = 1;

        for(int a : arr){
            currSum += a;
            if(currSum % 2 != 0){
                cnt = (cnt + evenCnt) % MOD;
                oddCnt++;
            } else {
                cnt = (cnt + oddCnt) % MOD;
                evenCnt++;
            }
        }
        return cnt;
    }
};