class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        //optimal
        int n = nums.size();
        vector<int> freq(101, 0);
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
            if(freq[nums[i]] > 2){
                return false;
            }
        }
        return true;
    }
};