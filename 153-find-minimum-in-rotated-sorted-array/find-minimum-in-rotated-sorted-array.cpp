class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        int ans=INT_MAX;
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(nums[st] <= nums[mid]){
                ans = min(ans, nums[st]);
                st = mid + 1;
            }
            else if(nums[mid] <= nums[end]) {
                ans = min (ans, nums[mid]);
                end = mid - 1;
            }
        }
        return ans;
    }
};