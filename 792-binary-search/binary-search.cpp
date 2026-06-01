class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n = nums.size();
        // Initialize two pointers to define our search boundaries.
        int st = 0; // start
        int end = n-1; // end
        // Keep searching as long as the search space is valid (st hasn't crossed end)
        while(st <= end){
            // Calculate the mid index. 
            // Using 'st + (end - st) / 2' prevents potential integer overflow bugs with very large arrays.
            int mid = st + (end - st) / 2;
            // Case 1: If the element at the middle index matches our target 't',
            // we have successfully found it! Return its index immediately.
            if(nums[mid] == t){
                return mid;
            }
            // Case 2: If the middle element is strictly greater than our target,
            // it means our target must lie in the smaller half on the left side.
            else if(nums[mid] > t){
                end = mid - 1; // Shrink the search space by moving the 'end' pointer
            }
            // Case 3: If the middle element is strictly smaller than our target,
            // it means our target must lie in the larger half on the right side.
            else st = mid + 1; // Shrink the search space by moving the 'st' pointer
        }
        // If the loop finishes without hitting Case 1, the target 
        // does not exist anywhere inside the array.
        return -1;
    }
};