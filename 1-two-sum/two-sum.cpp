#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int first = nums[i];
            int second = t - first;
            if(mpp.contains(second)){
                return {mpp[second], i};
            }
            mpp[first] = i;
        }
        return {-1, -1};
    }
};