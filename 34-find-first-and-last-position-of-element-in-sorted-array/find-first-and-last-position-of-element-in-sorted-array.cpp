class Solution {
public:
    // Helper function to find the first occurrence (Lower Bound style)
    int firstPos(vector<int>& nums, int target){
        int n = nums.size();
        int st = 0;
        int end = n - 1;
        int ans = -1; // Stores our latest valid match
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(nums[mid] == target) {
                ans = mid; // Record this index as a potential first position
                end = mid - 1; // Keep pushing LEFT to see if an even earlier 'target' exists
            }
            else if(nums[mid] <= target) st = mid + 1; // Too small, search the right half
            else end = mid - 1; // Too big, search the left half
        }
        return ans;
    }
    // Helper function to find the last occurrence (Upper Bound style)
    int lastPos(vector<int>& nums, int target){
        int n = nums.size();
        int st = 0;
        int end = n - 1;
        int ans = -1; // Stores our latest valid match
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(nums[mid] == target){
                ans = mid; // Record this index as a potential last position
                st = mid + 1; // Keep pushing RIGHT to see if a later 'target' exists
            }
            else if(nums[mid] >= target) end = mid - 1; // Too big, search the left half
            else st = mid + 1; // Too small, search the right half
        }
        return ans;
    }
    
     vector<int> searchRange(vector<int>& nums, int target) {
        // Return both found positions directly as a pair container
        return { firstPos(nums, target), lastPos(nums, target) };
    }
};