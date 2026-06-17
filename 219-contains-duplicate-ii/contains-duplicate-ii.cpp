class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k == 0) return false; //edge case
        int n = nums.size();
        unordered_set<int> mmw; //moving memory window
        for(int i = 0; i < n; i++){
            if(mmw.contains(nums[i])){
                return true;
            }
            else{
                if(i >= k){ //if window size crosses k, then remove the old element  
                    mmw.erase(nums[i - k]);
                }
                mmw.insert(nums[i]); //then add the new elem
            }
        }
    return false;
    }
};