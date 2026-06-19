class Solution {
public:
    int sumByDiv(vector<int>& nums, int div){
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += (nums[i] + div - 1) / div;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int t) {
        int n = nums.size();
        int max_elem = *max_element(nums.begin(), nums.end());
        int st = 1;
        int end = max_elem;
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(sumByDiv(nums, mid) <= t){
                end = mid - 1;
            }else st = mid + 1;
        }
        return st;
    }
};