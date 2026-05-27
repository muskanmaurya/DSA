class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        //Sort the array
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){ 
            //If the current starting number is greater than 0, 
            // no three numbers after it can ever sum to 0.
            if (nums[i] > 0) break;
            //Skip duplicate values for the first element to avoid duplicate triplets
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            //Initialize two pointers for the remaining window
            int j=i+1, k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                // Sum is too small, move the left pointer to increase the sum
                if(sum<0)j++;
                // Sum is too large, move the right pointer to decrease the sum
                else if(sum>0)k--;
                else if(sum==0){
                    // Found a valid triplet summing to 0
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++,k--;
                    //Skip duplicate elements for both 'j' and 'k' to avoid duplicate triplets
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};