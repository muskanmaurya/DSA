class Solution {
public:

    int firstPos(vector<int>& nums, int t) {        
        int st=0;
        int end=nums.size()-1;
        int ans=-1;        
        while(st<=end){            
        int mid=st+(end-st)/2;            
        if(nums[mid]==t){ ans=mid; end=mid-1; }          
        else if(nums[mid]<t) st=mid+1;           
        else end=mid-1;
       }
        return ans;
    }

    int lastPos(vector<int>& nums, int t) {
        int st=0;
        int end=nums.size()-1;
        int ans=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==t){ ans=mid; st=mid+1; }
            else if(nums[mid]<t) st=mid+1;
            else end=mid-1;
        }
        return ans;   
        }

     vector<int> searchRange(vector<int>& nums, int t) {
        return { firstPos(nums, t), lastPos(nums, t) };
    }
};