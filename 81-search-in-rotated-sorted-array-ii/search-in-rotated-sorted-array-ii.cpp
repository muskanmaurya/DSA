class Solution {
public:
    bool search(vector<int>& nums, int t) {
    int n = nums.size();
    int st = 0, end = n - 1;
    while(st <= end){
        int mid = st + (end - st) / 2;
        // Case 1: If the middle element matches our target, return true immediately
        if(nums[mid] == t) return true;
        // CRITICAL DUPLICATE HANDLER: 
            // If the start, middle, and end elements are all identical, we cannot
            // distinguish which half of the array is sorted. The safest move is to 
            // shrink our search boundaries by 1 step from both sides and try again.
        if (nums[st] == nums[mid] && nums[mid] == nums[end]) {
                st++;
                end--;
                continue; // Skip the rest of the checks for this iteration
            }
        else if(nums[st] <= nums[mid]){ // Case 2: Check if the LEFT half is perfectly sorted
            if(t >= nums[st] && t <= nums[mid]) end = mid - 1;
            else st = mid + 1;
        }
        else {  // Case 3: If the left half isn't sorted, the RIGHT half must be sorted!
            if(t >= nums[mid] && t <= nums[end]) st = mid + 1;
            else end = mid - 1;
        }
    }
    return false;  // Loop finished without finding the target element
    }  
};
