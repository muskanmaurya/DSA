class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        // Edge cases: If array has only 1 element, or the unique element is at the boundaries
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n - 1] != nums[n - 2]) return nums[n - 1];
        // Search inside the boundaries securely
        int st = 1, end = n - 2;
        while(st <= end){
            int mid = st + (end - st) / 2;
            // If mid is not equal to either of its neighbors, it's our single element!
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
            // Check if we are standing in the normal "Left Zone"
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 != 0 && nums[mid] == nums[mid - 1])){
                st = mid + 1;
            }
            // Otherwise, the shift has already happened, meaning we are in the "Right Zone"
            else {
                end = mid;
            }
        }
        return nums[n - 1];
    }
};