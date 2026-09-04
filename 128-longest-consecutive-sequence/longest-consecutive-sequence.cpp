#include<unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());
        int maxS = 1;
        int cnt = 1;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i + 1]){
                continue;
            }

            if(nums[i + 1] == nums[i] + 1){
                cnt++;
            }
            else {
                maxS = max(maxS, cnt);
                cnt = 1;
            }
        }
        return max(maxS, cnt);
    }
};