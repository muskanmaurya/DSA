class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cs;  //current sum
        int cnt=0;  //count
        for(int i=0;i<n;i++){
            cs=0;
            for(int j=i;j<n;j++){
                cs+=nums[j];  
                if(cs==k){  //if my cnt is equal to k increase the cnt
                    cnt++;
                }
            }
        } 
        return cnt; //value of cnt is the answer
    }
};