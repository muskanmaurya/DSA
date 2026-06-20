class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int d) {
        int n = nums.size();
        // This ordered set acts as our sliding window.
        // It keeps elements sorted so we can use Binary Search.
        // We use 'long long' to prevent integer overflow errors.
        set<long long> window;

        for(int i = 0; i < n; i++){
            // Step 1: Calculate the lowest acceptable value for our range.
            // Target Range: [nums[i] - d, nums[i] + d]
            long long target = (long long)nums[i] - d;
            // Step 2: Use Binary Search (lower_bound) to look for the first 
            // element in our window that is greater than or equal to (>=) our target.
            // 'it' is a pointer (iterator) pointing to that found number.
            auto it = window.lower_bound(target);
            // Step 3: Check if a valid number was found, and if it is 
            // less than or equal to (<=) our maximum allowable upper bound.
            if(it != window.end() && *it <= nums[i] + d){
                return true; // A valid pair is found within the range conditions!
            } 
            // Step 4: Add the current number into the window for future checks.
            window.insert(nums[i]);
            // Step 5: Maintain the window size constraint.
            // If our index 'i' reaches or exceeds 'k', the oldest element
            // at index 'i - k' is now too far away. We remove it from our set.
            if(i >= k){
                window.erase(nums[i - k]);
            }
        }
        // If the entire array is scanned and no valid pair is found:
        return false;  
    }
};