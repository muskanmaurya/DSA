class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int sum = 0;
        int minlen = INT_MAX;

        for(int j = 0; j < n; j++){
            sum += nums[j];

            while(sum >= t){
                minlen = min(minlen, j - i + 1);
                sum -= nums[i];
                i++;
            }
        }
        return (minlen == INT_MAX) ? 0 : minlen;
    }
};