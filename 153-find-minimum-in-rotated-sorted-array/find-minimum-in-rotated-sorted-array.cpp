class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        int ans=INT_MAX;
        while(st<=end){
            int mid=st+(end-st)/2;
            //if whole array is sorted
            if(nums[st]<=nums[end]){
                ans=min(ans,nums[st]);
                break;
            }

            //if left part is sorted 
            if(nums[st]<=nums[mid]){
                ans=min(ans,nums[st]);
                st=mid+1;
            }
            //if right part is sorted
            else{
                ans=min(ans,nums[mid]);
                end=mid-1;
            }
        }
        return ans;
    }
};