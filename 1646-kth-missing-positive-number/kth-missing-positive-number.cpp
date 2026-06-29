class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        //Optimal with Binary search
        int st = 0, end = nums.size() - 1;
        while(st <= end){
            int mid = st + (end - st) / 2;
            int missing = nums[mid] - (mid + 1);
            if(missing < k){
                st = mid + 1;
            }else {
                end = mid - 1;
            }
        }
        return k + end + 1;
    }
};