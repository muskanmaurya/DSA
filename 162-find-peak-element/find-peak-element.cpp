class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int st=1;
        int end=n-1;
            if(n==1)return 0;
            if(nums[0]>nums[1])return 0;
            if(nums[n-1]>nums[n-2])return n-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            if(nums[mid-1]<nums[mid]){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return -1;
    }
};