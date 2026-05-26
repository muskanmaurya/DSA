class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int cnt=0; // Counter to track the number of structural value drops
        // Run a single loop across the entire array
        for(int i=0;i<n;i++){
            // Circular boundary check using (i + 1) % n. 
            // This perfectly compares the last element with the first element automatically.
            if(nums[i]>nums[(i+1)%n]){
                cnt++;// Drop found! Increment the breakpoint counter
            }
        }
        if(cnt<=1)return true; // if there is less than equal to one break point
        else return false; // if there is more than one break point
    }
};