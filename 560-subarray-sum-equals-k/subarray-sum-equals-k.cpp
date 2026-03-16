class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        vector<int> ps(n,0);
        ps[0]=nums[0];
        for(int i=1;i<n;i++){
            ps[i]=ps[i-1]+nums[i];
        }

        unordered_map<int,int> mpp;
        for(int j=0;j<n;j++){
            if(ps[j]==k){
                cnt++;
            }
            int val=ps[j]-k;
            if(mpp.find(val)!=mpp.end()){
                cnt+=mpp[val];
            }

            if(mpp.find(ps[j])==mpp.end()){
                mpp[ps[j]]=0;
            }

            mpp[ps[j]]++;

        }

        return cnt;
        
    }
};