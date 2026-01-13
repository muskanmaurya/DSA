class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el=0;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt++;
                el=nums[i];
            }
            else if(nums[i]==el){
                cnt++;
            }
            else cnt--;
        }
        int cnt1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el){cnt++;}
            if(cnt1>n/2){
                return el;
            }
        }
        return el;
    }
};