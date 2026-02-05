class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
       int f=-1;
       int end=-1;
       int n=nums.size();
       vector<int> ans; 
       for(int i=0;i<n;i++){
        if(nums[i]==t){
            if(f==-1){
                f=i;
                end=i;
            }else{
                end=i;
            }
        }
       }
        ans.push_back(f);
        ans.push_back(end);
        return ans;       
    }
};