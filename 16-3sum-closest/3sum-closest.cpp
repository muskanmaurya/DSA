class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < n - 2; i++){
            int l = i + 1; //left
            int r = n - 1; //right

            while(l < r){
                int currentSum = nums[i] + nums[l] + nums[r];

                if(abs(t - currentSum) < abs(t - closestSum)){
                    closestSum = currentSum;
                }

                if(currentSum < t){
                    l++;
                }else if(currentSum > t){
                    r--;
                }else return currentSum;
            }
        }
    return closestSum;
    }
};