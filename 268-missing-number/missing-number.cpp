class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int n = nums.size();
    // The range is [0, n], but array indices only go from 0 to n-1 so init it with n to ensure the last no of range is included.
    int res = n; 
    
    for (int i = 0; i < n; i++) {
        // Instead of two separate loops, we XOR the "Expected Number" (index i) and the "Actual Number" (nums[i]) at the same time using a ^ a = 0 (Same numbers cancel out) and 0 ^ a = a.
        res ^= i ^ nums[i];
    }
    // After the loop, every number that was present in both the index pool and the array values will have canceled itself out to zero.
    // The only value remaining in 'res' is the one that never had a pair.
    return res;  
    }
};