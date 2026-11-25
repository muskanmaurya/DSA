class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        long long tsum = 0;
        for (int x : nums) tsum += x;

        vector<int> ans(n);
        long long psum = 0;
        for(int i = 0; i < n; i++){
            long long val = nums[i];
            long long rsum = tsum - psum - nums[i];

            long long ldiff = val * i - psum;
            long long rdiff = rsum - val * (n - 1 - i);
            ans[i] = static_cast<int>(ldiff + rdiff);
            psum += val;
        }
        return ans;
    }
};