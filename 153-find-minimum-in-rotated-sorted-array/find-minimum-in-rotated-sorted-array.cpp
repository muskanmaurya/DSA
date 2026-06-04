class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        int ans=INT_MAX;  // Initialize our answer with a maximum possible integer value
        while(st <= end){
            int mid = st + (end - st) / 2;
            // Case 1: If the LEFT half is perfectly sorted
            if(nums[st] <= nums[mid]){
                // Since the left half is sorted, the smallest element in this
                // entire section is guaranteed to be at the 'st' index.
                ans = min(ans, nums[st]);
                // We've already accounted for the min of this sorted half, so eliminate it and jump to search the right half.
                st = mid + 1;
            }
            // Case 2: If the left half isn't sorted, the RIGHT half MUST be sorted!
            else if(nums[mid] <= nums[end]) {
                // Since the right half is sorted, the smallest element in this
                // entire section is guaranteed to be at the 'mid' index.
                ans = min (ans, nums[mid]);
                // We've already accounted for the min of this sorted half, so eliminate it and jump to search the left half.
                end = mid - 1;
            }
        }
        return ans; // Return the global minimum found across all checked boundaries
    }
};