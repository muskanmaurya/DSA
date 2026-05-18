#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n=nums.size();
        //hashing approach
        unordered_map<int,int> m; // Stores: {Number, Index}
        for(int i=0;i<n;i++){
            int first = nums[i];
            int second = t - first; // This is the complement we need
            if(m.contains(second)){
                return {m[second], i}; // Directly get value using m[second] safely
            }
            m[first]=i; //inserting current number and its index in map
        }
    return {-1, -1};
    }
};