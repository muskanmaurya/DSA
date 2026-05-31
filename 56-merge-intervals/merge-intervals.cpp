class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        // Step 1: Sort the intervals based on their start times.
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;

        // Step 2: Pick each interval one-by-one to act as a potential "anchor"
        for (int i = 0; i < n; i++) {
            int st = nums[i][0];
            int end = nums[i][1];

            // Step 3: CRITICAL CHECK
            // If the below conditon meets, it means this interval has already been completely absorbed into a previous merge block. Skip it!
            if (!ans.empty() && st <= ans.back()[1]) {
                continue;
            }

            // Step 4: Inner Loop
            // Look ahead at all subsequent intervals to see how far we can stretch our current 'end' boundary.
            for (int j = i + 1; j < n; j++) {
                
                // If the next interval starts before or exactly when our current boundary ends,
                // they are overlapping!
                if (nums[j][0] <= end) {
                    // Update our boundary to absorb the furthermost reaching end point
                    end = max(end, nums[j][1]);
                } 
                else {
                    // Since the array is sorted, if this one doesn't overlap, no future intervals will either. Break early to save time.
                    break;
                }
            }
            
            // Step 5: The chain broke or ended. 
            // Push the fully expanded [start, end] pair into our final answer vector.
            ans.push_back({st, end});
        }
        
        // Step 6: Return the consolidated list of non-overlapping intervals
        return ans;
    }
};