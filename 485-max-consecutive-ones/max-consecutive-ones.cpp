class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int maxi = 0;
        for(int num : nums){// Using a range-based loop 
            if(num == 1){
                cnt++;
                if (cnt > maxi) maxi = cnt;// Update maxi only when cnt increases
            }else cnt = 0; // Reset streak when a 0 is found
        }
        return maxi;
    }
};