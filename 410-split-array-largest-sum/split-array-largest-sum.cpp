class Solution {
public:
    // Helper function to test if a given max sum is mathematically possible
    bool canSplit(vector<int> &nums, long long maxSum, int k) {
        int subArrNeeded = 1;
        long long currSubSum = 0;
        for(int i = 0; i < nums.size(); i++){
            // If adding the next element breaks the limit, we must split!
            if(currSubSum + nums[i] > maxSum){
                subArrNeeded++;
                currSubSum = nums[i];
                // If we've been forced to create more subarrays than allowed
                if(subArrNeeded > k) return false;
            }
            else currSubSum += nums[i];  // Otherwise, keep growing the current subarray
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return -1;
        long long st = *max_element(nums.begin(), nums.end());
        long long end = accumulate(nums.begin(), nums.end(), 0LL);
        long long optimalMaxSum = -1;

        while(st <= end){
            long long mid = st + (end - st) / 2;
            // If this max sum works, record it, but try to find a tighter limit
            if(canSplit(nums, mid, k) == true){
                optimalMaxSum = mid;
                end = mid - 1;
            }
            else st = mid + 1; // If it fails, the limit was too strict.
        }
        return optimalMaxSum;
    }    
};