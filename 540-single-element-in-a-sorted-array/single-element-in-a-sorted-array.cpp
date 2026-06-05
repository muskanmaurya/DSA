class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        // Jump by 2 because elements appear in pairs
        for(int i = 0; i < n-1; i+=2){
            // If a pair doesn't match, the current element is the single one
            if(nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        // If the loop finishes without returning, the single element 
        // must be sitting at the very last index.
        return nums[n - 1];
    }
};