class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        //better
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            if(it.second > 2)return false;
        }
        return true;
    }
};