class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        // Step 1: Mark visited elements by converting numbers at those positions to negative
        for(int i = 0; i < n; i++){
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0){ //if elem at that index is pos then mark it neg
                nums[index] = -nums[index];
            }
        }
        // Step 2: Scan the array again. the pos index is missing number
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans.push_back(i + 1); // Index 'i' means number 'i + 1' was missing
            }
        }
        return ans;
    }
};
