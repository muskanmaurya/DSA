class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        //optimal - Binary search
        if(n == 1) return 0; // Handle single element array
        // Handle boundary elements explicitly to avoid out-of-bounds errors later
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        // Search space reduces to inner elements because boundaries are handled
        int st = 1;
        int end = n-2;
        while(st <= end){
            int mid = st + (end - st) / 2;  
            //If mid is strictly greater than both its neighbors, it's the peak!
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            //If the right neighbor is greater, the upward slope is towards the right
            if(nums[mid] < nums[mid+1]) st = mid + 1; // Move our search space to the right half

            //Otherwise, the slope goes up towards the left half
            else end = mid - 1; // Move our search space to the left half
        } 
        return -1;    
    }
};