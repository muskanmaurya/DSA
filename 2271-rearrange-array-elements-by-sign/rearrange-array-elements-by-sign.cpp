class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n); // Extra space is mandatory to preserve order
        int posIdx = 0; // Pointer for positive numbers (even indices)
        int negIdx = 1; // Pointer for negative numbers (odd indices)
        
        //Directly place elements into their correct positions
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans[posIdx] = nums[i];
                posIdx += 2; // Move to the next even position
            }else {
                ans[negIdx] = nums[i];
                negIdx += 2; // Move to the next odd position
            }
        }
        return ans;
    }
};