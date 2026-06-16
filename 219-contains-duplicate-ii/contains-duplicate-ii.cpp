class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int j = 0;
        for(int i = 0; i < n; i++){
            if(mpp.contains(nums[i])){
               int j = mpp[nums[i]];
                if(abs(i - j) <= k){
                    return true;
                }
            }
            mpp[nums[i]] = i;
        }
        return false;
    }
};