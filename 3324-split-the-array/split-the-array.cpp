class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        //brute
        for(int i = 0; i < nums.size(); i++){
            int cnt = 0;
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] == nums[j]){
                    cnt++;
                }
                if(cnt >= 2) return false;
            }
        }
        return true;
    }
};