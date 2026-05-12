#include<algorithm>
class Solution {
public:
    void rotate(vector<int>& nums, int d) {
        int n=nums.size();
        d=d%n;
        vector<int> temp(n);
    
    // Step 1: Place each element in its new "rotated" position
    for (int i = 0; i < n; i++) {
        temp[(i + d) % n] = nums[i];
    }
    
    // Step 2: Copy temp back to nums
    nums = temp;

    }
};