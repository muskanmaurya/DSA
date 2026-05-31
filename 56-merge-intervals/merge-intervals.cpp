class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {  //Optimal solution
        int n = nums.size();
        sort(nums.begin(), nums.end()); //Sort the intervals
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(ans.empty() || nums[i][0] > ans.back()[1]){
                // This means there is NO overlap! It's a brand new standalone interval.
                // We safely push the entire interval pair into our answers list.
                ans.push_back(nums[i]);
            }
            //If it fails the condition above, it means the current interval DOES overlap with the last interval we saved.
            else{
                // Instead of pushing a new pair, we update the end boundary of our 
                // last saved interval to stretch and absorb the larger of the two ends.
                ans.back()[1] = max(ans.back()[1], nums[i][1]);
            }
        }
        // Return the fully consolidated list of non-overlapping intervals
        return ans;
    }
};