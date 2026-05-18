#include<unordered_map>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0; //count
        vector<int> ps(n,0); //init prefixSum arr of n size with all elem as 0
        ps[0] = nums[0]; 
        for(int i = 1; i < n; i++){
            ps[i] = ps[i-1] + nums[i]; //prefixsum formula
        }
        unordered_map<int, int> m;
    m[0] = 1; //Base case: a prefix sum of 0 has occurred 1 time
    
    for (int j = 0; j < n; j++) {
        int val = ps[j] - k;
        // If (ps[j] - k) exists in map, add its frequency to our count
        if (m.find(val) != m.end()) {
            cnt += m[val];
        }
        // C++ stl automatically initializes new keys to 0, so we can just do this directly
        m[ps[j]]++;
    }  
    return cnt;  
    }    
};