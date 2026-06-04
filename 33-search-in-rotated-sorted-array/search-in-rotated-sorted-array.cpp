class Solution {
public:
    int search(vector<int>& nums, int t) {
    int n = nums.size();
    int st = 0, end = n - 1;
    while(st <= end){
        int mid = st + (end - st) / 2;
        // Case 1: If mid element is our target, return its index immediately
        if(nums[mid] == t) return mid;
        // Case 2: Check if the LEFT half is perfectly sorted
        else if(nums[st] <= nums[mid]){
            // If the target falls completely within this sorted left boundary
            if(t >= nums[st] && t <= nums[mid]) end = mid - 1; // Narrow search space to the left half
            else st = mid + 1; // Otherwise, search the right half
        }
        // Case 3: If the left half isn't sorted, the RIGHT half must be sorted!
        else {
            // If the target falls completely within this sorted right boundary
            if(t >= nums[mid] && t <= nums[end]) st = mid + 1; // Narrow search space to the right half
            else end = mid - 1; // Otherwise, search the left half
        }
        }
        // Target was not found anywhere in the array
        return -1;;
    }
};