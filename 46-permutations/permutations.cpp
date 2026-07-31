class Solution {
public:
    vector<vector<int>> getPerms(vector<int>& nums, int idx, vector<vector<int>>& ansarr){
        if(idx == nums.size()){
            ansarr.push_back({nums});
        }
        for(int i = idx; i < nums.size(); i++){
            swap(nums[i], nums[idx]);
            getPerms(nums, idx + 1, ansarr);
            swap(nums[i], nums[idx]);
        }
        return ansarr;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ansarr;
        getPerms(nums, 0, ansarr);
        return ansarr;
    }      
};