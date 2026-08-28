class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ansarr = {{}};
        
        for(int num : nums){
            int size = ansarr.size();
            for(int i = 0; i < size; i++){
                vector<int> current = ansarr[i];
                current.push_back(num);
                ansarr.push_back(current);
            }
        }
        return ansarr;
    }
};